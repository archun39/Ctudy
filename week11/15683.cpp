#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAP_MAX = 9;

struct T {
    int x, y;
    int type;
};

int N, M;
int map[MAP_MAX][MAP_MAX];
int isVisited[MAP_MAX][MAP_MAX];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int answer = 1e9;
vector<T> cctvs;

void input(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> map[i][j];
            if(map[i][j] != 0) isVisited[i][j] = -1;
            if(map[i][j] != 0 && map[i][j] != 6){
                T tmp;
                tmp.x = i;
                tmp.y = j;
                tmp.type = map[i][j];
                cctvs.push_back(tmp);
            }
        }
    }
}

bool isWall(int x, int y){
    if(map[x][y] == 6) return true;
    return false;
}

bool isOut(int x, int y){
    return x < 1 || y < 1 || x > N || y > M;
}

void process(T cctv, int dir, bool on){
    int nx = cctv.x;
    int ny = cctv.y;
    
    while(true){
        nx += dx[dir];
        ny += dy[dir];
        if(isWall(nx, ny) || isOut(nx,ny)) break;
        if(on) isVisited[nx][ny] += 1;
        else isVisited[nx][ny] -= 1;
    }
}

void type1(T cctv, int dir, bool on){
    process(cctv, dir, on);
}

void type2(T cctv, int dir, bool on){
    process(cctv, dir, on);
    process(cctv, (dir+2)%4, on);
}

void type3(T cctv, int dir, bool on){
    process(cctv, dir, on);
    process(cctv, (dir+1)%4, on);
}

void type4(T cctv, int dir, bool on){
    for(int i = 0; i < 3; i++){
        dir = (dir+i) % 4;
        process(cctv, dir, on);
    }
}

void type5(T cctv, int dir, bool on){
    for(int i = 0; i < 4; i++){
        dir = (dir+i) % 4;
        process(cctv, dir, on);
    }
}

void getType(T cctv, int i, bool on){
    switch (cctv.type)
        {
        case 1:
            type1(cctv, i, on);
            break;
        case 2:
            type2(cctv, i, on);
            break;
        case 3:
            type3(cctv, i, on);
            break;
        case 4:
            type4(cctv, i, on);
            break;
        case 5:
            type5(cctv, i, on);
            break;
        default:
            break;
        }
}

void print(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cout << isVisited[i][j] << " ";
        }
        cout << endl;
    }
}

int getSpace(){
    int res = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(isVisited[i][j] == 0 && map[i][j] == 0){
                res++;
            }
        }
    }

    return res;
}

void sol(int idx){
    if(idx == cctvs.size()){
        int res = getSpace();
        answer = min(answer, res);
        return;
    }
    T cctv = cctvs[idx];
    for(int i = 0; i < 4; i++){
        getType(cctv, i, true);
        sol(idx+1);
        getType(cctv, i, false);
    }
}

int main(){
    input();
    sol(0);
    cout << answer << endl;
    return 0;
}
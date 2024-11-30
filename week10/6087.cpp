#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct N{
    int x, y, dir, count;

    N(int x, int y, int dir, int count) : x(x), y(y), dir(dir), count(count) {}
};

const int MAX = 101;

int W, H;
char map[MAX][MAX];
int isVisited[MAX][MAX][4];
vector<N> pos;
//오, 아래, 왼, 위
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void input(){
    cin >> W >> H;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> map[i][j];
            for(int k = 0; k < 4; k++){
                isVisited[i][j][k] = 1e9;
            }
            if(map[i][j] == 'C'){
                pos.push_back(N(i,j,0,0));
            }
        }
    }
}

bool isOut(int x, int y){
    return x < 0 || y < 0 || x >= H || y >= W;
}

void sol(){
    queue<N> q;
    for(int i = 0; i < 4; i++){
        q.push(N(pos[0].x, pos[0].y, i, 0));
        isVisited[pos[0].x][pos[0].y][i] = 0;
    }
    
    
    while(!q.empty()){
        N cur = q.front();
        int x = cur.x;
        int y = cur.y;
        int dir = cur.dir;
        int count = cur.count;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nCount = count;

            if(isOut(nx,ny) || map[nx][ny] == '*') continue;
            if(dir != i) nCount++; //뒤돌아가는 것 판별
             
            if(nCount < isVisited[nx][ny][i]){
                isVisited[nx][ny][i] = nCount;
                if(map[nx][ny] != 'C') q.push(N(nx, ny, i, nCount));
            }
        }
    }

    int answer = 1e9;
    for(int i = 0; i < 4; i++){
        answer = min(answer, isVisited[pos[1].x][pos[1].y][i]);
    }
    cout << answer << endl;
}

int main(){
    input();
    sol();
    return 0;
}
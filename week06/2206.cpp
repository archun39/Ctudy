#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1001;

int N, M;
int map[MAX][MAX] = {0};
bool isVisited[MAX][MAX] = {0};
bool canBreak = true;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int answer = 1e9;
void process();

bool canMove(int r, int c){
    if(r < 1 || c < 1 || r > N || c > M) return false;
    return true;
}

bool isWall(int r, int c){
    return map[r][c];
}

void input(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            char c;
            cin >> c;
            map[i][j] = c - '0';
        }
    }
    return;
}

void process(int r, int c, int count);

void nextmove(int r, int c, int count){
    isVisited[r][c] = true;
    process(r, c, count);
    isVisited[r][c] = false;
}


void process(int r, int c, int count){
    if(r == N && c == M){
        answer = min(answer, count);
        return;
    }
    for(int i = 0; i < 4; i++){
        int nr = dx[i] + r;
        int nc = dy[i] + c;
        //can't go
        if(!canMove(nr,nc) || isVisited[nr][nc]) continue;

        //wall
        if(isWall(nr,nc)){
            if(canBreak){
                if(!isWall(nr+dx[i], nc+dy[i])){
                    canBreak = false;
                    nextmove(nr+dx[i], nc+dy[i], count+1);
                    canBreak = true;
                }
            }
            else continue;
        }
        else{
            nextmove(nr,nc,count+1);
        }
    }
    return;
}

void sol(){
    isVisited[1][1] = true;
    process(1,1,1);
    if(answer == 1e9) cout << -1 <<endl;
    else cout << answer + 1<< endl;
}


int main(){
    input();
    sol();
    return 0;
}                                      
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1001;
const int INF = -1e9;

int N, M;
int map[MAX][MAX];
int dx[3] = {0,0,1}; //좌 우 밑
int dy[3] = {-1,1,0};
bool isVisited[MAX][MAX];
int dp[MAX][MAX][3];

void input(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> map[i][j];
        }
    }
}

void init(){
    for(int i = 1; i < MAX; i++){
        for(int j = 1; j < MAX; j++){
            for(int k = 0; k < 3; k++){
                dp[i][j][k] = INF;
            }
        }
    }
}

int sol(int x, int y, int dir){
    if(x == N && y == M) return map[N][M];
    if(dp[x][y][dir] != INF) return dp[x][y][dir];

    isVisited[x][y] = true;
    
    int tmp = INF;
    for(int i = 0; i < 3; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > N || ny > M || isVisited[nx][ny]) continue;
        tmp = max(tmp, sol(nx, ny, i));
    }
    
    isVisited[x][y] = false;
    dp[x][y][dir] = map[x][y] + tmp;
    return dp[x][y][dir];
}

int main(){
    input();
    init();
    cout << sol(1,1,0);

    return 0;
}
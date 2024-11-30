#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 1001;
/*
불이 번지는 과정과 지훈이가 움직이는 과정을 나누어서 해결한다.
지훈이의 좌표를 queue로 설정한다.

단, 불이 먼저 번져야 지훈이가 움직였을 때 불에 죽지 않는다.

-- 불이 번지는 과정 --
    1. queue에 불의 위치를 담는다.
    2. 현재 발생한 불의 갯수를 기억한다.
    3. 불의 갯수만큼 4방향으로 퍼뜨린다.
    4. 새롭게 생긴 불을 queue에 담는다.
    5. 다 퍼진 불씨는 queue에서 제거한다.
    6. 2 ~ 5 반복

-- 지훈이가 움직이는 과정 --
    1. 현재 위치를 기준으로 queue에 담고 시작한다.
    2. 지훈이가 현재 움직일 수 있는 방향을 기억한다.
    3. 4방향을 기준으로 새롭게 움직일 수 있는 방향으로 이동한다.
    4. 새롭게 움직인 좌표를 queue에 담는다.
    5. 이동했던 좌표로 돌아오지 않게 queue에서 제거하고 isVisited를 이용해 기억한다.
    6. 2 ~ 5 반복
*/

int R, C;
char map[MAX][MAX];
queue<pair<int,int>> fires;
queue<pair<int,int>> jihun;
bool isVisited[MAX][MAX] = {0};
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int answer = 10e7;

void input(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
            if(map[i][j] == 'J'){
                jihun.push({i,j});
                isVisited[i][j] = true;
            }
            else if(map[i][j] == 'F'){
                fires.push({i,j});
            }
        }
    }
}

bool isWall(int r, int c){
    if(map[r][c] == '#') return true;
    return false;
}

bool isFire(int r, int c){
    if(map[r][c] == 'F') return true;
    return false;
}

bool isEXIT(int r, int c){
    if(r < 0 || c < 0 || r >= R || c >= C) return true;
    return false;
}

//불이 번지는 과정
void fire_spreadings(int r, int c){
    for(int i = 0; i < 4; i++){
        int nr = r + dx[i];
        int nc = c + dy[i];

        //불이 번질 수 없는 위치
        if(isWall(nr,nc) || isEXIT(nr,nc) || isFire(nr,nc)) continue;
        else if(map[nr][nc] == '.') {
            map[nr][nc] = 'F';
            fires.push({nr,nc});
        }
    }   
}

void fire_Turn(){
    //queue에 담긴 불씨의 갯수를 기억한다.
    //이를 통해 이번 턴에 담긴 불씨와 겹치지 않게 한다.
    //즉, 한턴에 번질 수 있는 불씨만 계산.
    int firesize = fires.size();
    for(int i = 0; i < firesize; i++){
        auto fire = fires.front();
        fires.pop();
        int x = fire.first;
        int y = fire.second;
        fire_spreadings(x,y);
    }
}

void jihun_Turn(int r, int c, int time){
    for(int i = 0; i < 4; i++){
        int nx = r + dx[i];
        int ny = c + dy[i];
        //지훈이가 탈출을 할 수 있는 위치에 도달하면
        //기존 answer와 비교하여 최소값을 찾는다.
        if(isEXIT(nx,ny)) answer = min(answer, time);
        
        //갈 수 없는 위치
        else if(isWall(nx,ny) || isFire(nx,ny) || isVisited[nx][ny]) continue;
        else{
            jihun.push({nx,ny});
            isVisited[nx][ny] = true;;
        }
    }
}

void sol(){ 
    int time = 0;
    int move_size = 0; //지훈이가 해당 1분에 움직일 수 있는 모든 경우의 수

    //지훈이가 더 이상 움직일 수 없으면 종료
    while(!jihun.empty()){
        //1분마다 새로운 맵 생성
        if(move_size == 0){
            move_size = jihun.size();
            //지훈이의 움직임과 불의 번짐을 동시에 실행시키면,
            //지훈이가 한방향 움직일 때마다, 불이 번지므로 
            //불이 모두 번진 상태에서 지훈이가 움직일 수 있도록 한다. 
            fire_Turn();
            time++;
        }

        //지훈이의 움직임 - bfs
        auto next_move = jihun.front();
        jihun.pop();
        move_size -= 1;
        jihun_Turn(next_move.first, next_move.second, time);
    }

    //결과 출력
    if(answer == 10e7) cout << "IMPOSSIBLE" << endl;
    else cout << answer << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    input();
    sol();

    return 0;
}
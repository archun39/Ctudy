#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 201;

int R, C, N;
int map[MAX][MAX];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void input(){
    cin >> R >> C >> N;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            char c;
            cin >> c;
            if(c == 'O') {
                map[i][j] = 1;
            }
        }
    }
}

void plant_bombs(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(map[i][j] == 0) map[i][j] = 1;
        }
    }
}

void print(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(map[i][j] == 0) cout << '.';
            else cout << 'O';
        }
        cout << endl;
    }
}

void explosion(){
    queue<pair<int,int>> bombs;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(map[i][j] != 0) map[i][j] += 1;
            if(map[i][j] == 3) bombs.push(make_pair(i,j));
        }
    }

    while(!bombs.empty()){
        auto pos = bombs.front();
        bombs.pop();
        map[pos.first][pos.second] = -1;

        for(int i = 0; i < 4; i++){
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            map[nx][ny] = -1;
        }
    }
}

void sol(){
    int time = 0;
    while(time < N){
        time++;
        explosion();
        if(time % 2 == 0) plant_bombs();
        //cout << time << endl;
        //print();
    }
}

int main(){
    input();
    sol();
    print();
    return 0;
}
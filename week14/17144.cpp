#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct D{
    int r,c,v;

    D(int r, int c, int v) : r(r), c(c), v(v) {};
};

queue<D> dust;

const int MAX = 1001;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int machine;

int R, C, T;
int map[MAX][MAX] = {0};

void input(){
    cin >> R >> C >> T;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
            if(map[i][j] == -1) machine = i; //i-1, i
            else if(map[i][j] != 0) dust.push(D(i,j,map[i][j]));
        }
    }
}

bool isOut(int r, int c){
    if(r < 0 || c < 0 || r >= R || c >= C) return true;
    return false;
}

void print(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void spreadAir(){
    int map2[MAX][MAX] = {0};

    while(!dust.empty()){
        D tmp = dust.front();
        dust.pop();
        int count = 0;
        for(int i = 0; i < 4; i++){
            int nr = tmp.r + dx[i];
            int nc = tmp.c + dy[i];
            //isOut
            if(isOut(nr, nc)) continue;
            if(map[nr][nc] != -1){
                count++;
                map2[nr][nc] += map[tmp.r][tmp.c]/5;
            }
        }
        map[tmp.r][tmp.c] = map[tmp.r][tmp.c] - map[tmp.r][tmp.c]/5 * count;
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            map[i][j] += map2[i][j];
        }
    }
}

void roundAir(){
    //top
    int before = 0;
    int now = 0;
    int top = machine-1;
    for(int c = 1; c < C; c++){
        now = map[top][c];
        map[top][c] = before;
        before = now;
    }
    for(int r = top-1; r >= 0; r--){
        now = map[r][C-1];
        map[r][C-1] = before;
        before = now;
    }
    for(int c = C-2; c >= 0; c--){
        now = map[0][c];
        map[0][c] = before;
        before = now;
    }
    for(int r = 1; r < top; r++){
        now = map[r][0];
        map[r][0] = before;
        before = now;
    }

    //bottom
    before = 0;
    now = 0;
    int bot = machine;
    for(int c = 1; c < C; c++){
        now = map[bot][c];
        map[bot][c] = before;
        before = now;
    }
    for(int r = bot+1; r < R; r++){
        now = map[r][C-1];
        map[r][C-1] = before;
        before = now;
    }
    for(int c = C-2; c >= 0; c--){
        now = map[R-1][c];
        map[R-1][c] = before;
        before = now;
    }
    for(int r = R-2; r > bot; r--){
        now = map[r][0];
        map[r][0] = before;
        before = now;
    }
}

void findAir(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(map[i][j] > 0) dust.push(D(i,j,map[i][j]));
        }
    }
}

void sol(){
    while(T--){
        spreadAir();
        roundAir();
        findAir();
    }
}

int answer(){
    int ans = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(map[i][j] > 0) ans += map[i][j];
        }
    }

    return ans;
}

int main(){
    input();
    sol();
    cout << answer();
    return 0;
}
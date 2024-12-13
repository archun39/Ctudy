#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX = 1501;

struct T {
    int x, y;

    T(int x, int y): x(x), y(y) {};

    bool operator < (const T &var) const {
        if(x == var.x) return y < var.y;
        return x < var.x;
    }    
};

int R, C;
char lake[MAX][MAX];
int area[MAX][MAX];
set<T> melt;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
vector<T> birds;
vector<int> u;

int find(int a){
    if(u[a] != a) u[a] = find(u[a]);
    return u[a];
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a < b) u[b] = a;
    else if(b < a) u[a] = b;
}

void input(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> lake[i][j];
            if(lake[i][j] == 'L') birds.push_back(T(i,j));
        }
    }
}

bool isOut(int x, int y){
    return x < 0 || y < 0 || x >= R || y >= C;
}

void find_area(int x, int y, int num){
    if(area[x][y] == num) return;
    area[x][y] = num;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isOut(nx, ny)) continue;
        if(lake[nx][ny] == '.'){
            find_area(nx, ny, num);
        }
        else if(lake[nx][ny] == 'L'){
            area[nx][ny] = num;
        }
    }
}

void find_melt(){
    int area_num = 1;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(lake[i][j] == '.' || lake[i][j] == 'L'){
                if(area[i][j] == 0) find_area(i,j,area_num++);
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(isOut(nx,ny)) continue;
                    if(lake[nx][ny] == 'X'){
                        area[nx][ny] = area[i][j];
                        melt.insert(T(nx, ny));
                    }
                }           
            }
        }
    }

    u = vector<int>(area_num+1);
    for(int i = 0; i < u.size(); i++){
        u[i] = i;
    }
}


bool isConnect(){
    int first = find(area[birds[0].x][birds[0].y]);
    int second = find(area[birds[1].x][birds[1].y]);
    return first == second;
}

void print(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(lake[i][j] == '.'){
                cout << u[area[i][j]];
            }
            else cout << lake[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void melting(){
    set<T> tmp;
    for(auto m : melt){
        lake[m.x][m.y] = '.';
        for(int i = 0; i < 4; i++){
            int nx = m.x + dx[i];
            int ny = m.y + dy[i];
            if(isOut(nx, ny)) continue;
            if(lake[nx][ny] == 'X' && area[nx][ny] == 0){
                area[nx][ny] = area[m.x][m.y];
                tmp.insert(T(nx, ny));
            }
            else if(lake[nx][ny] == '.' || lake[nx][ny] == 'L' && find(area[nx][ny]) != find(area[m.x][m.y])){
                merge(area[nx][ny],area[m.x][m.y]);
            }
        }
    }
    melt.clear();
    melt = tmp;
}



void sol(){
    int days = 0;
    find_melt();
    
    while(!isConnect()){
        days+=1;
        melting();
    }
    cout << days << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    sol();
    return 0;
}
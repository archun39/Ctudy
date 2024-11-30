#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 101;

struct T{
    int x1, y1, x2, y2;
};
int N, M, K;
vector<T> v;
int map[MAX][MAX] = {};
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool isVisited[MAX][MAX] = {false};
vector<int> answer;
int area = 0;


void input(){
    cin >> M >> N >> K;
    for(int i = 0; i < K; i++){
        T tmp;
        cin >> tmp.x1 >> tmp.y1 >> tmp.x2 >> tmp.y2;
        v.push_back(tmp);
    }
}

void fillMap(T tmp){
    for(int r = tmp.x1; r < tmp.x2; r++){
        for(int c = tmp.y1; c < tmp.y2; c++){
            map[r][c]++;
        }
    }
}

void findArea(int r, int c){
    isVisited[r][c] = true;
    area++;
    for(int i = 0; i < 4; i++){
        int nx = r + dx[i];
        int ny = c + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if(map[nx][ny] == 0 && !isVisited[nx][ny]){
            findArea(nx,ny);
        }
    }
}

void print(){
    for(int j = 0; j < M; j++){
        for(int i = 0; i < N; i++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void sol(){
    for(int i = 0; i < K; i++){
        fillMap(v[i]);
    }
    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!isVisited[i][j] && map[i][j] == 0)
            {
                area = 0;
                findArea(i,j);
                answer.push_back(area);
                count++;
            }
        }
    }
    cout << count << endl;
    sort(answer.begin(), answer.end());
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
}

int main(){
    input();
    sol();
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

struct T {
    int x, y;

    T(int x, int y): x(x), y(y) {};
};

const int MAX = 21;

int N, M, X, Y, K;
int map[MAX][MAX];
vector<T> v;

void input(){
    cin >> N >> M >> X >> Y >> K;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j){
            cin >> map[i][j];
        }
    }
}

int main(){
    input();

    return 0;
}
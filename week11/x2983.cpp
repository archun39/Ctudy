#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int MAX = 1e9;

struct pos {
    int x, y;
    
    pos(int x, int y): x(x), y(y) {};
};

int N, K;
vector<char> v;
int dx[4] = {1,1,-1,-1}; //A B C D
int dy[4] = {1,-1,1,-1};
vector<pos> plant;
pos frog;

void input(){
    cin >> N >> K;
    v = vector<char>(K);
    for(int i = 0; i < K; i++){
        cin >> v[i];
    }

    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        if(i==0) frog = pos(x,y);
        plant.push_back(pos(x, y));
    }
}

int main(){
    input();

    return 0;
}
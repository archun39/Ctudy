#include <iostream>
#include <vector>
using namespace std;

int N,M,L,K;
vector<pair<int,int>> v;

void input(){
    cin >> N >> M >> L >> K;
    for(int i = 0; i < K; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x,y});
    }
}

void process(int r, int c){
    for(int i = 0; i < K; i++){
        auto tmp = v[i];
        int x = tmp.first;
        int y = tmp.second;
        if(r <= x && x <= r+L && c <= y && y <= c+L){
            
        }
    }
    
}

void sol(){
    
}

int main(){
    input();
    sol();
    return 0;
}
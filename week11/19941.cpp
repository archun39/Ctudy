#include <iostream>
#include <vector>

using namespace std;

const int MAX = 20001;

int N, K;
vector<char> v;


void input(){
    cin >> N >> K;
    v = vector<char>(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
}

void print(){
    for(int i = 0; i < N; i++){
        cout << v[i];
    }
}

void sol(){
    int answer = 0;
    for(int i = 0; i < N; i++){
        if(v[i] != 'P') continue;
        for(int p = i-K; p <= i+K; p++){
            if(p < 0 || p >= N) continue;
            if(v[p] == 'H'){
                v[p] = '.';
                answer++;
                break;
            }
        }
    }
    cout << answer << endl;
}

int main(){
    input();
    sol();
    return 0;
}
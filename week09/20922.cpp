#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;
vector<int> v;
vector<int> isVisited(100001);

void input(){
    cin >> N >> K;
    v = vector<int> (N);
    
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
}

void sol(){
    int start = 0, end = 0;
    int answer = 0;
    //슬라이딩 윈도우
    for(start = 0; start < N; start++){
        //갈 수 있는 최대 배열
        while(end < N && isVisited[v[end]] < K){
            isVisited[v[end++]]++;
        }
        answer = max(answer, end - start);
        isVisited[v[start]]--;
    }
    cout << answer ;
}

int main(){
    input();
    sol();
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2001;

int N, M;
vector<int> graph[MAX];
bool isVisited[MAX] = {false};
bool answer = false;

void input(){
    cin >>  N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void process(int node, int count){
    if(count == 4){
        answer = true;
        return;
    }
    isVisited[node] = true;
    for(int i = 0; i < graph[node].size(); i++){
        int next = graph[node][i];
        if(!isVisited[next] && !answer){
            process(next, count+1);
        }
    }
    isVisited[node] = false;
}

void sol(){
    for(int i = 0; i < N; i++){
        process(i, 0);
        if(answer){
            cout << answer << endl;
            return;
        }
    }
    cout << answer << endl;
}

int main(){
    input();
    sol();

    return 0;
}
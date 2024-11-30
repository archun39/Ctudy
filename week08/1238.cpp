#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define INF 98765432
using namespace std;

const int MAX = 1001;

int N, M, X;
vector<pair<int,int>> v[MAX];
int dist[MAX];

void input(){
    cin >> N >> M >> X;

    for(int i = 0; i < M; i++){
        int start, end, time;
        cin >> start >> end >> time;
        v[start].push_back(make_pair(end, time));
    }
}

void init(){
    memset(dist, INF, sizeof(dist));
}

int process(int start, int end){

    int result = 0;

    init();
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while(!pq.empty()){
        int current = pq.top().second;
        int distance = pq.top().first;
        
        pq.pop();
        if(current == end){
            result = dist[end];
            break;
        }

        for(int i = 0; i < v[current].size(); i++){
            int next = v[current][i].first;
            int next_distance = v[current][i].second + distance;

            if(dist[next] > next_distance){
                dist[next] = next_distance;
                pq.push(make_pair(next_distance, next));
            }
        }
    }

    return result;
}

void sol(){
    int answer = 0;
    
    for(int i = 1; i <= N; i++){
        init();
        int res = process(i, X) + process(X, i);
        
        if(answer < res){
            answer = res;
        }
    }
    cout << answer << endl;
}

int main(){

    input();
    sol();

    return 0;
}
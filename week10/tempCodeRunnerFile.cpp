#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> ii;

const int MAX = 100001;

int N, K;
int isVisited[MAX];

void input(){
    cin >> N >> K;
    for(int i = 0; i < MAX; i++){
        isVisited[i] = 1e9;
    }
}

bool process(int time, int next){
    if(time < isVisited[next]){
        isVisited[next] = time;
        if(next != K) return true;
    }
    return false;
}

void sol(){
    int answer = 0;
    priority_queue<ii,vector<ii>, greater<ii>> pq;
    ii init; //{cnt, pos}
    init.first = 0;
    init.second = N;
    isVisited[N] = 0;

    pq.push(init);

    while(!pq.empty()){
        ii cur = pq.top();
        pq.pop();
        int pos = cur.second;
        int cnt = cur.first;
        
        //walking
        if(pos+1 <= MAX && process(cnt+1, pos+1)) pq.push(make_pair(cnt+1, pos+1));
        if(0 <= pos-1 && process(cnt+1, pos-1)) pq.push(make_pair(cnt+1, pos-1));
        if(pos*2 <= K && pos*2 <= MAX && process(cnt+1, pos*2)) pq.push(make_pair(cnt+1, pos*2));
    }
    cout << isVisited[K] << endl;
}

int main(){
    input();
    sol();

    return 0;
}
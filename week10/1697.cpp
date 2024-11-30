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
        isVisited[i] = MAX;
    }
}

bool process(int time, int next){
    if(time < isVisited[next]){
        isVisited[next] = time; 
        return true;
    }
    return false;
}

void sol(){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(make_pair(0, N)); //{cnt, pos}
    isVisited[N] = 0;

    while(!pq.empty()){
        ii cur = pq.top();
        pq.pop();
        int pos = cur.second;
        int cnt = cur.first;
        
        // move_forward
        if(pos+1 < MAX && process(cnt+1, pos+1)){
            pq.push(make_pair(cnt+1, pos+1));
        } 
        // move_behind
        if(pos-1 >= 0 && process(cnt+1, pos-1)){
            pq.push(make_pair(cnt+1, pos-1));
        } 
        // teleport
        if(pos*2 < MAX && process(cnt+1, pos*2)) { 
            pq.push(make_pair(cnt+1, pos*2));
        }
    }
    cout << isVisited[K] << endl;
}

int main(){
    input();
    sol();

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

const int MAX = 100001;

int N, S, D;
int ans = 0;

map<int, set<int>> m;
int depth[MAX];

void input(){
    cin >> N >> S >> D;
    for(int i = 0; i < N-1; i++){
        int a,b;
        cin >> a >> b;

        m[a].insert(b);
        m[b].insert(a);
    }
}

//전단지 배부
int process(int x, int before){
    for(auto next : m[x]){
        if(next == before) continue;
        depth[x] = max(depth[x], process(next, x)+1);
    }

    if(depth[x] >= D && x != S) ans++;
    return depth[x];
}

void sol(int x){    
    process(x, -1);
    cout << ans * 2 << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    input();
    sol(S);

    return 0;
}
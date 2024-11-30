#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int n,k;

void input(){
    cin >> n >> k;
}

void print(vector<int> v){
    cout << "<";
    for(int i = 0; i < v.size()-1; i++){
        cout << v[i] << ", ";
    }
    cout << v[v.size()-1] << ">";
}

void sol(){
    queue<int> q;
    vector<int> v;
    //init
    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    int count = 0;
    //k번째 올때 마다 pop할 예정
    //시간제한이 2초이므로 구현형식으로 해결하면 됨
    while(!q.empty()){
        count++;
        int tmp = q.front();
        q.pop();
        if(count != k){
            q.push(tmp);
        }
        else{
            v.push_back(tmp);
            count = 0;
        }
    }

    print(v);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    input();
    sol();
    return 0;
}
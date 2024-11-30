#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;
vector<int> v;
queue<int> nums[100001];

void input(){
    cin >> N >> K;
    v = vector<int> (N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
}

void sol(){
    int p = 0;
    int answer = 0;
    for(int i = 0; i < N; i++){
        int a = v[i];

        if(nums[a].size() < K){
            nums[a].push(i);
        }
        else{
            p = nums[a].front()+1;
            nums[a].pop();
        }
        answer = max(answer, i-p);
    }
    cout << answer+1 << endl;
}

int main(){
    input();
    sol();
    return 0;
}
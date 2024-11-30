#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1001;

int N;
vector<int> v;
int dp[MAX];
vector<int> LIS[MAX];
vector<int> answer;

void input(){
    cin >> N;
    v = vector<int> (N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
}

void sol(){
    for(int i = 0; i < N; i++){
        dp[i] = 1;
        LIS[i].push_back(v[i]);
        for(int j = 0; j < i; j++){
            if(v[i] > v[j]){
                if(dp[i] < dp[j] + 1){
                    LIS[i].clear();
                    LIS[i] = LIS[j];
                    LIS[i].push_back(v[i]);
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if(answer.size() < LIS[i].size()){
            answer = LIS[i];
        }
    }
}

int main(){
    input();
    sol();
    cout << answer.size() << endl;
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    return 0;
}
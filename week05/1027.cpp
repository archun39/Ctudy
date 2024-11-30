#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
typedef long double ld;
using namespace std;

int N;
vector<ll> buildings;
vector<int> check;

void input(){
    cin >> N;
    check = vector<int>(N,0);
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        buildings.push_back(tmp);
    }
}

ld get_incline(int target_idx, int current_idx){
    ld x = current_idx - target_idx;
    ld y = buildings[current_idx] - buildings[target_idx];

    return y / x;
}

void process(int target_idx){
    check[target_idx] += 1;
    check[target_idx+1] += 1;
    ld incline = get_incline(target_idx, target_idx+1);
    for(int i = target_idx+2; i < N; i++){
        ld tmp = get_incline(target_idx, i);
        if(tmp > incline){
            incline = tmp;
            check[target_idx] += 1;
            check[i] += 1;
        }
    }
}ㄱㄹ                       

void sol(){
    for(int i = 0; i < N-1; i++){
        process(i);
    }

    int answer = 0;
    for(int i = 0; i < N; i++){
        answer = max(answer, check[i]);
    }
    
    cout << answer;
}

int main(){
    input();
    sol();
    return 0;
}

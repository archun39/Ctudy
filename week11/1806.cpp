#include <iostream>
#include <vector>
using namespace std;

int N;
long long S;
vector<int> v;

void input(){
    cin >> N >> S;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
}

void sol(){
    if(v[0] == S){
        cout << 1 << endl;
        return ;
    }

    int left, right;
    left = 0;
    right = 1;

    long long sum = v[0] + v[1];
    int answer = N+1;
    
    while(left <= right && right < N){
        if(sum >= S){
            answer = min(answer, right-left+1);
            sum -= v[left];
            left++;
        }
        else {
            right++;
            sum += v[right];
        }
    }
    if(answer == N+1) cout << 0 << endl;
    else cout << answer << endl;
}

int main(){
    input();
    sol();

    return 0;
}
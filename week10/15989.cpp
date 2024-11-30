#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10001;

int process(int n){
    int answer = 0;

    for(int i = 0; i <= (n/3); i++){
        int tmp = n - (3*i);
        answer += tmp/2+1;
    }

    return answer;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << process(n) << endl;
    }

    return 0;
}
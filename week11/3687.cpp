#include <iostream>
#include <vector>
#include <string>
using namespace std;
// 0 : 6개
// 1 : 2개
// 3 : 5개
// 4 : 4개
// 5 : 5개
// 6 : 6개
// 7 : 3개
// 8 : 7개
// 9 : 6개

const int MAX = 101;
int small_num[9] = {0,0,1,7,4,2,0,8,10};
long long small[MAX];

void make_small_num(){
    for(int i = 1; i < 9; i++){
        small[i] = small_num[i];
    }

    small[6] = 6;

    for(int i = 9; i < MAX; i++){
        small[i] = small[i-2]*10 + small_num[2];
        for(int n = 3; n <= 7; n++){
            small[i] = min(small[i], small[i-n] * 10 + small_num[n]);
        }
    }
}

int main(){
    int t;
    cin >> t;
    make_small_num();
    while(t--){
        int n;
        cin >> n;
        string big;
        if(n%2 == 0){
            big = "1";
            for(int i = 1; i < n/2; i++){
                big = big + "1";
            }
        }
        else{
            big = "7";
            for(int i = 1; i < n/2; i++){
                big = big + "1";
            }
        }
        cout << small[n] << " "<< big << endl;
    }
    return 0;
}
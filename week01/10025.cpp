#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

const int MAX = 1000001;
int n, k;
int arr[MAX];

void input(){
    cin >> n >> k;

    //얼음 양동이를 놓을 자리 초기화
    memset(arr, 0, sizeof(arr));
    
    for(int i = 0; i < n; i++){
        int g, x;
        cin >> g >> x;
        arr[x] = g;
    }
}

/***
곰이 잡을 수 있는 양동이의 범위는 자신위치를 포함한 양 옆 k이므로,
총 2k+1 만큼 잡을 수 있다.
따라서 2k+1 만큼의 값을 비교하여 최대값을 구한다. >>> '윈도우 슬라이싱'
최초 값에서 앞값을 빼고 다음 값을 더하는 방식으로 구한다. 
***/

void sol(){
    //윈도우 슬라이싱 범위 설정
    int size = 0;
    if(2*k + 1 > 1000000){
        size = 1000000;
    }
    else size = 2*k + 1;

    //초기값은 처음부터 size까지
    long long value = 0;
    for(int i = 0; i < size; i++){
        value += arr[i];
    }
    long long maxAnswer = value;

    //이후 초기값부터 첫값은 빼고 다음 값을 더하는 방식으로 진행
    for(int i = 0; i+size < MAX; i++){
        value = value - arr[i] + arr[i + size];
        maxAnswer = max(maxAnswer, value);
    }

    cout << maxAnswer << endl;
}

int main(){
    input();
    sol();
    return 0;
}
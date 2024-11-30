#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#define endl '\n'
using namespace std;

const int MAX = 101;

int n;
int arr[MAX];
bool isLoop[MAX];
bool isVisited[MAX];

/*
뽑힌 정수들이 이루는 집합과 뽑힌 정수들의 바로 밑의 둘째 줄에 들어있는 정수들이 이루는 집합이 일치하려면

idx와 arr[idx] 값들의 집합이 일치해야한다.
즉, idx로 시작해서 arr[idx2] == idx로 도착하는 loop를 찾아야한다.
 

*/

void init(){
    memset(isLoop, 0, sizeof(isLoop));
    memset(arr, 0, sizeof(arr));
    memset(isVisited, 0, sizeof(isVisited));
}

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
}

void findLoop(int idx, int target){
    if(isLoop[idx]) return;
    if(isVisited[idx]){
        //is Loop!
        if(idx == target){
            for(int i = 0; i < MAX; i++){
                if(isVisited[i]){
                    isLoop[i] = true;
                }
            }
        }
        return;
    }
    else{
        isVisited[idx] = true;
        int nextIdx = arr[idx];
        findLoop(nextIdx, target);
    }

}

void sol(){
    for(int i = 1; i <= n; i++){
        memset(isVisited, 0, sizeof(isVisited));
        findLoop(i,i);
    }
    
    vector<int> v;
    int answer = 0;
    for(int i = 1; i <= n; i++){
        if(isLoop[i]) v.push_back(i);
    }

    cout << v.size() << endl;
    for(int x : v){
        cout << x << endl;
    }
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init();
    input();
    sol();

    return 0;
}
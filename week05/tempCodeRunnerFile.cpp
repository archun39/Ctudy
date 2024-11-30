#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> children;
vector<int> LIS;

void input(){
    cin >> N;
    children = vector<int> (N);
    LIS = vector<int> (N,1);
    for(int i = 0; i < N; i++){
        cin >> children[i];
    }
}

int binarysearch(int left, int right, int target){
    int mid;

    while(left < right){
        mid = (left + right) / 2;
        if(children[mid] < target) left = mid + 1;
        else right = mid;
    }
    return right;
}

void sol(){
    LIS[0] = children[0];
    int j = 0, i = 1;

    while(i < N){
        if(LIS[j] < children[i]){
            LIS[j+1] = children[i];
            j += 1;
        }
        else{
            int idx = binarysearch(0, j, children[i]);
            LIS[idx] = children[i];
        }
        i++;
    }

    cout << N - (j+1);
}

int main(){
    input();
    sol();
    return 0;
}
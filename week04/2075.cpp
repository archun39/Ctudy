#include <iostream>
#include <set>
#include <algorithm>
#define endl '\n'
using namespace std;

const int MAX = 1501*1501;

int arr[MAX];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n*n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+ n*n);
    cout << arr[n*n-n] << endl;
    return 0;
}
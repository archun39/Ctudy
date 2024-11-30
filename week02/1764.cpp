#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define endl '\n'
using namespace std;

bool cmp (string A, string B){
    return A < B;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    set<string> s;
    vector<string> list;

    for(int i = 0; i < n; i++){
        string x;
        cin >> x;
        s.insert(x);
    }

    for(int i = 0; i < m; i++){
        string x;
        cin >> x;

        if(s.find(x) != s.end()){
            list.push_back(x);
        }
    }

    sort(list.begin(), list.end(), cmp);
    cout << list.size() << endl;
    for(auto s : list){
        cout << s << endl;
    }

    return 0;
}
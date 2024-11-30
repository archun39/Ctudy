#include <iostream>
#include <string>
#include <vector>
#include <map>
#define endl '\n'
using namespace std;

map<string, int> m;

void insert(string x){
    auto iter = m.find(x);
    if(iter == m.end()){
        m.insert({x, 1});
    }
    else{
        m[x] += 1;
    }
}

void print(int countTotal){
    for(auto iter = m.begin(); iter != m.end(); iter++){
        cout << iter->first << " ";
        cout << fixed;
        cout.precision(4);
        cout << (iter->second) / (double)countTotal * 100 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string x;
    int countTotal = 0;
    while(getline(cin,x)){
        if(x=="end") break;
        countTotal++;
        insert(x); 
    }

    print(countTotal);

    return 0;
}


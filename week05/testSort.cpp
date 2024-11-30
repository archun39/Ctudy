#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct T{
    int a,b,c;
};

bool cmp(T a, T b){
    if(a.b==b.b) return a.c > b.c;
    return a.b < b.b;
}

int main(){
    vector<T> v;
    for(int i = 0; i < 5; i++){
        T tmp;
        cin >> tmp.a >> tmp.b >> tmp.c;
        v.push_back(tmp);
    }


    sort(v.begin(), v.end(), cmp);
    
    for(int i = 0; i < 5; i++){
        cout << v[i].a << v[i].b << v[i].c << endl;
    }

    return 0;
}
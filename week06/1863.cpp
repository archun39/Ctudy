#include <iostream>
#include <vector>
using namespace std;

struct T{
    int x, y;
};

int n;
vector<T> v;
vector<int> stack;
int answer = 0;

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        T tmp;
        cin >> tmp.x >> tmp.y;
        v.push_back(tmp);
    }
}

void process(int building, int back){
    if(back < building && building != 0){
        stack.push_back(building);
    }
    else if(back == building){
        return;
    }
    else{
        stack.pop_back();
        answer++;
        process(building, stack.back());
    }
}

void sol(){
    stack.push_back(0);
    for(int i = 0; i < n; i++){
        int building = v[i].y;
        if(stack.empty()){
            stack.push_back(building);
            continue;
        }
        int back = stack.back();
        process(building, back);
    }

    cout << answer + stack.size()-1<< endl;
  
}

int main(){
    input();
    sol();
    return 0;
}
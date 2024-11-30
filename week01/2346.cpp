#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
using namespace std;

int n;
vector<int> answer;
deque<pair<int,int>> dq;

void input(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        dq.push_back(make_pair(tmp, i+1));
    }
}

int isPlus(int nextNumber){
    for(int i = 0; i < abs(nextNumber)-1; i++){
        pair<int,int> tmp = dq.front();
        dq.push_back(tmp);
        dq.pop_front();
    }
    pair<int,int> target = dq.front();
    answer.push_back(target.second);
    dq.pop_front();

    return target.first;
}

int isMinus(int nextNumber){
    for(int i = 0; i < abs(nextNumber); i++){
        pair<int,int> tmp = dq.back();
        dq.push_front(tmp);
        dq.pop_back();
    }
    pair<int,int> target = dq.front();
    answer.push_back(target.second);
    dq.pop_front();

    return target.first;
}

void print(){
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
}

void sol(){
    //첫번째는 무조건 맨 앞을 터뜨린다.
    int nextNumber = 1;
    
    while(!dq.empty()){
       if (nextNumber > 0) nextNumber = isPlus(nextNumber);
       else nextNumber = isMinus(nextNumber);
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    sol();
    print();
    return 0;
}
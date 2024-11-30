#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int N;

vector<string> list;
vector<string> constList;
map<string, int> getIdx;
int maxlen = 0;

void input(){
    cin >> N;
    list = vector<string> (N);
    for(int i = 0; i < N; i++){
        cin >> list[i];
        constList.push_back(list[i]);
        getIdx.insert({list[i], i});
    }
}

int process(string A, string B){
    int len = min(A.length(),B.length());
    int count = 0;
    for(int i = 0; i < len; i++){
        if(A[i] == B[i]) count++;
        else break;
    }
    return count;
}


void sol(){
    sort(list.begin(), list.end());
    map<int,set<int>> answer;
    int maxlen = 0;
    int key = 0;
    //정렬해서 옆에 문자와 비교하면 된다.
    for(int i = 0; i < N-1; i++){
        int count = process(list[i], list[i+1]);
        //같은 접두사를 저장하기 위함
        if(maxlen < count){
            key++;
            maxlen = count;
            answer = map<int,set<int>>();
            answer[key].insert(getIdx[list[i]]);
            answer[key].insert(getIdx[list[i+1]]);
        }
        else if(maxlen == count){
            answer[key].insert(getIdx[list[i]]);
            answer[key].insert(getIdx[list[i+1]]);
        }
        else{
            key++;
        }
    }
    int ansKey = 0;
    int ansIdx = 1e9;
    //같은 길이의 접두사 중에서 가장 먼저 들어온 문자를 찾기 위함
    for(auto tmp : answer){
        for(auto idx : tmp.second){
            if(idx < ansIdx){
                ansIdx = idx;
                ansKey = tmp.first;   
            }
            break;
        }
    }
    int flag = 2;
    //출력
    for(auto idx : answer[ansKey]){
        if(flag == 0) break;
        
        cout << constList[idx] << endl;
        flag--;
    }
}

int main(){
    input();
    sol();
    return 0;
}
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
using namespace std;
map<string, set<string>> m;
vector<string> tmp;
vector<vector<string>> ans;

void process(string s){
    //s출발 티켓이 더이상 없는 경우
    if(m.find(s) == m.end()){
        cout << m.size() << endl;
        return;    
    }
    if(m.empty()) return;
    cout << s << endl;
    
    for(auto x : m[s]){   
        tmp.push_back(x);
        m[s].erase(x);
        if(m[s].empty()) m.erase(s);
        process(x);
        tmp.pop_back();
        m[s].insert(x); 
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer; 
    for(int i = 0; i < tickets.size(); i++){
        m[tickets[i][0]].insert(tickets[i][1]);
    }

    
    process("ICN");
    
    return answer;
}

int main(){

    vector<string> answer = solution(tickets);

    return 0;
}
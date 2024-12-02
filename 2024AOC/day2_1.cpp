#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int INPUT_MAX = 1000;
const int DIFF_LEVEL = 3;

bool sol(vector<int> v){
    bool increase = true;
    for(int i = 0; i < v.size()-1; i++){
        if(abs(v[i] - v[i+1]) > DIFF_LEVEL) return false;
        if(v[i] == v[i+1]) return false;
        
        if(i == 0){
            increase = v[i] < v[i+1];
        }
        else{
            if(increase){
                if(v[i] >= v[i+1]) return false;
            }
            else{
                if(v[i] <= v[i+1]) return false;
            }
        }
    }
    
    return true;
}

int main(){
    vector<int> levels;
    string str;

    int answer = 0;
    
    for(int i = 0; i < INPUT_MAX; i++){
        getline(cin, str);
        levels.clear();

        string tmp = "";
        for(int i = 0; i < str.length(); i++){
            char c = str[i];
            if(c == ' '){
                levels.push_back(stoi(tmp));
                tmp = "";
            }
            else{
                tmp += c;
            }
        }
        levels.push_back(stoi(tmp));

        bool res = sol(levels);
        if(res){
            answer++;
        } 
        
    }

    cout << answer << endl;

    return 0;
}


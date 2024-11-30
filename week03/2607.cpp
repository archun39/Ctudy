#include <iostream>
#include <vector>
#include <map>
#include <string>
#define endl '\n'
using namespace std;

int n;
vector<string> v;
int answer = 0;

void input(){
    cin >> n;
    v = vector<string> (n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
}

/*
비슷한 단어인 경우
1. 한 문자를 더하거나
2. 한 문자를 빼거나
3. 하나의 문자를 다른 문자로 바꾸어
4. 순서만 바꾸면 되는 경우

map을 이용해서 해결하자
*/

//string을 알파벳 단위로 분류하기
map<char,int> process(string tmp){
    map<char,int> m;
    for(char c : tmp){
        m[c] += 1;
    }
    return m;
}

// true : 비슷한 단어 , false : 비슷하지 않은 단어
bool compareFunction(string target, map<char,int> tmp){
    int minusPoint = 0;
    int targetSize = target.length(); 
    for(int i = 0; i < target.length(); i++){
        char c = target[i];
        
        //알파벳이 없는경우
        if(tmp.find(c) == tmp.end()){
            minusPoint += 1;
            //문자가 두개 이상 없으면 안되므로
            if(minusPoint > 1){
                return false;
            }
        }
        //알파벳이 있는 경우
        else{
            targetSize -= 1;
            tmp[c] -= 1;
            if(tmp[c] == 0) tmp.erase(c);
        }
    }
    int remainAlpha = 0;
    for(auto iter = tmp.begin(); iter != tmp.end(); iter++){
        remainAlpha += iter->second;
    }
    //문자 하나만 더하면 되는 경우
    if(targetSize == 0 && remainAlpha == 1) return true;
    //문자 하나만 빼면 되는 경우
    else if(targetSize == 1 && remainAlpha == 0) return true;
    //문자 하나만 바꾸면  되는 경우
    else if(targetSize == 1 && remainAlpha == 1) return true;
    //순서만 바꾸면 되는 경우
    else if(targetSize == 0 && remainAlpha == 0) return true;
    else return false;
}

void sol(){
    int answer = 0;
    string target = v[0];
    for(int i = 1; i < n; i++){
        map<char,int> tmp = process(v[i]);
        //비슷한 단어인지 판단하여 맞으면 answer + 1
        if(compareFunction(target, tmp)){
            answer += 1;
        }
    }

    cout << answer << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    sol();

    return 0;
}
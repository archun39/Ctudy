#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

string S, E, Q;
set<string> arr;
set<string>::iterator iter;
int answer = 0;


void input(){
    cin >> S >> E >> Q;
}

//시계열 데이터를 10진수로 바꾸기
int timeToDec(string time){
    int hour, minutes;
    hour = (time[0] - '0') * 10 + (time[1] - '0');
    minutes = (time[3] - '0') * 10 + (time[4] - '0');
    int result = hour*60 + minutes;

    return result;
}

bool isExisted(string name){
    // iter 사용법을 배워놓자.
    iter = arr.find(name);
    if(iter == arr.end()) return false;
    
    return true;
}

void inputValue(string name){
    if(!isExisted(name)){
        arr.insert(name);
    }
}

void process(string time, string name){
    //비교하기 쉽게 10진수로 변환한다.
    int startTime = timeToDec(S);
    int endTime = timeToDec(E);
    int streamingTime = timeToDec(Q);
    int realTime = timeToDec(time);

    // case 1 : 개강총회를 시작하기 전에
    if(realTime <= startTime){
        inputValue(name);
    }

    // case 2 : 개강총회 끝나고 스트리밍 종료 사이
    else{
        if(endTime <= realTime && realTime <= streamingTime){
            //출석을 했다면 중복 count하지 않도록 지워주고,
            //answer에 +1 해준다.
            if(isExisted(name)) {
                arr.erase(iter);
                answer++;
            }
        }
    }
}

void sol(){
    string time, name;
    while(cin >> time >> name){
        if(time == "end") break;
        process(time, name);
    }

    cout << answer << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    sol();
    
    return 0;
}
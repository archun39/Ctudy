#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#define endl '\n'
using namespace std;

//접시의 수 : N
//초밥의 가짓수 : d
//연속해서 먹는 접시의 개수 : k
//쿠폰번호 : c
int N, d, k ,c;
vector<int> belt;
map<int,int> m;

void input(){
    cin >> N >> d >> k >> c;
    int sushi;
    for(int i = 0; i < N; i++){
        cin >> sushi;
        belt.push_back(sushi);
    }
}

//슬라이싱 윈도우로 초밥이 포함되고 제거되는 과정
int process(int nextSushi, int lastSushi){
    m[nextSushi] += 1;
    if(m[lastSushi] == 1) m.erase(lastSushi);
    else m[lastSushi] -= 1; //초밥의 개수가 0이면 map에서 삭제해주어야함
    return m.size(); //초밥 종류의 갯수를 의미
}

void sol(){
    
    m[c] = 1; //최대는 쿠폰을 활용한 경우

    //init
    for(int i = 0; i < k; i++){
        m[belt[i]] += 1;
    }
    int answer = m.size();
    int nextSushi, lastSushi;

    //탐색
    for(int i = k; i < N; i++){
        nextSushi = belt[i];
        lastSushi = belt[i-k];
        answer = max(answer, process(nextSushi, lastSushi));
        
    }
    //남은 바퀴
    for(int i = 0; i < k; i++){
        nextSushi = belt[i];
        lastSushi = belt[N+i-k];
        answer = max(answer, process(nextSushi, lastSushi));
    }

    cout << answer << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    sol();

    return 0;
}
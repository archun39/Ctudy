#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

// N : 층
// K : 자릿 수
// P : 반전 갯수
// X : 현재 층 
int N,K,P,X;

const bool num[10][7] = {
	{1, 1, 1, 0, 1, 1, 1},//0
	{0, 0, 1, 0, 0, 1, 0},//1
	{1, 0, 1, 1, 1, 0, 1},//2
	{1, 0, 1, 1, 0, 1, 1},//3
	{0, 1, 1, 1, 0, 1, 0},//4
	{1, 1, 0, 1, 0, 1, 1},//5
	{1, 1, 0, 1, 1 ,1 ,1},//6
	{1, 0, 1, 0, 0, 1, 0},//7
	{1, 1, 1, 1, 1, 1, 1},//8
	{1, 1, 1, 1, 0, 1, 1}//9
};

void input(){
    cin >> N >> K >> P >> X;
}

bool process(int tmp){
    int a = X;
    int b = tmp;
    int cnt = 0;
    for(int i = 0; i < K; i++){
        for(int j = 0; j < 7; j++){
            if(num[a%10][j] != num[b%10][j]) cnt++;
        }
        a/=10;
        b/=10;
    }

    return cnt <= P;
}

void sol(){
    //1층부터 N층까지 바꿀 수 있는 층들 계산
    int answer = 0;
    for(int i = 1; i <= N; i++){
        if(i==X) continue;
        if(process(i)) answer++;
    }

    cout << answer << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    input();
    sol();
    return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <memory.h>
using namespace std;

const int MAX = 101;
const int DICE = 6;

int board[MAX];
int N, M;
map<int, int> ladder;
map<int, int> snake;

void init(){
    memset(board, MAX, sizeof(board));
}

void input(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int start, end;
        cin >> start >> end;
        ladder[start] = end;
    }

    for(int i = 0; i < M; i++){
        int start, end;
        cin >> start >> end;
        snake[start] = end;
    }
}

bool checkHere(int here, int count){
    if(board[here] > count){
        board[here] = count;
        return true;
    }
    return false;
}

void turn(int here, int count){
    
    for(int i = 1; i <= DICE; i++){
        int next = here + i;
        if(next > 100) continue;

        if(ladder.find(next) != ladder.end()){
            if(checkHere(next, count+1)) turn(ladder[next], count+1);
        }
        else if(snake.find(next) != snake.end()){
            if(checkHere(next, count+1)) turn(snake[next], count+1);
        }
        else{
            if(checkHere(next, count+1)) turn(next, count+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    input();
    turn(1, 0);

    cout << board[100];
    return 0;
}
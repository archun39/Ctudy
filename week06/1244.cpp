#include <iostream>
#include <vector>
using namespace std;

struct T{
    int sex, switchs;
};

int N;
int M;
vector<int> state;
vector<T> students;

void input(){
    cin >> N;
    state = vector<int>(N+1);
    //1 ~ N까지 저장
    for(int i = 1; i <= N; i++){
        cin >> state[i];
    }

    cin >> M;
    students = vector<T> (M);
    for(int i = 0; i < M; i++){
        cin >> students[i].sex >> students[i].switchs;
    }
}

void changeState(int idx){
    state[idx] = !state[idx];
}

void boy(int num){
    int i = 2;
    int tmp = num;
    while(tmp <= N){
        changeState(tmp);
        tmp = num * (i++);
    }
}

void girl(int num){
    changeState(num);
    int left = num - 1;
    int right = num + 1;
    while(left >= 1 && right <= N){
        if(state[left] == state[right]){
            changeState(left--);
            changeState(right++);
        }
        else break;
    }
}

void print(){
    int p;
    for(int i = 1; i <= N; i++){
        cout << state[i] << " ";
        if(i % 20 == 0) cout << endl;
    }
    cout << endl;
}

void sol(){
    for(int i = 0; i < M; i++){
        T tmp = students[i];
        if(tmp.sex == 1) boy(tmp.switchs);
        else if(tmp.sex == 2) girl(tmp.switchs);
    }
    print();
}

int main(){
    input();
    sol();
    return 0;
}
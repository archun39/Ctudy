#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct T {
    ll height, cnt;

    T(int h, int c) : height(h), cnt(c) {};
};

const int MAX = 100001;
int N;
vector<ll> v;
vector<T> stack;

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        ll tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
}

void print(){
    for(int i = 0; i < stack.size(); i++){
        cout << stack[i].height << "("<< stack[i].cnt << ") ";
    }
    cout<<endl;
}

void sol(){
    
    stack.push_back(T(v[0], 1));
    ll answer = 0;
    //print();
    for(int i = 1; i < N; i++){

        int cur = v[i];

        if(stack.back().height < cur){
            stack.push_back(T(cur, 1));
        }
        else{
            int count = 0;
            while(true){
                T tmp = stack.back();
                stack.pop_back();
                
                if(cur == tmp.height){
                    tmp.cnt += count;
                    tmp.cnt++;
                    stack.push_back(tmp);
                    break;
                }
                else if(cur > tmp.height){
                    stack.push_back(tmp);
                    stack.push_back(T(cur, count+1));
                    break;
                }
                else{
                    answer = max(answer, tmp.height * (tmp.cnt + count));
                    count += tmp.cnt;
                }

                if(stack.empty()){
                    stack.push_back(T(cur, count+1));
                    break;
                }
            }
        }
        //print();
    }
    int count = 0;
    while(!stack.empty()){
        T tmp = stack.back();
        stack.pop_back();

        answer = max(answer, tmp.height * (tmp.cnt + count));
        count += tmp.cnt;
    }

    cout << answer << endl;
}

int main(){
    input();
    sol();
    return 0;
}
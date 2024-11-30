#include <iostream>
#include <string>
#include <vector>
#include <set>
#define endl '\n'
using namespace std;

int N, M;
set<string> keywords;
vector<string> blogs;

void input(){
    cin >> N >> M;
    string tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        keywords.insert(tmp);
    }

    for(int i = 0; i < M; i++){
        //문자에 공백이 포함되지 않으므로, 
        //getline()을 이용해서 받아올 필요가 없다.
        cin >> tmp; 
        blogs.push_back(tmp);
    }
}

void sol(){
    for(int i = 0; i < M; i++){
        string tmp = "";
        string blog = blogs[i];

        //parsing
        for(int i = 0; i < int(blog.size()); i++){
            if(blog[i] == ','){
                keywords.erase(tmp);
                tmp = "";
            }
            else{
                tmp += blog[i];
            }
        }

        //**tmp에 남아있는 데이터까지 처리해준다.
        keywords.erase(tmp);
        cout << keywords.size() << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    sol();
    return 0;
}
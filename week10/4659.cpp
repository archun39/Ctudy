#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// 모음 판별기
bool check_vowels(char c){
    return c =='a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool process(string s){
    bool rule1 = false; // 1. 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
    bool rule2 = false; // 2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
    bool rule3 = false; // 3. 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.

    const int MAX_WORD = 2;

    char last = s[0];
    bool last_vow = false;

    int count = -1;

    if(check_vowels(last)){
        rule1 = true;
        last_vow = true;
        count = 1;
    } 

    //모음은 양수 count, 자음은 음수 count

    for(int i = 1; i < s.length(); i++){
        char c = s[i];
        if(last == c){
            if(c == 'e' || c == 'o');
            else return false; //조건 3. 불만족
        }

        if(check_vowels(c)){
            rule1 = true;
            if(last_vow){
                count++;
            }
            else{
                count = 1;
            }
            last_vow = true;
        }
        else{
            if(!last_vow){
                count--;
            }
            else{
                count = -1;
            }
            last_vow = false;
        }
        
        last = c;
        if(abs(count) > MAX_WORD) return false; //조건 2. 불만족
    }

    return rule1;
}

void print(bool good, string password){
    if(good){
        cout << "<" << password << "> is acceptable." << endl;
    }
    else cout << "<" << password << "> is not acceptable." << endl;
}

int main(){
    string password;
    while(true){
        cin >> password;
        if(password == "end") break;

        bool good = process(password);
        print(good, password);
    }
    

    return 0;
}
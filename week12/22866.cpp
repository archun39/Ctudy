#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int N;
int Map[100001], Cnt[100001], Near[100001];
stack<pair<int, int>> Stack, Stack_2;

void input(){
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> Map[i];
}

void left_to_right (){
    for (int i = 1; i <= N; i++) {
		while (!Stack.empty() && Stack.top().first <= Map[i]) Stack.pop();
		Cnt[i] += Stack.size();
		if (!Stack.empty() && Near[i] == 0) Near[i] = Stack.top().second;
		Stack.push({ Map[i], i });
	}
}

void right_to_left(){
    for (int i = N; i >= 1; i--) { 
		while (!Stack_2.empty() && Stack_2.top().first <= Map[i]) Stack_2.pop();
		Cnt[i] += Stack_2.size();
		if (!Stack_2.empty())
		{
			if (Near[i] == 0)
				Near[i] = Stack_2.top().second;
			else if (abs(i - Near[i]) > abs(i - Stack_2.top().second)) 
				Near[i] = Stack_2.top().second;
		}
		Stack_2.push({ Map[i], i });
	}
}

void print(){
	for (int i = 1; i <= N; i++) {
		if (Cnt[i] == 0)
			cout << 0 << '\n';
		else
			cout << Cnt[i] << ' ' << Near[i] << '\n';
	}
}

int main() {
    input();
    left_to_right();
	right_to_left();
    print();

    return 0;
}
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

// 왼쪽에서 오른쪽으로 탐색하며 더 높은 건물을 찾음
void left_to_right() {
    for (int i = 1; i <= N; i++) {
        // 현재 건물보다 낮은 건물들은 스택에서 제거 (볼 수 없으므로)
        while (!Stack.empty() && Stack.top().first <= Map[i]) Stack.pop();

        // 스택에 남아 있는 건물들은 모두 현재 건물에서 볼 수 있는 더 높은 건물
        Cnt[i] += Stack.size(); // 볼 수 있는 건물의 개수를 추가
        if (!Stack.empty() && Near[i] == 0) 
            Near[i] = Stack.top().second; // 가장 가까운 더 높은 건물의 인덱스를 저장

        // 현재 건물을 스택에 추가 (높이와 위치 저장)
        Stack.push({ Map[i], i });
    }
}

// 오른쪽에서 왼쪽으로 탐색하며 더 높은 건물을 찾음
void right_to_left() {
    for (int i = N; i >= 1; i--) { 
        // 현재 건물보다 낮은 건물들은 스택에서 제거 (볼 수 없으므로)
        while (!Stack_2.empty() && Stack_2.top().first <= Map[i]) Stack_2.pop();

        // 스택에 남아 있는 건물들은 모두 현재 건물에서 볼 수 있는 더 높은 건물
        Cnt[i] += Stack_2.size(); // 볼 수 있는 건물의 개수를 추가
        if (!Stack_2.empty()) {
            if (Near[i] == 0) 
                Near[i] = Stack_2.top().second; // 가장 가까운 더 높은 건물의 인덱스를 저장
            else if (abs(i - Near[i]) > abs(i - Stack_2.top().second)) 
                Near[i] = Stack_2.top().second; // 더 가까운 건물이 있으면 업데이트
        }

        // 현재 건물을 스택에 추가 (높이와 위치 저장)
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
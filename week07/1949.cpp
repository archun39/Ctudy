#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10001;
int N;  // 마을의 수
vector<int> population(MAX);  // 각 마을의 주민 수 저장
vector<vector<int>> tree(MAX);  // 트리 구조 저장
vector<vector<int>> dp(MAX, vector<int>(2, 0));  // DP 테이블
vector<bool> visited(MAX, false);  // 방문 여부 체크

// DFS로 트리 탐색하며 DP 테이블 채우기
void dfs(int node) {
    visited[node] = true;

    // DP 초기값: 현재 노드를 선택한 경우와 선택하지 않은 경우
    dp[node][0] = 0;  // 현재 노드를 선택하지 않은 경우
    dp[node][1] = population[node];  // 현재 노드를 선택한 경우

    for (int child : tree[node]) {
        if (!visited[child]) {
            dfs(child);  // 자식 노드 탐색

            // 현재 노드를 선택한 경우: 자식 노드는 선택 불가
            dp[node][1] += dp[child][0];

            // 현재 노드를 선택하지 않은 경우: 자식 노드를 선택할 수도 있음
            dp[node][0] += max(dp[child][0], dp[child][1]);
        }
    }
}

int main() {
    cin >> N;

    // 각 마을의 주민 수 입력
    for (int i = 1; i <= N; ++i) {
        cin >> population[i];
    }

    // 트리 구조 입력
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // 1번 노드부터 DFS 시작
    dfs(1);

    // 1번 노드를 기준으로 선택한 경우와 선택하지 않은 경우 중 최대값 출력
    cout << max(dp[1][0], dp[1][1]) << endl;

    return 0;
}

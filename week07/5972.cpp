#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 50001
#define INF 1e9
using namespace std;

int N, M;
int map[MAX];
vector<pair<int, int>> v[MAX];  // 인접 리스트로 그래프 표현 (노드, 거리)

void input() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
}

void init() {
    fill(map, map + N + 1, INF);
    map[1] = 0;
}

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({1, 0});  // (노드, 거리(cow))

    while(!pq.empty()) {
        int node = pq.top().first;  // 현재 노드
        int cow = pq.top().second;  // 현재까지의 거리
        pq.pop();

        if(cow > map[node]) continue;

        for(auto &next : v[node]) {
            int nextNode = next.first;
            int nextCow = next.second;

            if(map[nextNode] > map[node] + nextCow) {
                map[nextNode] = map[node] + nextCow;
                pq.push({nextNode, map[nextNode]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    input();
    init();
    dijkstra();
    cout << (map[N] == INF ? -1 : map[N]) << endl;  // 연결되지 않으면 -1 출력
    return 0;
}

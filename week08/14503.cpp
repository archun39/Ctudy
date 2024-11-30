#include <vector>
#include <iostream>

using namespace std;

const int MAX = 51;

int N, M;
int R, C, D; // 방향: 0(북), 1(동), 2(남), 3(서)
int map[MAX][MAX]; // 벽: 1, 빈 공간: 0, 청소 완료: -1
int dx[4] = {-1, 0, 1, 0}; // 행 이동
int dy[4] = {0, 1, 0, -1}; // 열 이동
int answer = 0;

void input() {
    cin >> N >> M;
    cin >> R >> C >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
}

bool isWall(int r, int c) {
    return map[r][c] == 1;
}

void cleaning(int r, int c) {
    if (map[r][c] == 0) {
        map[r][c] = -1; // 청소 완료 표시
        answer++;
    }
}

bool canClean(int r, int c) {
    return map[r][c] == 0;
}

void solve() {
    while (true) {
        // 현재 위치 청소
        if (canClean(R, C)) {
            cleaning(R, C);
        }

        // 4방향 확인
        bool cleaned = false;
        for (int i = 0; i < 4; i++) {
            D = (D + 3) % 4; // 반시계 방향 회전
            int nr = R + dx[D];
            int nc = C + dy[D];

            if (!isWall(nr, nc) && canClean(nr, nc)) {
                R = nr;
                C = nc;
                cleaned = true;
                break;
            }
        }

        // 청소할 공간이 없는 경우
        if (!cleaned) {
            int backDir = (D + 2) % 4; // 뒤로 이동 방향
            int nr = R + dx[backDir];
            int nc = C + dy[backDir];

            if (isWall(nr, nc)) {
                // 뒤가 벽이면 종료
                cout << answer << endl;
                return;
            } else {
                // 뒤로 이동
                R = nr;
                C = nc;
            }
        }
    }
}

int main() {
    input();
    solve();
    return 0;
}

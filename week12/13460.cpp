#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

const int MAX = 11;

struct P {
    int x, y, count, move;
    bool status;

    P(int x, int y, int c, int m, bool s) : x(x), y(y), count(c), move(m), status(s) {}

    // Comparison operator for set usage
    bool operator<(const P& other) const {
        return tie(x, y, count, move, status) < tie(other.x, other.y, other.count, other.move, other.status);
    }
};

int N, M;
char board[MAX][MAX];
P blue = P(0, 0, 0, 0, true);
P red = P(0, 0, 0, 0, true);
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
bool isVisited[MAX][MAX][MAX][MAX];
int answer = 1e9;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') red = P(i, j, 0, 0, true);
            if (board[i][j] == 'B') blue = P(i, j, 0, 0, true);
        }
    }
}

bool isWall(int x, int y) {
    return board[x][y] == '#';
}

bool isGoal(int x, int y) {
    return board[x][y] == 'O';
}

P move_ball(P ball, int dir) {
    int x = ball.x, y = ball.y, m = 0;
    while (true) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (isWall(nx, ny)) break;
        if (isGoal(nx, ny)) return P(ball.x, ball.y, ball.count + 1, m, false);
        x = nx;
        y = ny;
        m++;
    }
    return P(x, y, ball.count + 1, m, true);
}

void sol() {
    queue<pair<P, P>> q; // red, blue
    q.push({red, blue});
    isVisited[red.x][red.y][blue.x][blue.y] = true;

    while (!q.empty()) {
        P r = q.front().first;
        P b = q.front().second;
        q.pop();

        //cout << r.x << ":" <<r.y << " .. " <<b.x << ":" <<b.y << endl;
        for (int i = 0; i < 4; i++) {
            P r_res = move_ball(r, i);
            P b_res = move_ball(b, i);

            if (!b_res.status) continue; // Ignore if blue falls into the goal
            if (!r_res.status) {         // Red falls into the goal

                answer = min(answer, r_res.count);
                continue;
            }

            // Resolve overlap
            if (r_res.x == b_res.x && r_res.y == b_res.y) {
                if (r_res.move > b_res.move) {
                    r_res.x -= dx[i];
                    r_res.y -= dy[i];
                } else {
                    b_res.x -= dx[i];
                    b_res.y -= dy[i];
                }
            }

            // Skip if count exceeds limit
            if (r_res.count >= 10 || b_res.count >= 10) continue;

            if (!isVisited[r_res.x][r_res.y][b_res.x][b_res.y]) {
                isVisited[r_res.x][r_res.y][b_res.x][b_res.y] = true;
                q.push({r_res, b_res});
                //cout << i << endl;
            }
        }
    }
}

int main() {
    input();
    sol();
    cout << (answer == 1e9 ? -1 : answer) << endl;
    return 0;
}

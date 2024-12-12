#include <iostream>
#include <vector>
#include <algorithm>
#define max(a,b) a > b ? a : b
using namespace std;
typedef long long ll;


const int MAX = 21;

int N;
vector<vector<ll>> map(MAX, vector<ll>(MAX, 0));
ll answer = 0;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
}

vector<vector<ll>> move(vector<vector<ll>> board, int dir) {
    vector<vector<bool>> check(N, vector<bool>(N, false));

    if (dir == 0) { // Up
        for (int i = 0; i < N; i++) {
            for (int j = 1; j < N; j++) {
                if (board[j][i] == 0) continue;
                for (int k = j - 1; k >= 0; k--) {
                    if (board[k][i] == board[k + 1][i] && !check[k][i]) {
                        board[k][i] *= 2;
                        board[k + 1][i] = 0;
                        check[k][i] = true;
                        break;
                    } else if (board[k][i] == 0) {
                        board[k][i] = board[k + 1][i];
                        board[k + 1][i] = 0;
                    } else {
                        break;
                    }
                }
            }
        }
    } else if (dir == 1) { // Down
        for (int i = 0; i < N; i++) {
            for (int j = N - 2; j >= 0; j--) {
                if (board[j][i] == 0) continue;
                for (int k = j + 1; k < N; k++) {
                    if (board[k][i] == board[k - 1][i] && !check[k][i]) {
                        board[k][i] *= 2;
                        board[k - 1][i] = 0;
                        check[k][i] = true;
                        break;
                    } else if (board[k][i] == 0) {
                        board[k][i] = board[k - 1][i];
                        board[k - 1][i] = 0;
                    } else {
                        break;
                    }
                }
            }
        }
    } else if (dir == 2) { // Left
        for (int i = 0; i < N; i++) {
            for (int j = 1; j < N; j++) {
                if (board[i][j] == 0) continue;
                for (int k = j - 1; k >= 0; k--) {
                    if (board[i][k] == board[i][k + 1] && !check[i][k]) {
                        board[i][k] *= 2;
                        board[i][k + 1] = 0;
                        check[i][k] = true;
                        break;
                    } else if (board[i][k] == 0) {
                        board[i][k] = board[i][k + 1];
                        board[i][k + 1] = 0;
                    } else {
                        break;
                    }
                }
            }
        }
    } else if (dir == 3) { // Right
        for (int i = 0; i < N; i++) {
            for (int j = N - 2; j >= 0; j--) {
                if (board[i][j] == 0) continue;
                for (int k = j + 1; k < N; k++) {
                    if (board[i][k] == board[i][k - 1] && !check[i][k]) {
                        board[i][k] *= 2;
                        board[i][k - 1] = 0;
                        check[i][k] = true;
                        break;
                    } else if (board[i][k] == 0) {
                        board[i][k] = board[i][k - 1];
                        board[i][k - 1] = 0;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    return board;
}

ll find_value(const vector<vector<ll>>& tmp) {
    ll res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res = max(res, tmp[i][j]);
        }
    }
    return res;
}

void sol(vector<vector<ll>> m, int count) {
    if (count >= 5) {
        answer = max(answer, find_value(m));
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        vector<vector<ll>> tmp = move(m, dir);
        sol(tmp, count + 1);
    }
}

int main() {
    input();
    sol(map, 0);
    cout << answer << endl;
    return 0;
}

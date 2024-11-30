#include <iostream>
#include <cmath>

using namespace std;

// 변수 이름을 변경하여 충돌 방지
int x1, y1_, r1, x2, y2_, r2;

void input() {
    cin >> x1 >> y1_ >> r1 >> x2 >> y2_ >> r2;
}

int sol() {
    // 두 원의 중심 간 거리 계산
    double dist = sqrt(pow(x1 - x2, 2) + pow(y1_ - y2_, 2));
    
    // 경우 1: 두 원의 중심이 동일한 경우
    if (x1 == x2 && y1_ == y2_) {
        if (r1 == r2) return -1;  // 동일한 원
        else return 0;  // 중심이 같지만 반지름이 다름 (교점 없음)
    }

    // 경우 2: 거리와 반지름에 따른 교점 개수 판단
    if (dist > r1 + r2) return 0;         // 두 원이 너무 멀어서 교차하지 않음
    if (dist < abs(r1 - r2)) return 0;    // 한 원이 다른 원 안에 있지만 접하지 않음
    if (dist == r1 + r2) return 1;        // 두 원이 외접 (1개의 교점)
    if (dist == abs(r1 - r2)) return 1;   // 두 원이 내접 (1개의 교점)

    // 경우 3: 두 원이 두 점에서 교차하는 경우
    return 2;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        input();
        cout << sol() << endl;
    }

    return 0;
}

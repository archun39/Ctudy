#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int TEAM_SIZE = 6; // 팀의 인원 수
const int MAX = 201;     // 최대 팀 번호

int N; // 참가자의 수
vector<int> ranking;     // 참가자 순위
vector<int> v[MAX];      // 각 팀에 속한 참가자 순위
int total[MAX];          // 각 팀의 점수 합산
set<int> team;           // 유효한 팀 번호를 저장
int isVisited[MAX];      // 각 팀의 점수 누적 횟수를 카운트 (최대 4명)

// 입력 처리
void input() {
    cin >> N; // 참가자 수 입력
    for (int i = 0; i < N; i++) {
        int team_num;
        cin >> team_num;           // 참가자의 팀 번호 입력
        ranking.push_back(team_num); // 순위별로 팀 번호 저장
        v[team_num].push_back(i);    // 팀별로 참가자의 순위 저장
        team.insert(team_num);       // 팀 번호 저장
    }
}

// 초기화 함수
void init() {
    ranking.clear(); // 순위 벡터 초기화
    for (int i = 0; i < MAX; i++) {
        total[i] = 0;    // 각 팀의 총점 초기화
        v[i].clear();    // 각 팀의 순위 목록 초기화
        isVisited[i] = 0; // 점수 누적 횟수 초기화
    }
    team = set<int>(); // 팀 번호 초기화
}

// 문제 풀이 함수
void sol() {
    // 팀 삭제 (팀원이 TEAM_SIZE(6)명이 아닌 팀 제거)
    vector<int> del; // 삭제할 팀 번호 저장
    for (auto t : team) {
        if (v[t].size() != TEAM_SIZE) { // 팀원이 6명이 아니면
            del.push_back(t);
        }
    }
    for (int i = 0; i < del.size(); i++) {
        team.erase(del[i]); // 유효하지 않은 팀 제거
    }

    int score = 1; // 초기 점수 (순위가 높을수록 작은 점수)
    for (int i = 0; i < N; i++) {
        int t = ranking[i]; // 현재 순위의 팀 번호
        if (team.find(t) == team.end()) continue; // 유효하지 않은 팀은 스킵
        if (isVisited[t] < 4) { // 팀에서 상위 4명까지만 점수 누적
            total[t] += score;  // 점수 합산
            isVisited[t]++;     // 점수 누적 횟수 증가
        }
        score++; // 다음 순위 점수
    }

    // 우승 팀 결정
    int winner_score = 1e9; // 최소 점수 초기화
    int winner = 0;         // 우승 팀 번호
    int winner_five = 0;    // 우승 팀의 5번째 참가자 순위
    for (int i = 0; i < MAX; i++) {
        if (total[i] == 0) continue; // 점수가 없는 팀은 스킵
        
        if (total[i] < winner_score) { // 더 낮은 점수를 가진 팀 찾기
            winner_score = total[i];
            winner_five = v[i][4]; // 5번째 참가자의 순위 저장
            winner = i;            // 우승 팀 번호 저장
        } else if (total[i] == winner_score) { // 점수가 같을 경우
            if (v[i][4] < winner_five) { // 5번째 참가자의 순위로 비교
                winner_score = total[i];
                winner_five = v[i][4];
                winner = i;
            }
        }
    }
    cout << winner << endl; // 우승 팀 번호 출력
}

int main() {
    int T; // 테스트 케이스 수
    cin >> T;
    while (T--) {
        init(); // 초기화
        input(); // 입력 처리
        sol();   // 문제 풀이
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 101;

int R, C;
char map[MAX][MAX];
bool isVisited[MAX][MAX];
int N;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<int> sticks;
vector<pair<int,int>> cluster;

void input(){
	cin >> R >> C;
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= C; j++){
			cin >> map[i][j];
		}
	}

	cin >> N;
	sticks = vector<int> (N);
	for(int i = 0; i < N; i++){
		cin >> sticks[i];
		sticks[i] = R - sticks[i] + 1;
	}
}

bool isOut(int r, int c){
	return r < 1 || c < 1 || r > R || c > C;
}

void init(){
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			isVisited[i][j] = false;
		}
	}
	cluster.clear();
}

void print(){
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= C; j++){
			cout << map[i][j];
		}
		cout << endl;
	}
}

int throwStick(int n, int turn){
	if(turn % 2 == 0){ //왼쪽 -> 오른 (창영 턴)
		for(int c = 1; c <= C; c++){
			if(map[n][c] == '.') continue;
			else if(map[n][c] == 'x'){
				return c;	
			}
		}
	}
	else{	//왼쪽 <- 오른 (상근 턴)
		for(int c = C; c >= 1; c--){
			if(map[n][c] == '.') continue;
			else if(map[n][c] == 'x'){
				return c;
			}
		}
	}
	return -1;
}

void isCluster(int r, int c, bool &check){ //dfs
	if(r == R){
		//cluster가 바닥에 붙어있는 경우 cluster가 아님
		check = false;
		return;
	} 

	isVisited[r][c] = true;
	cluster.push_back({r,c}); //cluster정보 저장
	for(int i = 0; i < 4; i++){
		int nr = r + dx[i];
		int nc = c + dy[i];

		if(!isOut(nr, nc) && !isVisited[nr][nc]){
			if(map[nr][nc] == 'x'){
				isCluster(nr, nc, check);
			}
		}
	}
}

int dropCluster(){
	//모든 클러스터에 대해서 drop 판별하지 않으면 예외가 발생할 수 있음
	int drop = MAX;
	for(int i = 0; i < cluster.size(); i++){
		int x = cluster[i].first;
		int y = cluster[i].second;

		for(int r = x+1; r <= R; r++){ //현재 클러스터보다 아래만 판별하면 됨
			if(map[r][y] == 'x' && !isVisited[r][y]){ 
				drop = min(drop, r-x-1);
				break; //가장 처음 만나는 미네랄이므로 찾으면 break 해야함
			}
			else if(r == R && map[r][y] == '.'){ //바닥
				drop = min(drop, r-x);
			}
		}
	}
		
	return drop;	
}

void dropProcess(int drop){
	//먼저 .로 초기화 한 이후 
	//x로 해야 겹치는 부분이 발생하지 않음
	for(int i = 0; i < cluster.size(); i++){
		int r = cluster[i].first;
		int c = cluster[i].second;
		map[r][c] = '.';
	}
	for(int i = 0; i < cluster.size(); i++){
		int r = cluster[i].first;
		int c = cluster[i].second;
		map[r+drop][c] = 'x';
	}
}

void process(int r, int c){
	map[r][c] = '.'; //맞은 미네랄 파괴

	//맞은 미네랄을 기준으로 주변 cluster판별
	for(int i = 0; i < 4; i++){
		int nr = r + dx[i];
		int nc = c + dy[i];

		if(!isOut(nr, nc) && map[nr][nc] == 'x'){
			init();
			bool check = true;
			isCluster(nr, nc, check);

			if(check){	//cluster가 존재하는 경우
 				int drop = dropCluster(); //얼마나 drop해야하는지 최소값 구함
				dropProcess(drop); //drop
				return;
			}
		}
	}
}

void sol(){
	for(int i = 0; i < sticks.size(); i++){
		int c = throwStick(sticks[i], i);
		
		if(c == -1) continue; //맞은 미네랄이 없음
		else{
			//미네랄이 맞음
			process(sticks[i], c);
		}
	}
}

int main(){

	input();
	sol();
	print();
	return 0;
}

/*
좋은 예시
9 8
........
...xxx..
.xxx....
.x.x.xxx
.x.x...x
.x.xxx.x
.x.....x
.x.....x
.xxx...x
1
7
*/
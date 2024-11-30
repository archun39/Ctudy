#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX_BEER = 20;


struct T{
	int x, y;
};

int t;
int n;
vector<T> v;
T current;
T festival;
int beer = 20;
bool isVisited[101];
bool answer = false;

//v, answer, isVisited
void init(){
	v = vector<T> ();
	answer = false;
	for(int i = 0; i < 101; i++){
		isVisited[i] = false;
	}
}

//두 좌표의 거리 계산
int getDist(T a, T b){
	return abs(a.x - b.x) + abs(a.y - b.y);
}

void findNextDir(T cur){
	queue<T> q;
	q.push(cur);

	while(!q.empty()){
		T now = q.front();	
		q.pop();
		
		if(getDist(now, festival) <= 1000){	//현재 위치에서 페스티벌로 이동가능 여부 판단
			answer = true;
			break;
		}

		for(int i = 0; i < n; i++){
			T tmp = v[i];
			if(!isVisited[i] && getDist(tmp, now) <= 1000){ //편의점 방문 여부 및 거리 판단
				q.push(tmp);
				isVisited[i] = true;
			}
		}
	}
}

void sol(){
	findNextDir(current);
	answer? cout << "happy" << endl : cout << "sad" << endl;
}

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		init();
		cin >> current.x >> current.y;
		for(int i = 0; i < n; i++){
			T tmp;
			cin >> tmp.x >> tmp.y;
			v.push_back(tmp);
		}
		cin >> festival.x >> festival.y;
		sol();
	}	
  return 0;
}

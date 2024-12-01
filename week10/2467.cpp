#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

int N;
vector<pair<ll, bool>> v; //양수면 true, 음수면 false

void input(){
  cin >> N;
	for(int i = 0; i < N; i++){
		ll tmp;
		bool sign = true;
		cin >> tmp;
		if(tmp < 0){
			sign = false;
		}
		v.push_back(make_pair(abs(tmp), sign));
	}
}

bool cmp(pair<ll,bool> A, pair<ll,bool> B){
	return A.first < B.first;
}

void sol(){
	sort(v.begin(), v.end(), cmp);

	ll min_res = 1e9 * 3;
	ll ans1, ans2;

	for(int i = 0; i < v.size()-1; i++){
		auto x1 = v[i];
		auto x2 = v[i+1];
		ll res;
		if(x1.second == x2.second){ //같은 부호
			res = abs(x1.first + x2.first);
		}
		else{ //다른 부호
			res = abs(x1.first - x2.first);
		}

		if(res < min_res){
			min_res = res;
			ans1 = (x1.second) ? x1.first : x1.first*(-1);
			ans2 = (x2.second) ? x2.first : x2.first*(-1);
		}
	}

	if(ans1 < ans2) cout << ans1 << " " << ans2 << endl;
	else cout << ans2 << " " << ans1 << endl;
}

int main(){
	input();
	sol();

	return 0;
}

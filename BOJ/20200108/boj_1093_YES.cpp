#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 0xFFFFFFFF/2 - 1;
int v[33], cost[33], N, K, have[33];
map<int ,int> m[2];
int ans = MAX;
	
int main(){
	cin >> N;
	
	for(int i = 0; i < N; i++)cin >> v[i];
	for(int i = 0; i < N; i++)cin >> cost[i];
	
	cin >> K;
	
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		int t;
		cin >> t;
		have[t] = 1;
	}
	
	int l = N/2;
	int r = N - N/2;
	
	for(int i = 0; i < (1 << l); i++){
		int val = 0;
		int c = 0;
		for(int j = 0; j < l; j++){
			if(i & (1 << j)){
				c+=cost[j];
				val += (!have[j] ? v[j] : 0);
			}
			else if(have[j]){
				val -= v[j];
			}
		}
		if(m[0].find(c) != m[0].end()){
			m[0][c] = min(m[0][c], val);
		}
		else{
			m[0][c] = val;
		}
	}
	
	
	for(int i = 0; i < (1 << r); i++){
		int val = 0;
		int c = 0;
		for(int j = 0; j < r; j++){
			if(i & (1 << j)){
				c+=cost[l+j];
				val += (!have[l+j] ? v[l+j] : 0);
			}
			else if(have[l+j]){
				val -= v[l+j];
			}
		}
		if(m[1].find(c) != m[1].end()){
			m[1][c] = min(m[1][c], val);
		}
		else{
			m[1][c] = val;
		}
	}
	
	int t = MAX;
	
	auto it = m[1].end();
	it--;
	
	for(it; ; it--){
		t = min(it->second, t);
		it->second = t;
		if(it == m[1].begin())break;
	}
	
	
	for(it = m[0].begin(); it != m[0].end(); it++){
		auto target = K - it->first;
		
		auto it2 = m[1].lower_bound(target);
		
		if(it2 != m[1].end()){
				ans = min(ans, it->second + it2->second);
		}
	}
	
	if(ans == MAX){
		cout << -1;
	}
	else{
		cout << max(ans, 0);
	}
}
#include <iostream>
#include <map>

using namespace std;

using ll = long long;
int l, r;
int N, K;
int Arr[31];
map<ll, ll> m1;

ll ans = 0;
void make_left(int n, ll c){
	if(c > K)return;
	if(n == l){
		m1[c]++;
		ans++;
		return;
	}
	
	make_left(n+1, c+Arr[n]);
	make_left(n+1, c);
}

void make_right(int n, int c){
	if(c > K)return;
	if(n == r){
		if(c == 0)return;
		auto it = m1.upper_bound(K-c);
		it--;
		ans += it->second;
	
		return;
	}
	make_right(n+1, c+ Arr[n+l]);
	make_right(n+1, c);
}

int main(){
	cin >> N >> K;
	for(int i = 0; i < N; i++)cin >> Arr[i];
	
	l = N/2;
	r = N - N/2;
	
	make_left(0,0);
	ll t = 0;
	for(auto it = m1.begin(); it != m1.end(); it++){
		t += it->second;
		it->second = t;
	}
	make_right(0,0);
	
	cout << ans;
}
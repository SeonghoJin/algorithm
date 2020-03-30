/*#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const long long MOD = 1'000'000'007;


long long visit[100'001];

vector<pair<long long, long long>> adj[100'001];
long long ans = 0;

long long dfs(long long n){
	
	visit[n] = 1;
	
	long long s = 0, k;
	
	for(long long i = 0; i < adj[n].size(); i++){
		
		pair<long long, long long> t = adj[n][i];
		long long next = adj[n][i].first;
		long long c = adj[n][i].second;
		if(visit[next])continue;
		
		k = dfs(next) * c %MOD + c;
		k%= MOD;
		ans = (ans + k + k*s) % MOD;
		s = (k + s) % MOD;
	
	}
	
	return s;
}

int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	long long N;
	
	cin >> N;
	
	for(long long i = 0; i < N-1; i++){
		
		long long a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
		
	}
	dfs(1);
	cout << ans%MOD;
	
	
	
}*/
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
const int MAX_N = 200'001;
const int MAX_K = 1'000'001;
int ans = INT_MAX;
int sz[MAX_N];
int ki[MAX_N];
vector<pii> adj[MAX_N];
map<int,int> dp;
int N, K;

int dfs(int here, int par){
	sz[here] = 1;
	for(pii temp : adj[here]){
		int next = temp.first;
		if(next == par || ki[next])continue;
		sz[here] += dfs(next, here);
	}
	return sz[here];
}

int get_centroid(int here, int par, int cap){
	for(pii temp : adj[here]){
		int next = temp.first;
		if(next == par || ki[next])continue;
		if(sz[next] > cap){
			return get_centroid(next, here, cap);
		}
	}
	return here;
}

void compute(int here, int par, int weigth, int depth){
	if(weigth > K)return;
	auto it = dp.find(K-weigth);
	if(it != dp.end()){
		ans = min(ans, it->second + depth);
	}
	for(pii temp : adj[here]){
		int next = temp.first;
		int w = temp.second;
		if(next == par || ki[next]){
			continue;
		}
		compute(next,here,w+weigth,depth+1);
	}
}

void add(int here, int par, int weight, int depth){
	if(weight > K)return;
	auto it = dp.find(weight);
	if(it != dp.end()){
		it->second = min(it->second, depth);
	}
	else{
		dp[weight] = depth;
	}
	for(pii temp : adj[here]){
		int next = temp.first;
		int w = temp.second;
		if(next == par || ki[next]){
			continue;
		}
		add(next,here,w+weight,depth+1);
	}
}

void go(int here){
	int cap = dfs(here,-1)/2;
	int center = get_centroid(here,-1,cap);
	dp.clear();
	dp[0] = 0;
	ki[center] = 1;
	for(pii temp : adj[center]){
		int next = temp.first;
		int w = temp.second;
		if(ki[next])continue;
		compute(next,center,w,1);
		add(next,center,w,1);
	}

	for(pii temp : adj[center]){
		if(ki[temp.first])continue;
		go(temp.first);
	}
}
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> N >> K;
	for(int i = 0; i < N-1; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}

	go(0);

	if(ans == INT_MAX){
		cout << -1;
	}
	else cout << ans;
}
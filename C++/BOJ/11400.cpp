#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
const int MAX_V = 100'001;
const int MAX_E = 1'000'001;
int V, E;
vector<int> edges[MAX_V];
vector<pii> answer;
int cnt[MAX_V], cur = 1;

int dfs(int n, int par){
	int here = cnt[n] = cur++;

	for(int next : edges[n]){
		if(next == par)continue;

		if(cnt[next] == 0){
			int prev = dfs(next, n);
			if(prev > cnt[n]){
				answer.push_back({min(n,next),max(n,next)});
			}
			here = min(here, prev);
		}
		else{
			here = min(here, cnt[next]);
		}
	}
	return here;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	cin >> V >> E;
	for(int i = 0; i < E; i++){
		int  a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	dfs(1,0);
	cout << answer.size() << '\n';

	
	sort(answer.begin(), answer.end());
	for(int i = 0; i < answer.size(); i++){
		cout << answer[i].first << " " << answer[i].second << '\n';
	}
}
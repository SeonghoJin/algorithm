#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <queue>
using namespace std;
const int MAX = 500001;
const int MIN = -2100000000;
int N, M, low[MAX], flag[MAX], cnt, cost[MAX], dp[MAX], SCC_COST[MAX], INDEGREE[MAX];
vector<int> adj[MAX], isrt;
vector<vector<int>> SCC;
stack<int> s;
set<int> st[MAX];
int makeSCC(int n){
	
	int result = low[n] = cnt++;
	s.push(n);
	
	for(int i = 0; i < adj[n].size(); i++){
		int next = adj[n][i];
		
		if(low[next] == 0){
			result = min(result, makeSCC(next));
		}
		else if(flag[next] == 0){
			result = min(result, low[next]);
		}
	}
	
	if(result == low[n]){
		vector<int> scc;
		while(1){
			int t = s.top(); s.pop();
			flag[t] = true;
			low[t] = n;
			scc.push_back(t);
			if(t == n)break;
		}
		SCC.push_back(scc);
	}
	return result;
}

int dfs(int n){
	
	int& ret = dp[n];
	
	for(auto it = st[n].begin(); it != st[n].end(); it++){
		int next = *it;
		
		
	}
	
}

int main(){
	cin >> N >> M;
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	for(int i = 0; i < M; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	
	for(int i = 1; i <= N; i++){
		if(low[i] == 0)makeSCC(i);
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < adj[i].size(); j++){
			if(low[i] == low[adj[i][j]])continue;
			if(st[low[i]].push(low[adj[i][j]]).second)INDEGREE[low[adj[i][j]]]++;
		}
	}
	
	for(int i = 1; i <= N; i++){
		cin >> cost[i];
	}
	
	int S,P;
	cin >> S >> P;
	
	for(int i = 0; i < P; i++){
		int a;
		cin >> a;
		isrt.push_back(a);
	}
	
	queue<int> q;
	fill(dp,dp+MAX,MIN);
	for(int i = 0; i < SCC.size(); i++){
		int t_cost = 0;
		for(int j = 0; j < SCC[i].size(); j++){
			int temp = SCC[i][j];
			t_cost+=cost[SCC[i][j]];
		}
		SCC_COST[low[SCC[i][0]]] = t_cost;
		if(INDEGREE[low[SCC[i][0]]] == 0){
			q.push(low[SCC[i][0]]);
		}
	}
	
	
	while(!q.empty()){
		int temp = q.front(); q.pop();
		if(temp == low[S]){dp[temp] = SCC_COST[temp];}
		for(auto it = st[temp].begin(); it != st[temp].end(); it++){
			int next = *it;
			int next_cost = SCC_COST[next];
			INDEGREE[next]--;
			dp[next] = max(dp[next],dp[temp]+next_cost);
			if(INDEGREE[next] == 0){
				q.push(next);
			}
		}
	}
	
	int answer = 0;
	
	for(int i = 0; i < isrt.size(); i++){
		answer = max(answer, dp[low[isrt[i]]]);
	}
	
	cout << answer << '\n';
	
	
}



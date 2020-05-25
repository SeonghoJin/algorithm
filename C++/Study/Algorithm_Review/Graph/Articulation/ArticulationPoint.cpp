#include <bits/stdc++.h>

using namespace std;
const int MAX_V = 10'001;
const int MAX_E = 100'001;

vector<int> adj[MAX_V];
int parent[MAX_V];
int V, E;
int cnt = 1;
int m_num[MAX_V];
int answer[MAX_V];

int dfs(int n, int par, bool flag){
	m_num[n] = cnt++;
	parent[n] = par;
	
	int mi = m_num[n];
	int child = 0;
	for(int next : adj[n]){
		if(next == par)continue;
		if(m_num[next] == 0){
			int prev= dfs(next, n, 0);
			child++;
			if(!flag && prev >= m_num[n]){
				answer[n] = 1;
			}
			mi =  min(mi, prev);
		}
		else{
			mi = min(mi, m_num[next]);
		}
	}

	if(flag && child > 1){
		answer[n] = 1;
	}
	return mi;
}

void print(){
	for(int i = 1; i <= V; i++){
		cout << m_num[i] << " ";
	}
	cout << '\n';
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	cin >> V >> E;

	for(int i = 0; i < E; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 1; i <= V; i++){
		if(m_num[i] == 0){
			dfs(i, 0, 1);
		}
	}
	int count = 0;
	for(int i = 1; i <= V; i++){
		if(answer[i]){count++;}
	}
	cout << count << '\n';
	for(int i = 1; i <= V; i++){
		if(answer[i])cout << i << " ";
	}
}
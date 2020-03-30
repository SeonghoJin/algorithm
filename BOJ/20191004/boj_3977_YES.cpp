/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <set>
using namespace std;
const int MAX = 100001;

int N, M, flag[MAX], low[MAX], cnt, topo[MAX];
vector<int> adj[MAX];
stack<int> s;

int dfs(int n){
	int result = low[n] = cnt++;
	s.push(n);
	
	for(int i = 0; i < adj[n].size(); i++){
		int next = adj[n][i];
		
		if(low[next] == 0){
			result = min(result, dfs(next));
		}
		else if(flag[next] == 0){
			result = min(result, low[next]);
		}
	}
	
	if(result == low[n]){
		
		while(1){
			int t = s.top(); s.pop();
			low[t] = result;
			flag[t] = 1;
			if( t == n)break;
		}
	}
	return result;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--){
		cin >> N >> M;
		fill(flag, flag+MAX, 0);
		fill(low, low+MAX, 0);
		fill(topo,topo+MAX, 0);
		for(int i = 0; i <= N+1; i++){adj[i].clear();}
		stack<int> Temp;
		s.swap(Temp);
		cnt = 0;
		for(int i = 0; i < M; i++){
			int a, b;
			cin >> a >> b;
			a++; b++;
			adj[a].push_back(b);
		}
		
		for(int i = 1; i <= N; i++){
			if(flag[i]==0)dfs(i);
		}
		
		for(int i = 1; i <= N; i++){
			for(int j = 0; j < adj[i].size(); j++){
				if(low[i] != low[adj[i][j]]){topo[low[adj[i][j]]]++;}
			}	
		}
		set<int> ans;
		for(int i = 1; i <= N; i++){
			if(topo[low[i]] == 0){ans.push(low[i]);}
		}
		
		if(ans.size() != 1){cout << "Confused" << '\n';}
		else {
			int k = *(ans.begin());
			for(int i = 1; i <= N; i++){
				if(low[i] == k){cout << i-1 << '\n';}
			}
		}
		cout << '\n';
	}
	
	
}*/
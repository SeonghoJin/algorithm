#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

using pii = pair<int, int>;
const int MAX = 100001;
int N, K;
vector<pair<int,int>> adj[MAX];
int parent[MAX];
int dep[MAX];
int next_sptle[23][MAX];
int min_sptle[23][MAX];
int max_sptle[23][MAX];

void dfs(int here, int p, int depth){
	parent[here] = p;
	dep[here] = depth;
	for(int i = 0; i < adj[here].size(); i++){
		if(adj[here][i].first == p){
			min_sptle[0][here] = max_sptle[0][here] = adj[here][i].second;
			continue;
		}
		dfs(adj[here][i].first, here, depth+1);
	}
	
}

void make_tree(){
	dfs(1,0,0);
}

void make_sptle(){
	
	min_sptle[0][1] = 987654321;
	max_sptle[0][1] = 0;
	
	for(int i = 1; i <= N; i++){
		next_sptle[0][i] = parent[i];
	}
	
	for(int i = 1; i < 23; i++)
		for(int j = 1; j <= N; j++){
				
			next_sptle[i][j] = next_sptle[i-1][next_sptle[i-1][j]];
			min_sptle[i][j] = min(min_sptle[i-1][j], min_sptle[i-1][next_sptle[i-1][j]]);
			max_sptle[i][j] = max(max_sptle[i-1][j], max_sptle[i-1][next_sptle[i-1][j]]);
		}
	
}

pair<int ,int> LCA(int a, int b){
	
	int min_ans = 987654321;
	int max_ans = 0;
	
	
	if(dep[a] < dep[b])swap(a, b);
		
	int diff = dep[a] - dep[b];
		
	for(int i = 0; i < 23; i++){
		if(diff & (1 << i)){
			min_ans = min(min_ans, min_sptle[i][a]);
			max_ans = max(max_ans, max_sptle[i][a]);
			a = next_sptle[i][a];	
		}
	}
	
	if(a != b){
		for(int i = 22; i >= 0; i--){
			if(next_sptle[i][a] == next_sptle[i][b])continue;
			min_ans = min(min_ans, min(min_sptle[i][a], min_sptle[i][b]));
			max_ans = max(max_ans, max(max_sptle[i][a], max_sptle[i][b]));
			a = next_sptle[i][a];
			b = next_sptle[i][b];
		}
	
	
	min_ans = min(min_ans, min(min_sptle[0][a], min_sptle[0][b]));
	max_ans = max(max_ans, max(max_sptle[0][a], max_sptle[0][b]));
	}
	
	return make_pair(min_ans, max_ans);
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N;
	
	for(int i = 0; i < N-1; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	
	
	
	make_tree();
	make_sptle();
	
	cin >> K;
	
	while(K--){
		int a, b;
		cin >> a >> b;
		pair<int, int> temp = LCA(a, b);
		cout << temp.first << " " << temp.second << '\n';
	}
	
}
#include <iostream>
#include <vector>

using namespace std;


int N, M;
vector<int> adj[201];

int visit[201];
int d[201];

bool dfs(int n){
	if(visit[n])return false;
	visit[n] = 1;
	for(int i = 0; i < adj[n].size(); i++){
		int next = adj[n][i];
		
		if(d[next] == 0 || dfs(d[next]) ){
			d[next] = n;
			return true;
		}
	}
	
	return false;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++){
		int T;
		cin >> T;
		while(T--){
			int t;
			cin >> t;
			adj[i].push_back(t);
			cout << t << " ";
		}
		cout << '\n';
	}
	
	int ans = 0;
	for(int i = 1; i <= N; i++){
		fill(visit, visit+201, 0);
		ans += dfs(i);
	}
	
	cout << ans;
	
}
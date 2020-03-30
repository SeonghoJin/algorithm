/*
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using pii = pair<int, int>;

int dep[100001];
vector<pii> adj[100001];
int sptle[100001][20];
long long sptle_cost[100001][20];
long long dist[100001];
int N;
int dfs(int depth, int parent, int n, long long d){
	sptle[n][0] = parent;
	dep[n] = depth;
	dist[n] = d;
	for(int i = 0; i < adj[n].size(); i++){
		if(adj[n][i].first == parent)continue;
		sptle_cost[adj[n][i].first][0] = adj[n][i].second; 
		dfs(depth+1,n,adj[n][i].first,d+adj[n][i].second);
	}
}

void make_sparsetable(){
	
	for(int i = 1; i < 20; i++){
		for(int j = 1; j <= N; j++){
			sptle[j][i] = sptle[sptle[j][i-1]][i-1];
			sptle_cost[j][i] = sptle_cost[sptle[j][i-1]][i-1]+sptle_cost[j][i-1];
		}
	}
	
	/*for(int i = 1; i <= N; i++){
		for(int j = 0; j < 20; j++){
		cout << sptle_cost[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < 20; j++){
		cout << sptle[i][j] << " ";
		}
		cout << '\n';
	}
	
}

long long answer1(int a, int b){
	long long cost = 0;
	if(dep[a] != dep[b]){
		int differ = abs(dep[a] - dep[b]);
		if(dep[a] > dep[b]){
			for(int i = 0; i < 20; i++){
				if(differ & (1 << i)){cost+=sptle_cost[a][i]; a = sptle[a][i]; }
			}
		}
		else{
			for(int i = 0; i < 20; i++){
				if(differ & (1 << i)){cost+=sptle_cost[b][i]; b = sptle[b][i]; }
			}
		}
	}
	
    if (a != b)
    {
        for (int i = 19; i >= 0; i--)
        {
            if (sptle[a][i] != sptle[b][i])
            {	
				cost+=sptle_cost[a][i]; a = sptle[a][i]; 
                cost+=sptle_cost[b][i]; b = sptle[b][i]; 
            }
        }
        return cost += (sptle_cost[a][0] + sptle_cost[b][0]);
    }
	
	return cost;
}

int answer2(int a, int b){
	if(dep[a] != dep[b]){
		int differ = abs(dep[a] - dep[b]);
		if(dep[a] > dep[b]){
			for(int i = 0; i < 20; i++){
				if(differ & (1 << i)){a = sptle[a][i];}
			}
		}
		else{
			for(int i = 0; i < 20; i++){
				if(differ & (1 << i)){b = sptle[b][i];}
			}
		}
	}
	int lca;
    if (a != b)
    {
        for (int i = 19; i >= 0; i--)
        {
            if (sptle[a][i] != sptle[b][i])
            {	
				a = sptle[a][i]; 
                b = sptle[b][i]; 
            }
        }
    	return sptle[a][0];    
	}
	return a;

}



int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N-1; i++){
		int a,b,c;
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	dfs(0,0,1,0);
	make_sparsetable();
	int M;
	cin >> M;
	for(int i = 0; i < M; i++){
		int a,b,c,d;
		cin >> c;
		if(c == 1){
		cin >> a >> b;
			
		cout << answer1(a,b) << '\n';
		}
		else{
			cin >> a >> b >> d;
			int lca = answer2(a,b);
			int diff = dep[a] - dep[lca] + 1;
			if(diff == d){cout << lca << '\n';}
			else if(diff > d){
				d--;
				for(int i = 0; i < 20; i++){
					if(d & (1 << i)){a = sptle[a][i];}
				}
				cout << a << '\n';
			}
			else {
				diff = dep[a] - dep[lca] + dep[b] - dep[lca] + 1 - (d - 1) - 1;
			
				for(int i = 0; i < 20; i++){
					if(diff & (1 << i)){b = sptle[b][i];}
				}
				cout << b << '\n';
			}
		}
	}
	
	
}
*/
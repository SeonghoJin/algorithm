#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adj(10001,vector<int>());
int dep[10001];
int par[10001];
void precalc(int depth, int n){
	dep[n] = depth;
	for(int i = 0; i < adj[n].size(); i++){
		precalc(depth+1,adj[n][i]);
	}
}

int main(){
	int T;
	cin >> T;
	
	while(T--){
		int N;
		cin >> N;
		for(int i = 0; i <= N; i++){adj[i].clear();}
		fill(par,par+N+1,0);
		int a,b;
		for(int i = 0; i < N-1; i++){
			cin >> a >> b;
			adj[a].push_back(b);
			par[b] = a;
		}
		for(int i = 1; i <= N; i++){
			if(par[i] == 0){precalc(0,i); break;}
		}
		int x,y;
		cin >> x >> y;
		int dep_x = dep[x], dep_y = dep[y];
		while(dep_x != dep_y){
				if(dep_x > dep_y){x = par[x]; dep_x = dep[x];}
				else{y = par[y]; dep_y = dep[y];}
		}
		while(x != y){		
			x = par[x];
			y = par[y];
		}
		cout << x << '\n';
		
	}
}
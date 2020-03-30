/*
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int par[100001];
int dep[100001];
vector<int> adj[100001];
int sptle[100001][20];
int N;
	
int dfs(int depth, int parent, int n){
	par[n] = parent;
	dep[n] = depth;
	
	for(int i = 0; i < adj[n].size(); i++){
		if(adj[n][i] == parent)continue;
		dfs(depth+1,n,adj[n][i]);
	}
}

void make_sparsetable(){
	
	for(int i = 1; i <= N; i++){
		sptle[i][0] = par[i];
	}
	
	for(int i = 1; i < 20; i++){
		for(int j = 1; j <= N; j++){
			sptle[j][i] = sptle[sptle[j][i-1]][i-1];
		}
	}
	
}

int answer(int a, int b){
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
	
	cout << a << " " << b << '\n';
    if (a != b)
    {
        for (int i = 19; i >= 0; i--)
        {
            if (sptle[a][i] != sptle[b][i])
            {
				cout << i << "\n";
                a = sptle[a][i];
                b = sptle[b][i];
            }
 
        }
 
        return sptle[a][0];
 
    }
    
		
	
}



int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N-1; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0,1,1);
	make_sparsetable();
	int M;
	cin >> M;
	for(int i = 0; i < M; i++){
		int a,b;
		cin >> a >> b;
		cout << answer(a,b) << '\n';
		
	}
	
	
}*/
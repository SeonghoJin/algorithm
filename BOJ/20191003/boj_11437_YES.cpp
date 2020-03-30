/*
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N;

vector<int> adj[50001];
int sptle[50001][19];
int depth[50001];
void precalc(int n, int parent){
	sptle[n][0] = parent;
	depth[n] = depth[parent]+1;
	for(int i = 0; i < adj[n].size(); i++){
		if(parent == adj[n][i])continue;
		precalc(adj[n][i],n);
	}
}

void makesptle(){	
	for(int i = 1; i < 19; i++){
		for(int j = 1; j <= N; j++){
			sptle[j][i] = sptle[sptle[j][i-1]][i-1];
		}
	}
	
}

int LCA(int a, int b){
	if(depth[a] < depth[b]){int temp = a; a = b; b = temp;}
	
	int diff = depth[a]-depth[b];
	for(int i = 0; i < 19; i++){
		if(diff & (1 << i)){a = sptle[a][i];}
	}
	if(a != b){
		
		for(int i = 18; i >= 0; i--){
			if(sptle[a][i] != sptle[b][i]){
				
				a = sptle[a][i];
				b = sptle[b][i];
				
			}
		}
		a = sptle[a][0];
	}
	return a;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N-1; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	precalc(1,0);
	makesptle();
	int M;
	cin >> M;
	for(int i = 0; i < M; i++){
		int a,b;
		cin >> a >> b;
		cout << LCA(a,b) << '\n';
	}
	
	
}*/
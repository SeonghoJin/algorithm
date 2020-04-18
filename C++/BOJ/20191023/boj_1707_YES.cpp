#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[20001];

int V, E, visit[20001];

void makebipartite(){
	
	queue<pair<int,int>> q;
	
	for(int i = 1; i <= V; i++){
		if(visit[i] == 0){q.push({i,1});}
	while(!q.empty()){
		pair<int, int> temp = q.front(); q.pop();
		int num = temp.first;
		int group = temp.second;
		for(int i = 0; i < adj[num].size(); i++){
			int next = adj[num][i];
			if(visit[next] == 0){
				visit[next] = 3 - temp.second;
				q.push({next,visit[next]});
			}
		}
	}
	}
}

bool checkbipartite(){
	
	for(int i = 1; i <= V; i++){
		for(int j = 0; j < adj[i].size(); j++){
			int next = adj[i][j];
			
			if(visit[next] == visit[i])return false;
		}
	}
	return true;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--){
	cin >> V >> E;
	
	for(int i = 1; i <= V; i++){adj[i].clear();}
	fill(visit, visit+V+1, 0);
		
	for(int i = 0; i < E; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	makebipartite();
	cout << (checkbipartite() ? "YES" : "NO")<< '\n'; 
	}
}

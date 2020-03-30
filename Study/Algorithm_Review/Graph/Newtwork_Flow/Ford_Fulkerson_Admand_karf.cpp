#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 401;

int cap[MAX][MAX], flow[MAX][MAX];
int V, E;

int networkFlow(int source, int sink){
	
	int totalFlow = 0;
	
	while(1){
		
		vector<int> parent(V+1);
		queue<int> q;
		parent[source] = source;
		q.push(source);
		
		while(!q.empty() && !parent[sink] ){
			int here = q.front(); q.pop();
			
			for(int there = 1; there <= V; there++){
				if(cap[here][there] - flow[here][there] > 0 && !parent[there]){
					q.push(there);
					parent[there] = here;
				}
			}
			
		}
		
		if(!parent[sink])break;
		int fl = 987654321;
		
		for(int p = sink; p != source; p = parent[p])
			fl = min(cap[parent[p]][p] - flow[parent[p]][p], fl);
		
		for(int p = sink; p != source; p = parent[p]){
			flow[parent[p]][p] += fl;
			flow[p][parent[p]] -= fl;
		}
		
		totalFlow += fl;
		
	}
	
	return totalFlow;
}


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> V >> E;
	
	for(int i = 0; i < E; i++){
		int a, b;
		cin >> a >> b;
		cap[a][b] = 1;
	}
	
	cout << networkFlow(1,2);
	
}
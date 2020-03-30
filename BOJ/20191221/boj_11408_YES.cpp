#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 987654321;
int N, M;

int cap[802][802];
int flow[802][802];
int cost[802][802];
vector<int> adj[802];

void create_edge(int here, int next, int c){

	cap[here][next] = 1;
	cost[here][next] = c;
	cost[next][here] = -c;
	adj[here].push_back(next);
	adj[next].push_back(here);
}

pair<int, int> SPFA(int source, int tank){
	
	int total_fl = 0;
	int total_cost = 0;
	
	while(1){
		
		vector<int> dist(N+M+2, INF);
		vector<bool> Inq(N+M+2, 0);
		vector<int> pre(N+M+2, -1);
		
		queue<int> q; 
		q.push(source);
		Inq[source] = 1;
		pre[source] = 0;
		dist[source] = 0;
		
		while(!q.empty()){
			int here = q.front(); q.pop();
			Inq[here] = 0;
			
			for(int i = 0; i < adj[here].size(); i++){
				int next = adj[here][i];
				
				if(cap[here][next] - flow[here][next] > 0  && dist[here] + cost[here][next] < dist[next]){
					dist[next] = dist[here]+cost[here][next];
					pre[next] = here;
					if(!Inq[next]){
						Inq[next] = 1;
						q.push(next);
					}
				}
			}
		}
		
		if(pre[tank] == -1){break;}
		
		total_fl++;
		for(int n = tank; n != source; n = pre[n]){
			total_cost += cost[pre[n]][n];
			flow[pre[n]][n] += 1;
			flow[n][pre[n]] -= 1;
		}
		
	}
	
	return make_pair(total_fl, total_cost);
}


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++){
		int t;
		cin >> t;
		
		create_edge(0,i,0);
		for(int j = 0; j < t; j++){
			int a, b;
			cin >> a >> b;
			int next = a + N;
			create_edge(i,next,b);
			create_edge(next,N+M+1,0);
		}
		
	}
	
	pair<int,int> ans = SPFA(0,N+M+1);
	cout << ans.first << " " << ans.second;
	
}
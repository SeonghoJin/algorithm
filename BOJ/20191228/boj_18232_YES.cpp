/*#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int MAX = 300001;
vector<int> adj[MAX];
int visit[MAX];
int judge(int t){
	return t < 0 ? -1 : 1;
}
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int N, M, S, E;
	cin >> N >> M >> S >> E;
	
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	queue<int> q;
	visit[S] = 1;
	visit[E] = -1;
	q.push(S);
	q.push(E);
	
	int ans = 0;
	
	while(!q.empty() && ans == 0){
		int next = q.front(); q.pop();
		
		
		if(next - 1 > 0){
			
			if(visit[next-1] == 0){
			visit[next-1] = (visit[next] > 0 ? visit[next]+1 : visit[next]-1); 
			q.push(next-1);
			}
			else if(judge(visit[next]) * judge(visit[next-1]) < 0){
				
				ans = abs(visit[next]) + abs(visit[next-1]) - 1;
				break;
			}
		}
		if(next + 1 <= N){
			
			if(visit[next+1] == 0){
			visit[next+1] = visit[next] > 0 ? visit[next]+1 : visit[next] - 1;
			q.push(next+1);
			}
			else if(judge(visit[next]) * judge(visit[next+1]) < 0){
				ans = abs(visit[next]) + abs(visit[next+1]) - 1;
				break;
			}
		}
		
		for(int i = 0; i < adj[next].size(); i++){
			if(visit[adj[next][i]] == 0){
			visit[adj[next][i]] = visit[next] > 0 ? visit[next]+1 : visit[next] - 1;
			q.push(adj[next][i]);
			}
			else if(judge(visit[next]) * judge(visit[adj[next][i]]) < 0){
				ans = abs(visit[next]) + abs(visit[adj[next][i]]) - 1;
				break;
			}
		}
	}
	
	cout << ans;
	
}*/
/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 101;

typedef struct _edge{
	int cap, flow, there, rev;
	_edge(int there, int cap, int flow, int rev) : there(there), cap(cap), flow(flow), rev(rev) {}
}edge;

vector<edge> adj[MAX];
int level[MAX];
int work[MAX];
int mapping(char c){
	return c >= 'a' ? 26+(c-'a') : c-'A';
}

bool bfs(int source, int sink){
	fill(level, level+MAX, -1);
	
	queue<int> q;
	q.push(source);
	level[source] = 0;
	
	while(!q.empty()){
		int here = q.front(); q.pop();
		
		for(auto i : adj[here]){
			int there = i.there;
			
			if(level[there] == -1 && i.cap - i.flow > 0){
				level[there] = level[here]+1;
				q.push(there);
			}
			
		}
	}
	
	return level[sink] != -1; 
}

int dfs(int here, int cap, int sink){
	if(here == sink)return cap;
	
	for(int& i = work[here]; i < adj[here].size(); i++){
		int there = adj[here][i].there;
		
		if(level[here] - level[there] == -1 && adj[here][i].cap - adj[here][i].flow > 0){
			int fl = dfs(there, min(cap, adj[here][i].cap - adj[here][i].flow), sink);
			if(fl > 0){
				adj[here][i].flow += fl;
				adj[there][adj[here][i].rev].flow -= fl;
				return fl;
			}
		}
	}
	return 0;
}


int dinik(int source, int sink){
	int res = 0;
	
	while(bfs(source,sink)){
		fill(work,work+MAX, 0);
		
		while(1){
			int fl = dfs(source, 987654321, sink);
			if(fl == 0)break;
			res += fl;
		}
	}
	
	return res;
}
int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		char a,b;
		int f;
		cin >> a >> b >> f;
		int _a = mapping(a), _b = mapping(b);
		
		adj[_a].push_back({_b,f,0,(int)adj[_b].size()});
		adj[_b].push_back({_a,f,0,(int)adj[_a].size()-1});
	}
	
	cout << dinik(mapping('A'), mapping('Z'));
	
}*/
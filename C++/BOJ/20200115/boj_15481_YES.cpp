/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

using ll = long long;

const int MAX = 200001;

struct edge{
	
	ll w;
	int u, v;
	
	public : 
		edge(ll _w, int _u, int _v) : w(_w), u(_u), v(_v){
			
		}
	
		edge(){
			
		}
	
};

struct data{
	int n, d, pa, w;
	public :
		data(){
			
		}
		data(int _n ,int _w, int _pa, int _d) : n(_n), d(_d), pa(_pa), w(_w){
		};
	
		bool operator < (const data da) const{
			return this->w > da.w;
		}
};


int depth[MAX];

edge edges[MAX];
ll w_sptle[MAX][19];
ll sptle[MAX][19];
int visit[MAX];
vector<pair<int, int>> adjlist[MAX];
int N, M;
	

int lca(int u, int v){
	
	if(depth[u] < depth[v])swap(u,v);
	
	int diff = depth[u] - depth[v];
	
	for(int i = 0; i < 19; i++){
		if(diff & (1 << i)){
			u = sptle[u][i];
		}
	}
	
	if(u == v){return u;}
	else{
		for(int i = 18; i >= 0; i--){
			if(sptle[u][i] != sptle[v][i]){
				u = sptle[u][i];
				v = sptle[v][i];
			}
		}
	}
	
	return sptle[u][0];
}

ll getSecondMAX(int u, int v, int m){
	
	if(depth[u] < depth[v])swap(u,v);
	
	int diff = depth[u] - depth[v];
	
	int lca_node = lca(u,v);
	
	int u_lca = depth[u] - depth[lca_node];
	int v_lca = depth[v] - depth[lca_node];
	ll ret = -1;
	for(int i = 0; i < u_lca; i++){
		if(w_sptle[u][0] < m){
			ret = max(ret, w_sptle[u][0]);
		}
		u = sptle[u][0];
	}
	
	for(int i = 0; i < v_lca; i++){
		if(w_sptle[v][0] < m){
			ret = max(ret, w_sptle[v][0]);
		}
		v = sptle[v][0];
	}
	
	return ret;
}

	
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adjlist[a].push_back({b,c});
		adjlist[b].push_back({a,c});
		edges[i] = edge(c,a,b);
	}
	
	priority_queue<data> pq; //depth, parent
	
	pq.push(data(1,0,1,0));
	long long MST1 = 0;
	int cnt = 0;
	while(!pq.empty()){
		data temp = pq.top(); pq.pop();
		
		int here = temp.n;
		int weight = temp.w;
		int dep = temp.d;
		int par = temp.pa;
		if(visit[here])continue;
		visit[here] = 1;
			
		MST1 += weight;
		
		depth[here] = dep;
		sptle[here][0] = par;
		w_sptle[here][0] = weight;
		cnt++;
		for(auto next : adjlist[here]){
			if(visit[next.first])continue;
			pq.push(data(next.first, next.second, here, dep+1));
		}
		
	}
	
	if(cnt != N){
		cout << "AA";
		return 0;
	}
	
	for(int i = 1; i < 19; i++){
		for(int j = 1; j <= N; j++){
			sptle[j][i] = sptle[sptle[j][i-1]][i-1];
			w_sptle[j][i] = max(w_sptle[sptle[j][i-1]][i-1], w_sptle[j][i-1]);
		}
	}
	
	int ans = 0xffffffff/2 - 1;
		
	for(int i = 0; i < M; i++){
		int u = edges[i].u;
		int v = edges[i].v;
		int w = edges[i].w;
		
		
		int LCA = lca(u,v);
		long long _M = -1;
		
		int depth_U = depth[u] - depth[LCA];
		int depth_V = depth[v] - depth[LCA];
		
		for(int i = 0; i < 19; i++){
			if(depth_U & (1 << i)){
				_M = max(_M, w_sptle[u][i]);
				u = sptle[u][i];
			}
			if(depth_V & (1 << i)){
				_M = max(_M, w_sptle[v][i]);
				v = sptle[v][i];
			}
		}
		
		if(w > _M){
			if(ans > MST1 + w - _M){
				ans = MST1 + w - _M;
			}
		}
		else{
			_M = getSecondMAX(u,v,_M);
			if(_M != -1){
				if(ans > MST1 + w - _M){
					ans = MST1 + w - _M;
				}
			}
		}
		cout << _M << '\n';
		cout << ans;
		
	}
	
	
	
	
}
*/


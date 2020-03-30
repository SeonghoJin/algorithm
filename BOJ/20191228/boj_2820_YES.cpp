#include <iostream>
#include <vector>
using namespace std;

const int MAX = 500'001;

long long ft[MAX*2];
int cnt = 1;
vector<int> adj[MAX];

int l[MAX], r[MAX];

void update(int i, int v){
	
	while(i < cnt){
		ft[i] += v;
		i += (i & -i);
	}
	
}

long long sum(int i){
	
	long long ret = 0;
	
	while(i){
		ret += ft[i];
		i -= (i & -i);
	}

	return ret;
}

void dfs(int n, int p){
	
	l[n] = cnt++;
	
	for(auto next : adj[n]){
		if(next == p)continue;
		dfs(next, n);
	}
	
	r[n] = cnt++;
}

int cost[MAX];

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int N, M;
	cin >> N >> M >> cost[1];
	
	for(int i = 2; i <= N; i++){
		int a, b;
		cin >> a >> b;
		cost[i] = a;
		adj[b].push_back(i);
	}
	
	dfs(1,0);
	
	while(M--){
		char c;
		cin >> c;
		if(c == 'u'){
			int k;
			cin >> k;
			int li = l[k];
			cout << sum(li)+ cost[k] << '\n';
		}
		else{
			int a, b;
			cin >> a >> b;
			int li = l[a], ri = r[a];
			if(ri - li == 1)continue;
			else{
				update(li+1, b);
				update(ri, -b);
			}
			
		
		}
	}
	
}
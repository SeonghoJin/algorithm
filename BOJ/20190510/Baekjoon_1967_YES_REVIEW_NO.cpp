#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

static int N;
static int MaxNodeNumber=1;
static vector<vector<pair<int,int>>> tree(10001,vector<pair<int,int>>());
vector<bool> isvisit(10001,false);

static void input(){
	
	cin >> N;

	for(int i = 0; i < N-1; i++){
		int x,y,z;
		cin >> x >> y >> z;
		tree[x].push_back(make_pair(y,z));
		tree[y].push_back(make_pair(x,z));
		MaxNodeNumber=max(MaxNodeNumber,x);
	}
	
}

static int startNode = 1;
static int ans = 0;

static void dfs(int start, int length){
	
	if(isvisit[start]) return;
	isvisit[start]=true;
	if(length > ans){ 
	ans = length;
	startNode = start;				
	}
	
	for(int i = 0; i < tree[start].size(); i++){
		pair<int, int> child = tree[start][i];
		dfs(child.first,length+child.second);
	}
	isvisit[start]=false;
	
}


/*int main(){
	input();
	dfs(startNode,0);
	dfs(startNode,0);
	cout << ans;
}

#include <cstdio>
#include <vector>
#include <utility>
#include <unistd.h>
#define f(x) {x=0;while(1){if(ptr==buf+sz)syscall(0,0,ptr=buf,sz);if(*ptr<48)break;x=x*10+*ptr++-48;}ptr++;}
#define sz (1<<14)

int n, m, k;
std::vector<std::pair<int, int>> g[10001];
void dfs(int s, int p, int x) {
	for(auto[e, w] : g[s])
		if(e!=p)
			dfs(e, s, x+w);
	if(m<x)
		m=x, k=s;
}
int main() {
	char buf[sz],*ptr=buf+sz;
	f(n);
	while(--n) {
		int s, e, w;
		f(s); f(e); f(w);
		g[s].push_back({e, w});
		g[e].push_back({s, w});
	}
	dfs(1, 1, 0);
	dfs(k, k, 0);
	printf("%d", m);
}*/
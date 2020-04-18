#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<pair<int,int>>> Tree(100001,vector<pair<int,int>>());
vector<bool> isvisit(100001,false);
int ret = -987654321;
int N;
static int maxpoint = -1;

static bool backtraking(int a){
	for(int i = 0; i < Tree[a].size(); i++){
		pair<int, int> p1 = Tree[a][i];
		if(!isvisit[p1.first])return false;
	}
	return true;
}
static void input(){
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		
		int p;
		cin >> p;
		
		while(1){
			int t = -2;
			cin >> t;
			if(t==-1) break;
			int k;
			cin >> k;
			Tree[p].push_back(make_pair(t,k));
		}
	}
}

static void dfs(int a, int length){
	
	isvisit[a]=true;
	
	if(backtraking(a) && ret <= length){
		maxpoint = a;
		ret = length;
		
	}
	
	for(int i = 0; i < Tree[a].size(); i++){
		pair<int, int> p1 = Tree[a][i];
		if(!isvisit[p1.first]){
		length+=p1.second;
		dfs(p1.first,length);
		length-=p1.second;
		}
	}
	isvisit[a]=false;
	
}

static int treewidth(){
	
	
	
	dfs(1,0);
	dfs(maxpoint,0);
	return ret;
}


/*
int main(){
	
	input();
	
	cout << treewidth();
	
}

#include <cstdio>
#include <vector>
#include <utility>
#include <unistd.h>
#define f(x) {x=0;if(ptr==buf+sz)syscall(0,0,ptr=buf,sz);if(*ptr=='-'){ptr++;while(1){if(ptr==buf+sz)syscall(0,0,ptr=buf,sz);if(*ptr<48)break;x=x*10-*ptr+++48;}}else{while(1){if(ptr==buf+sz)syscall(0,0,ptr=buf,sz);if(*ptr<48)break;x=x*10+*ptr++-48;}}ptr++;}
#define sz (1<<16)

long m;
int n, k;
std::vector<std::pair<int, int>> g[100001];
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
	for(int i=0; i<n; i++) {
		int s, e, w; f(s);
		while(1) {
			f(e); if(e==-1) break; f(w);
			g[s].push_back({e, w});
		}
	}
	dfs(1, 1, 0);
	dfs(k, k, 0);
	printf("%ld", m);
}*/
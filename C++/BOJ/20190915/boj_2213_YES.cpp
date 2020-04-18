/*
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int weight[10001];
vector<int> adjlist[10001];
int visit[10001];
int dp[10001][2];
vector<int> v;
int N;

int dfs(int num, int colored){
	visit[num] = 1;
	
	int& ret = dp[num][colored];
	if(ret != -1)return ret;
	int cost = (colored == 1 ? weight[num] : 0); 
	ret = cost;
	
	int sz = adjlist[num].size();
	
	for(int i = 0; i < sz; i++){
		int nextnum = adjlist[num][i];
		if(visit[nextnum])continue;
		int a = dfs(nextnum,0);
		int b = (colored == 0 ? dfs(nextnum,1) : 0);
		ret += max(a,b);
		
	}
	
	visit[num] = 0;
	
	return ret;
}
int t_visit[10001] = {0,};

void trace(int num, int colored){
	t_visit[num] = 1;
	if(colored){
		v.push_back(num);
		for(int i = 0; i < adjlist[num].size(); i++){
			int next = adjlist[num][i];
			if(t_visit[next])continue;
			trace(next,0);
		}
	}
	else{
		for(int i = 0; i < adjlist[num].size(); i++){
			int next = adjlist[num][i];
			if(t_visit[next])continue;
			if(dp[next][1] >= dp[next][0]){
				trace(next,1);
			}
			else{
				trace(next,0);
			}
		}	
	}
	t_visit[num] = 0;
	
}

int main(){
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		cin >> weight[i];
	}
	for(int i = 0; i < 10001; i++){fill(dp[i],dp[i]+2,-1);}
	for(int i = 0; i < N-1; i++){
		int a,b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	
	int a = dfs(1,0);
	int b = dfs(1,1);
	cout << max(a,b) << '\n';
	trace(1,a > b ? 0 : 1);
	sort(v.begin(),v.end());
	for(auto it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	
	
}*/
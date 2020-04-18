/*
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int weight[10001], N;
vector<int> adjlist[10001];
int dp[10001][2];
int find(int par,int num, int state){
	
	int& ret = dp[num][state];
	if(ret != -1)return ret;
	ret = state*weight[num];
	
	for(int i = 0; i < adjlist[num].size(); i++){
		int next = adjlist[num][i];
		if(next == par)continue;
		if(state){ret+=find(num,next,0);}
		else if(state == 0){ret+=max(find(num,next,1),find(num,next,0));}
	}
	
	return ret;
}


int main(){
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		cin >> weight[i];
		fill(dp[i],dp[i]+2,-1);
	}
	for(int i = 0; i < N-1; i++){
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	
	cout << max(find(0,1,0),find(0,1,1));
	
}*/
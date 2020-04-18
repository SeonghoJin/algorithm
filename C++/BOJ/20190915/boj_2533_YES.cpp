/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 1000001;

vector<int> adjlist[MAX];
int dp[MAX][2];

int searchtree(int par,int num, int state){
	
	int& ret = dp[num][state];
	if(ret != -1)return ret;
	
	ret = state;
	
	for(int i = 0; i < adjlist[num].size(); i++){
		int next = adjlist[num][i];
		if(next == par)continue;
		if(state == 0){
			ret += searchtree(num,next,1);	
		}
		else{
			ret += min(searchtree(num,next,1),searchtree(num,next,0));	
		}
	}
	
	return ret;
}


int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	for(int i = 0; i < MAX; i++)fill(dp[i],dp[i]+2,-1);
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N-1; i++){
		int a, b;
		cin >> a >> b;
		adjlist[b].push_back(a);
		adjlist[a].push_back(b);
	}
	
	cout << min(searchtree(0,1,1),searchtree(0,1,0));
	
}*/
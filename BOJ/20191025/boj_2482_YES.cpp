/*
#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 1'000'000'003;
long long dp[2][1004][1004];
int N, K;
int temp = 0;
long long dfs(int t, int n, int k){
	if(k == 0)return 1;
	temp++;
	long long& ret = dp[t][n][k];
	if(ret != -1)return ret;
	
	ret = 0;
	int st = N-(1-t); 
	for(int i = n; i <= st; i++){
		ret += (dfs(t,i+2,k-1))%MOD;
		ret %= MOD;
	}
	
	return ret;
}

int main(){
	
	cin >> N >> K;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 1001; j++){
			fill(dp[i][j], dp[i][j]+1001,-1);
		}
	}
	cout << (dfs(0,3,K-1) + dfs(1,2,K))%MOD;
}*/
/*
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
unsigned long long K;
string ans;
unsigned long long k = 0;
unsigned long long Bi[202][202];

unsigned long long recur(int n, int r){
	
	if(n == r || r == 0){return Bi[n][r] = 1;}
	
	unsigned long long& ret = Bi[n][r];
	
	if(ret != -1)return ret;
	
	return ret = recur(n-1,r)+recur(n-1,r-1);
}

void precalc(){
	
	for(int i = 0; i < 202; i++)fill(Bi[i], Bi[i]+202,-1);
	
	for(int i = 0; i < 202; i++)
		for(int j = 0; j <= i; j++)
			recur(i,j);
	
	
}

void dfs(int n, int m, string s){
	
	if(n < 0 || m < 0)return;
	
	if(n == 0 && m == 0){
		k++;
		if(k == K){ans = s; }
		return;
	}
	
	unsigned long long next = (n ? Bi[n+m-1][n-1] : 0);
	if(next+k >= K)dfs(n-1,m,s+"a");
	else{k+=(next); dfs(n,m-1,s+"z");}	
}


int main(){
	
	cin >> N >> M >> K;
	precalc();
	
	if(Bi[N+M][N] >= K){
	dfs(N,M,"");
	}
	else ans = "-1";
	cout << ans;
}
*/
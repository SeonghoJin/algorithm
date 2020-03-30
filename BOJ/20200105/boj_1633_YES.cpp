#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int used[1001];
int team[2];
int w[1001];
int bl[1001];

int a, b;
int cnt = 0;

int dp[1001][16][16];

int f(int n, int _w, int _b){
	
	if(_w < 0 || _b < 0)return -987654321;
	if(n == cnt)return 0;
	
	int& ret = dp[n][_w][_b];
	if(ret != -1)return ret;
	
	ret = 0;
	
	ret = max(ret, f(n+1,_w-1,_b) + w[n]);
	ret = max(ret, f(n+1,_w,_b-1) + bl[n]);
	ret = max(ret, f(n+1,_w,_b));
	
	return ret;
}
	
int main(){
	
	while(scanf("%d %d", &a, &b) != EOF){
		w[cnt] = a;
		bl[cnt++] = b;
	}
	
	for(int i = 0; i < 1001; i++)
		for(int j = 0; j < 16; j++)
			for(int k = 0; k < 16; k++){dp[i][j][k] = -1;}
	
	cout << f(0,15,15);
}
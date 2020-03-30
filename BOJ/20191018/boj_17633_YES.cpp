#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int tmp = 4;
int N;

int dp[50000];
int dfs(){
	
	queue<pair<int,int>> q;
	q.push({N,0});
	
	while(!q.empty()){
		pair<int, int> temp = q.front(); q.pop();
		
		int v = temp.first;
		int a = temp.second;
		if(v == 0){tmp = min(tmp,a); break;}
		
		int k = sqrt(v);
		for(int i = k; i >= 1; i--){
			if(dp[v-i*i] == 0){
				dp[v-i*i] = 1;
				q.push({v-i*i,a+1});
			}
		}
		
	}
	
	return tmp; 
}

int main(){
	cin >> N;
	fill(dp,dp+50000, 0);
	dfs();
	cout << tmp;
}
/*
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int dp[501] = {0,};
int t[501] = {0,};
vector<vector<int>> need(501,vector<int>());

int N;

int buildtime(int num){
	
	if(need[num].empty()){
		return t[num];
	}
	
	int &ret = dp[num];
	if(ret!=0)return ret;
	ret = 0;
	for(int i = 0; i <need[num].size(); i++){
		ret=max(ret,buildtime(need[num][i]));
	}
	ret+=t[num];
	return ret;
}

int main(){
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		cin >> t[i];
		int w;
		cin >> w;
		while(w !=-1){
			need[i].push_back(w);
			cin >> w;
		}
	}
	
	for(int i = 1; i <= N; i++){
		fill_n(dp,0,N-1);
		cout << buildtime(i) << '\n';
	}
	
}*/
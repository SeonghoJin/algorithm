/*
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
vector<pair<int,int>> v;
vector<int> dp(101,0);

int main(){
	cin >> N;
	
	v.push_back(make_pair(0,0));
	for(int i = 0; i < N; i++){
		int a,b;
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}
	
	int twisted = 0;
	sort(v.begin(),v.end());
	
	int ret = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < i; j++){
			if((v[i].first > v[j].first) && (v[i].second > v[j].second)){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
		ret = max(ret,dp[i]);
	}
	
	for(int i = 1; i <= N; i++){
		cout << dp[i] <<endl;
	}
	cout << N-ret;
	

}*/
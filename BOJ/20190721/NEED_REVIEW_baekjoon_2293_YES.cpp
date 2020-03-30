/*
#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	int N,K;
	cin >> N >> K;
	
	vector<int> v;
	
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		if(a <= 10000)v.push_back(a);
	}
	
	vector<int> dp(K+1,0);
	
	dp[0] = 1;
	
	for(int i = 1; i <= v.size(); i++){
		for(int j = 0; j <= K; j++){
			cout << dp[j];
			if(j-v[i-1] >=0)
			dp[j] = dp[j]+dp[j-v[i-1]];
		}
		cout << endl;
	}
	for(int j = 1; j <= K; j++){
		cout << dp[j];
	}
	cout << endl;
	
	cout << dp[K];
}*/
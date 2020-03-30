/*
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int N , M;
	int Marr[101],Carr[101];
	int dp[101][10001] = {0,}; 
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++){
		cin >> Marr[i];
	}
	
	for(int i = 1; i <= N; i++){
		cin >> Carr[i];
	}
	
	
	for(int i = 1; i <= N; i++){
		for(int j = 0; j <= 10000; j++){
			if(j == Carr[i] && dp[i][j] == 0){dp[i][Carr[i]] = max(dp[i-1][Carr[i]],Marr[i]);}
			else if(dp[i-1][j] > 0){
				dp[i][j+Carr[i]] = max(dp[i][j+Carr[i]],dp[i-1][j]+Marr[i]);
				dp[i][j] = max(dp[i][j],dp[i-1][j]);
			}
		}
	}
	
	int answer = 987654321;
	for(int i = 0; i <= 10000; i++){
		if(dp[N][i] >= M)
		answer = min(answer, i);
	}
	
	cout << answer;
	
}*/
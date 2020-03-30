#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> worth(101);
vector<int> weight(101);
int N, K;

vector<vector<int>> dp(101,vector<int>(100001,-1));

int main(){
	
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++){
		cin >> weight[i] >> worth[i];
	}
	
	dp[0][0] = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= K; j++){
			if(dp[i][j] >= 0){
				dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
				if(j+weight[i+1]<=K){
					dp[i+1][j+weight[i+1]] = max(dp[i+1][j+weight[i+1]],dp[i][j]+worth[i+1]);
				}
			}
		}
		
	}
	
	int ret = 0;
	for(int i = 0; i <= K; i++){
		ret = max(ret,dp[N][i]);
	}
	cout << ret;
	
}
/*#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[51][500002];
int Arr[51];
int N;
int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	for(int i = 0; i < 51; i++)fill(dp[i], dp[i]+500002, -1);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)cin >> Arr[i];
	
	dp[0][0] = 0;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 500002; j++){
			if(dp[i][j] == -1)continue;
			
			int cnt = Arr[i+1];
			dp[i+1][j+cnt] = max(dp[i+1][j+cnt], dp[i][j]+cnt);
			dp[i+1][abs(j-cnt)] = max(dp[i+1][abs(j-cnt)], (j - cnt < 0 ? dp[i][j]+cnt-j:dp[i][j]));
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
		}
	}
	
	
	
	cout << (dp[N][0] == 0 ? -1 : dp[N][0]);
	
}*/
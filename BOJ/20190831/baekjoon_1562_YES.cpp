#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<long long>>> dp(101,vector<vector<long long>>(10,vector<long long>(1 << 10,0)));

int main(){
	
	int N;
	cin >> N;
	
	for(int i = 1; i <= 9; i++)dp[1][i][1 << i] = 1;
	
	for(int i = 2; i <= N; i++)
		for(int j = 0; j < 10; j++)
			for(int k = 0; k < 1024; k++){
				int bit = k | (1 << j);
				dp[i][j][bit] = dp[i][j][bit]%1000000000+((j > 0 ? dp[i-1][j-1][k] : 0)%1000000000 + (j < 9 ? dp[i-1][j+1][k] : 0)%1000000000)%1000000000;
			}
	
	long long answer = 0;
	
	for(int i = 0; i < 10; i++){
		answer+=(dp[N][i][1023]);
	}
	
	cout << answer%1000000000;
}
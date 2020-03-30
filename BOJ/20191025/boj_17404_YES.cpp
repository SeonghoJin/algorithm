#include <iostream>
/*
#include <cmath>

using namespace std;

int N;
int dp[3][1000][3];
int cost[1000][3];

int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N;
	int mi = 987654321;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < 3; j++)
			cin >> cost[i][j];
	
	
	for(int k = 0; k < 3; k++){
		dp[k][0][k] = cost[0][k];
		dp[k][0][(k+1)%3] = 987654321;
		dp[k][0][(k+2)%3] = 987654321;
		
		for(int i = 1; i < N; i++){
			for(int j = 0; j < 3; j++){
				dp[k][i][j] = min(dp[k][i-1][(j+1)%3],dp[k][i-1][(j+2)%3])+cost[i][j];
			}
		}
		
		for(int i = 0; i < 3; i++){
			if(k == i)continue;	
			mi = min(dp[k][N-1][i],mi);
		}
	}
	
	cout << mi;
	
}
*/
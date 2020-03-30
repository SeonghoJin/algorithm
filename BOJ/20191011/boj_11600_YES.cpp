#include <iostream>

using namespace std;

int map[1025][1025];
int dp[1025][1025];

int N, M;

int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++){cin >> map[i][j];
			dp[i][j] = dp[i-1][j]+dp[i][j-1]+map[i][j]-dp[i-1][j-1];
	}
	int a,b,c,d;
	for(int i = 0; i < M; i++){
	cin >> a >> b >> c >> d;
		cout << dp[c][d]-(dp[c][b-1]+dp[a-1][d])+dp[a-1][b-1] <<'\n';
	}
	
	
}
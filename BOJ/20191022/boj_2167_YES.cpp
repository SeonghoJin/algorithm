/*
#include <cstdio>

using namespace std;

int N, M;
int dp[301][301];
int main(){
	
	scanf("%d %d",&N, &M);
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++){
			int t;
			scanf("%d",&t);
			dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+t;
		}
	
	int T;
	scanf("%d",&T);
	while(T--){
		int a, b, c , d;
		scanf("%d %d %d %d",&a, &b, &c, &d);
		printf("%d\n", dp[c][d] - dp[c][b-1] - dp[a-1][d] + dp[a-1][b-1]);
	}
	
}*/
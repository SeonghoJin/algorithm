#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int n, dp[3][1001], ans = 1;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &dp[0][i]);
		dp[1][i] = dp[2][i] = 1;

		for (int j = 0; j < i; j++) {
			if (dp[0][j] < dp[0][i])
				dp[1][i] = max(dp[1][i], dp[1][j] + 1);
			
			if (dp[0][j] > dp[0][i]) {
				dp[2][i] = max(dp[2][i], dp[2][j] + 1);
				dp[2][i] = max(dp[2][i], dp[1][j] + 1);
			}
		}
		ans = max(ans, max(dp[1][i], dp[2][i]));
	}
	printf("%d", ans);
	return 0;
}
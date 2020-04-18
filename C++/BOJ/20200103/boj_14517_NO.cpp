#include <cstdio>
#include <cstring>
#define MOD 10007
char s[1002];
int dp[1001], psum[1001];

int main() {
	int len;
	scanf("%s", s + 1);
	len = strlen(s + 1);

	for (int i = 1; i <= len; i++)
		for (int j = i; j <= len; j++) {
			if (s[i] == s[j]) {
				dp[j] = (dp[j] + psum[len] - psum[j] + 1) % MOD;
				if (dp[j] < 0) dp[j] += MOD;
			}
			psum[j] = (psum[j - 1] + dp[j]) % MOD;
		}

	printf("%d", psum[len]);
}
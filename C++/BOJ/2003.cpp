#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, a[10001], sum[10001];

int go(int l, int r) {
	if (l > r) {
		return 0;
	}

	int j = l, ret = 0, sum = 0, m = (l+r)/2;
	for (int i = l; i <= r; i++) {
		sum += a[i];
		while (sum > k && j < m) {
			sum -= a[j];
			j++;
		}
		if (i >= m && sum == k) {
			ret++;
		}
	}

	ret += go(l, m-1) + go(m+1, r);

	return ret;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i-1]+a[i];
	}

	printf("%d\n", go(1, n));

	return 0;
}
/*
#include <stdio.h>

int n, m, i, k, ans, res;
bool chk[10];

int hi(int a) {
	int cnt = 0;
    if (!a && !chk[0]) return 1;
    while (a) {
		if (chk[a % 10]) return -1;
		a /= 10;
		cnt++;
	}
	return cnt;
}

int main() {
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) scanf("%d", &k), chk[k] = true;

	ans = n - 100;
	if (ans < 0) ans = -ans;
    for (i = n; i < 1111111; i++) {
		res = hi(i);
		if (res > 0) {
			res += i - n;
			ans = ans < res ? ans : res;
			break;
		}
	}
	for (i = n; i >= 0; i--) {
		res = hi(i);
		if (res > 0) {
			res += n - i;
			ans = ans < res ? ans : res;
			break;
		}
	}

	printf("%d", ans);

	return 0;
}*/
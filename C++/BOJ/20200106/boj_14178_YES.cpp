/*#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
int N, K;
int A[105][3];
int main() {
  scanf("%d %d", &N, &K);
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &A[i][j]);
    }
  }
	
  int res = 1 << 30;
	
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int k = 1; k <= N; k++) {
        int cnt = 0;
        for (int a = 1; a <= N; a++) {
          if (A[i][0] >= A[a][0] && A[j][1] >= A[a][1] && A[k][2] >= A[a][2]) {
          	cnt++;
          }
        }
        if (cnt >= K) {
          res = min(res, A[i][0] + A[j][1] + A[k][2]);
        }
      }
    }
  }
	
  printf("%d\n", res);
	
  return 0;
}*/
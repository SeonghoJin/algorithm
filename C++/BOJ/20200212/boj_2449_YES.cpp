#include <bits/stdc++.h>

using namespace std;

int Arr[200];
int dp[200][200];
int N, K;

int f(int i, int j){
	if(i == j)return (Arr[i] != Arr[j]);
	
	int& ret = dp[i][j];
	if(ret != -1)return ret;
	ret = 987654321;
	for(int a = i; a < j; a++){
		ret = min(ret, f(i, a) + f(a+1, j) + (Arr[i] != Arr[a+1]));
	}
	return ret;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N >> K;
	for(int i = 0; i < N; i++)cin >> Arr[i];
	
	for(int i = 0; i < 200; i++)
		fill(dp[i], dp[i]+200, -1);
	
	cout <<	f(0,N-1);

	
}

/*

이 부분에서 생각해야 할 것은 왜 구간 i .. j 의 전구의색 을 통일 시킬때 i 의 색깔로 통일해도 최적인가?
생각읋 해보자. 

ex 1) abba 을 생각해보면 왼쪽파티션과 오른쪽파티션이 서로 영향을 줄 경우의 수가 생기나, 어차피 사장되는 경우의수이기때문에 정상적으로 답은 나온다. 
ex 2) 생각해보면 이 점화식은 모든 경우의 수를 따지게 된다. 즉 완전탐색과 비슷하다는 뜻이다. 



*/
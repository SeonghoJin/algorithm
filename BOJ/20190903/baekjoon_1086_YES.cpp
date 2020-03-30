#include <iostream>

using namespace std;

long long factorial(int k){
	
	long long ret = 1;
	for(int i = 1; i <= k; i++)ret*=i;
	
	return ret;
}

long long gcd(long long a, long long b){
	return b ? gcd(b,a%b) : a;
}

long long dp[1 << 15][101];

int main(){
	
	int N, K, size[16], pow10[52], ModArr[16];
	string Arr[16];
	cin >> N;
	for(int i = 0; i < N; i++){cin >> Arr[i]; size[i] = Arr[i].size();}
	cin >> K;
	pow10[0] = 1;
	for(int i = 0; i < 51; i++)pow10[i+1] = (pow10[i]*10)%K;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < size[i]; j++){
			ModArr[i] = (ModArr[i]*10 + Arr[i][j]-'0')%K;
		}
	}
	
	dp[0][0] = 1;
	for(int i = 0; i < ( 1<< N)-1; i++){
		for(int j = 0; j < N; j++){
			if(i & (1 << j))continue;
			for(int k = 0; k < K; k++){
				if(dp[i][k] == 0)continue;
				int bit = i | ( 1 << j);
				int r_new = (k*pow10[size[j]] + ModArr[j])%K;
				dp[bit][r_new] +=dp[i][k];
			}
		}
	}
	
	long long _fac = factorial(N);
	long long _ret = dp[(1 << N)-1][0];
	long long _gcd = gcd(_fac,_ret);
	cout << _ret/_gcd << '/' << _fac/_gcd;
	
}
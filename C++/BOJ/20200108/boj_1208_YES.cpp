/*#include <iostream>
#include <map>
using namespace std;
const int T = 2'000'000;
int m[2][5'000'001];
int Arr[51];
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	int N, S;
	cin >> N >> S;
	for(int i = 0; i < N; i++)cin >> Arr[i];
	int l = N/2;
	int r = N - N/2;
	
	for(int i = 1; i < (1 << l); i++){
		int v = 0;
		for(int j = 0; j < l; j++){
			if(i & (1 << j))v+= Arr[j];
		}
		m[0][v+ T]++;
	}
	
	for(int i = 1; i < (1 << r); i++){
		int v = 0;
		
		for(int j =0; j < r; j++){
			if(i & (1 << j))v+= Arr[l+j];
		}
		m[1][v + T]++;
	}
	long long ans = 0;
	ans = m[0][S+T] + m[1][S+T];
	
	for(int i = -2'000'000; i <= 2'000'000; i++){
		int p = S - i + T;
		ans += 1LL * m[0][i+T] * m[1][p];
	}
	
	cout << ans;
	
}*/
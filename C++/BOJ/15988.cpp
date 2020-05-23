#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 1'000'001;
const int MOD = 1'000'000'009;
ll Arr[MAX];

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	int T;
	cin >> T;
	Arr[1] = 1;
	Arr[2] = 2;
	Arr[3] = 4;

	for(int i = 4; i <= MAX; i++){
		Arr[i] = Arr[i-1] + Arr[i-2] + Arr[i-3];
		Arr[i] %= MOD;
	}
	while(T--){
		int N;
		cin >> N;
		cout << Arr[N] << '\n';
	}
}
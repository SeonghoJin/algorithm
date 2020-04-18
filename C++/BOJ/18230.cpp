#include <bits/stdc++.h>

using namespace std;

vector<long long> a;
vector<long long> b;


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	long long N, A, B;
	cin >> N >> A >> B;

	for(long long i = 0; i < A; i++){
		long long temp;
		cin >> temp;
		a.push_back(temp);
	}	
	for(long long i = 0; i < B; i++){
		long long temp;
		cin >> temp;
		b.push_back(temp);
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	for(long long i = 0; i < A-1; i++)a[i+1] += a[i];
	for(long long j = 0; j < B-1; j++)b[j+1] += b[j];
	long long t = min(N,A);
	long long ans = 0;
	for(long long i = 0; i <= t; i++){
		long long k = N - i;
		if(k & 1)continue;
		if((k/2)-1 >= b.size())continue;
		ans = max(ans, (i == 0 ? 0 : a[i-1]) + (k/2 == 0 ? 0 : b[(k/2)-1]));
	}
	cout << ans;
	
}
	



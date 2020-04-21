#include <bits/stdc++.h>

using namespace std;

const long long MAX = 2*10e5+1;


	

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	long long T;
	cin >> T;

	while(T--){
		long long N;
		cin >> N;
		vector<long long> v;
		for(long long i = 0; i < N; i++){
			long long a; cin >> a;
			v.push_back(a);
		}

		bool f = v[0] > 0;
		long long temp = -10e9-100;
		long long ans = 0;
		for(long long i = 0; i <= N; i++){
			if(i == N){
				ans += temp;
				break;
			}
			if(f && v[i] < 0){
				ans += temp;
				temp = v[i];
				f = false;
			}
			else if(f && v[i] > 0){
				temp = max(temp, v[i]);
			}
			else if(f == false && v[i] > 0){
				ans += temp;
				f = true;
				temp = v[i];
			}
			else{
				temp = max(temp, v[i]);
			}
		}
		cout << ans << '\n';
	}

	
	
}
	



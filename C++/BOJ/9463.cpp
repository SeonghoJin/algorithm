#include <bits/stdc++.h>

using namespace std;

long long sz;
void update(vector<long long>& v, long long n){

	while(n <= sz){
		v[n]+=1;
		n += (n & -n);
	}

}

long long sum(vector<long long>& v, long long n){
	long long ans = 0;
	while(n){
		ans+=v[n];
		n -= (n & -n);
	}
	return ans;
}


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	long long T;
	cin >> T;
	while(T--){
		
		cin >> sz;

		vector<long long> v1(sz+1),v2(sz+1),v3(sz+1);
		for(long long i = 1; i <= sz; i++){
			cin >> v1[i];
		}
		
		for(long long i = 1; i <= sz; i++){
			cin >> v2[i];
			v3[v2[i]] = i;
		}

		for(long long i = 1; i <= sz; i++){
			v1[i] = v3[v1[i]];
			
		}



		vector<long long> fenwik(100000+1,0);
		long long ans = 0;
		for(long long i = 1; i <= sz; i++){
			long long cur = v1[i];
			ans +=(sum(fenwik,sz)-sum(fenwik,cur));
			update(fenwik,cur);
		}
		cout << ans << '\n';
	}
}
	
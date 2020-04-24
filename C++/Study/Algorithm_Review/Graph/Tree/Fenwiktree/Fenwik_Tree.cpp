#include <bits/stdc++.h>

using namespace std;

int sz;
void update(vector<int>& v, int n){

	while(n <= sz){
		v[n]+=1;
		n += (n & -n);
	}

}

int sum(vector<int>& v, int n){
	int ans = 0;
	while(n){
		ans+=v[n];
		n -= (n & -n);
	}
	return ans;
}


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int T;
	cin >> T;
	while(T--){
		
		cin >> sz;

		vector<int> v1,v2,v3(sz);
		for(int i = 0; i < sz; i++){
			int a;
			cin >> a;
			v1.push_back(--a);
		}
		
		for(int i = 0; i < sz; i++){
			int a;
			cin >> a;
			v2.push_back(--a);
			v3[a] = i;
		}

		for(int i = 0; i < sz; i++){
			v1[i] = v3[v1[i]];
			cout << v1[i] << " ";
		}

		vector<int> fenwik(100000+1,0);
		int ans = 0;
		for(int i = 0; i < sz; i++){
			
		}

	}
}
	
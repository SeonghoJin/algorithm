#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 2*10e5+1;
 
 
	
 
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int T;
	cin >> T;
 
	while(T--){
		long long k;
		cin >> k;
 
		int i = 2;
		
		while(1){
			long long p = (1 << i) - 1;
			if(k%p == 0){
				cout << k/p << '\n';
				break;
			}
			i++;
		}
 
	}
	
	
}
	
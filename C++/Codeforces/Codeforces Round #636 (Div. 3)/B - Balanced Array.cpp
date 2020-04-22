#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 2*10e5+1;
 
 
	
 
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int T;
	cin >> T;
 
	while(T--){
		int a;
		cin >> a;
		if((a/2) & 1){
			cout << "NO" << '\n';
		}
		else{
			cout << "YES" << '\n';
			int len = a/2;
			int sum = 0;
			for(int i = 1; i <= len; i++){
				cout << 2*i << " ";
				sum+= 2*i;
			}
 
			for(int i = 1; i < len; i++){
				cout << 2*i - 1 << " ";
				sum -= (2*i - 1);
			}
			cout << sum << '\n';
		}
	}
	
	
}
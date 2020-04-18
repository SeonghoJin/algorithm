#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 200002;

int Z[MAX], l, r;
string s;
int N, K;
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> N >> K;
	
	cin >> s;
	int sz = s.size();
	
	Z[0] = sz;
	
	for(int i = 1; i < sz; i++){
		if(i > r){
			l = r = i;
			while(r < sz && s[r-l] == s[r])r++;
			Z[i] = r-- - l;
		}
		else{
			if(i + Z[i - l] -1 < r){
				Z[i] = Z[i - l];
			}
			else{
				l = i;
				while(r < sz && s[r - l] == s[r])r++;
				Z[i] = r-- -l;
			}
		}
	}
	
	if(N <= K){
		cout << N;
	}
	else{
		
		int len = -1;
		
		for(int i = 1; i < sz; i++){
			if(sz - Z[i] == i){
				len = i;
				break;
			}
		}
		
		if(len == -1){
			cout << "0";
		}
		else{
			
			int lo = N/len;
			int up = (N+K)/len;
			int ans = -1;
			for(int i = lo; i <= up; i++){
				if(i*len < N)continue;
				
				int temp = sqrt(i);
				int j = 2;
				for(j = 2; j <= temp; j++){
					if(i%j == 0){
						ans = max(ans, (i/j)*len);
						break;
					}
				}
				if(j == temp+1){
					ans = max(ans, len);
				}
			}
			
			cout << (ans == -1 ? 0 : ans);
			
		}
		
	}

	
}
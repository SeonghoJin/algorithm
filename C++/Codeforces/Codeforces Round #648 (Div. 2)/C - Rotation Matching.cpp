#include <bits/stdc++.h>
 
using namespace std;
int m[200001];
int k[200001];
int idx[200001];
int ans[200001];
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
 
	int sz;
	cin >> sz;
	
	for(int i = 0; i < sz; i++){
		cin >> m[i];
		idx[m[i]] = i;
	}
 
	for(int i = 0; i < sz; i++){
		cin >> k[i];
		int curidx = idx[k[i]];
		if(curidx >= i){
			ans[curidx-i]++;	
		}
		else{ans[sz-i+curidx]++;
		}
	}
 
	int answer = 0;
	
	for(int i = 0; i < 200001; i++){
		answer = max(answer, ans[i]);
	}
 
	cout << answer;
}
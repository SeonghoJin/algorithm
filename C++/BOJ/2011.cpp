#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[5001];
const int MOD = 1'000'000;


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	string s;
	cin >> s;

	if(s[0] > '0')dp[0]= 1;
	if(s.size() > 1 && s[1] > '0')dp[1]+=dp[0];
	if(s.size() > 1 &&  s[0] > '0' && (s[0] < '2' || (s[0] <= '2' && s[1] <= '6')))dp[1]++;

	for(int i = 2; i < s.size(); i++){
		if(s[i] > '0'){dp[i]+=dp[i-1];}
		if(s[i-1] > '0' && (s[i-1] < '2' || (s[i-1] <= '2' && s[i] <= '6')))dp[i]+=dp[i-2];
		dp[i] %= MOD;
	}
	for(int i = 0; i < s.size(); i++){
		cout << dp[i] << " ";
	}
	cout << dp[s.size()-1]%MOD;	
}
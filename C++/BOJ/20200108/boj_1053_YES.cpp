#include <iostream>
#include <algorithm>

using namespace std;

int dp[51][51];
string s;

void ff(){
	for(int i  = 0;i  < 51; i++)fill(dp[i], dp[i]+51, -1);
}
int f(int l, int r){
	if(l == r)return 0;
	if(r - l == 1)return s[l] == s[r] ? 0 : 1;
	
	int& ret = dp[l][r];
	if(ret != -1)return ret;
	
	ret = 987654321;
	
	ret = min({ret, f(l,r-1)+1, f(l+1,r)+1,f(l+1,r-1) + 1 - (s[l] == s[r])});
	
	return ret;
}

int main(){
	string str;
	cin >> str;
	
	int ans = 987654321;
	int sz = str.size();
	ff();
	s = str;
	ans = min(ans, f(0,sz-1));
	for(int i = 0; i < sz; i++){
		for(int j = i + 1; j < sz; j++){
			ff();
			string st = str;
			swap(st[i],st[j]);
			s = st;
			ans = min(ans,f(0,sz-1)+1);
		}
	}
	cout << ans;
}
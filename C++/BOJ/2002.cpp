#include <bits/stdc++.h>

using namespace std;
map<string, pair<int,int>> m;
string s[1001];
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	int N;
	cin >> N;
	int cur = 0;
	for(int i = 0; i < N; i++){
		string str;
		cin >> str;
		s[i] = str;
		m[str] = {cur++,0};
	}
	cur = 0;
	int ans = 0;
	for(int j = 0; j < N; j++){
		string str;
		cin >> str;

		if(m[str].first == cur){
			m[str].second = 1;
			while(m[s[cur]].second){
				cur++;
			}
		}
		else{
			ans++;
			m[str].second = 1;
		}
	}
	cout << ans;
}
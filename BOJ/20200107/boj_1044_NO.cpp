
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
const ll MAX = 0xFFFFFFFFFFFFFFF/2 - 1;

int N;

ll team[2][40];

map<ll, ll> m[40][2];


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N;
	
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < N; j++)
			cin >> team[i][j];
	

	for(int i = 0; i < N; i++)team[1][i] *= -1;
	
	int l = N/2;
	int r = (N+1)/2;
	
	for(int i = 0; i < 2; i++){
		
		int len = (i ? r : l);
		
		for(int j = 0; j < (1 << len); j++){
			
			ll val = 0;
			int c = 0;
			for(int k = 0; k < len; k++){
				
				int f = (j & (1 << (len - k - 1)) ? 1 : 0);
				val += team[f][k + (i ? l : 0)];
				if(f)c++;
			}
			if(m[c][i].find(val) != m[c][i].end())continue;
			else{
				m[c][i][val] = j;
			}
		}
		
	}
	
	
	pair<ll, ll> ans = {MAX,MAX};
	
	for(int i = 0; i <= N/2; i++)
		for(auto it = m[i][0].begin(); it != m[i][0].end(); it++){
			auto target = -(it->first);
			
			if(m[N/2 - i][1].size() == 0)continue;
			
			auto it2 = m[N/2 - i][1].lower_bound(target);
			
			if(it2 != m[N/2-i][1].end()){
				 ans = min(ans, {abs((*it).first+(*it2).first), ((*it).second << (N/2)) | (*it2).second});
			}
			if(it2 != m[N/2-i][1].begin()){
				--it2;
				  ans = min(ans, {abs((*it).first+(*it2).first), ((*it).second  << (N/2)) | (*it2).second});
			}
		}
	
	auto bit = ans.second;
    for(int i = 0; i < N; i++)printf("%c ","12"[bit&(1ll<<N-1-i)?1:0]);

	
}




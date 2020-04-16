#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> vpii;

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.second < b.second;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	int N;
	int T;
	cin >> N >> T;
	int m_k;
	int m_v = 101; 
	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		vpii.push_back({a,b});
	}

	sort(vpii.begin(),vpii.end(), cmp);
	for(int i = 0; i < N; i++){
	int a = vpii[i].first;
	int b = vpii[i].second;
	if(m_v >= b){
			if(m_v == b){
				if(vpii[m_k].first < a){
					m_k = i;
				}
			}
			else{
				m_v = b;
				m_k = i;
			}
		}
	}
	long long ans = 0;
	
	long long start = T-N;
	for(int i = 0; i < N; i++){
		ans += (long long)vpii[i].first + 1LL * (start++)*vpii[i].second;
	}
	cout << ans;	
}
	



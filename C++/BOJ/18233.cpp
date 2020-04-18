#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> vpii;


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	int N, P, E;
	cin >> N >> P >> E;
	vector<pair<int,int>> arr;
	for(int i = 0; i < N; i++){
		int a,b;
		cin >> a >> b;
		arr.push_back({a,b});
	}
	bool flag = false;
	for(int i = 0; i < (1 << N); i++){
		int t = 0;
		for(int j = 0; j < N; j++){
			if((1 << j) & i)t++;
		}
		if(t == P){
			int K = E;
			vector<int> v(N,0);

			for(int j = 0; j < N; j++){
				if((1 << j) & i){
					v[j] += arr[j].first;
					K-=arr[j].first;
				}
			}
			if(K < 0)continue;

			for(int j = 0; j < N; j++){
				if((1 << j) & i){
					int t = min(arr[j].second-arr[j].first,K);
					v[j] += t;
					K-=t;
				}				
			}
			if(K == 0){
				flag = true;
				for(int j = 0; j < N; j++){
					cout << v[j] << " ";			
				}
				break;
			}
		}
	}
	if(flag == false)cout << -1;
}
	



#include <bits/stdc++.h>

using namespace std;

const long long MAX = 2*10e5+1;

int arr[251][251];	
	

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int N, M;
	cin >> N >> M;

	vector<pair<int,int>> adjlist[251];

	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		/*
		arr[a][b] = 1;
		if(c)arr[b][a] = 1;
	*/
		adjlist[a].push_back({b,0});
		if(c){
			adjlist[b].push_back({a,0});
		}
		else{
			adjlist[b].push_back({a,1});
		}
	}
	/*
	for(int k = 0; k < N; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				arr[i][j] = (arr[i][k] && arr[k][j]);
			}
		}
	}

*/	
	int ans[251][251];
	for(int i = 1; i <= N; i++){

		priority_queue<pair<int,int>> q;
		q.push({0,i});
		vector<int> dist(251,987654321);
		dist[i] = 0;
		while(!q.empty()){
			pair<int,int> here = q.top(); q.pop();
			if(dist[here.second] < -here.first)continue;

			for(pair<int,int> next : adjlist[here.second]){
				int c = next.second + -here.first;
				int n = next.first;

				if(dist[n] > c){
					dist[n] = c;
					q.push({-c,n});
				}
			}
		}

		for(int j = 1; j <= N; j++){
			ans[i][j] = dist[j];
		}
	}
	int T;
	cin >> T;

	while(T--){
		int a, b;
		cin >> a >> b;
		cout << ans[a][b] << '\n';
	}
	
	
	
}
	



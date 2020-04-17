#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	int T;
	cin >> T;

	while(T--){
		int N, M, W;
		cin >> N >> M >> W;

		vector<pair<int,int>> adjlist[501];
		for(int i = 0; i < M; i++){
			int a, b, c;
			cin >> a >> b >> c;
			--a; --b;
			adjlist[a].push_back({b,c});
			adjlist[b].push_back({a,c});
		}

		for(int i = 0; i < W; i++){
			int a, b, c;
			cin >> a >> b >> c;
			--a; --b;
			adjlist[a].push_back({b,-c});
		}
		
		vector<int> visit(N,0);
		bool flag = false;
		for(int t = 0; t < N; t++){
			if(visit[t])continue;
			vector<int> dist(N+1,INF);
			dist[t] = 0;
			visit[t] = 1;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(dist[j] == INF)continue;
				visit[j] = 1;
				for(int k = 0; k < adjlist[j].size(); k++){
					int next = adjlist[j][k].first;
					int d = adjlist[j][k].second; 
					if(dist[next] > dist[j] + d){
						dist[next] = dist[j] + d;
						if(i == N-1)flag = true;
					}

				}

			}
		}
		}
		if(flag)cout << "YES" << '\n';
		else{cout << "NO" << '\n';
		}

	}
}
	



#include <bits/stdc++.h>

using namespace std;


const int INF = 987654321*2;

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);	
	
	int N, M;
	vector<pair<int,int>> v[101];
	vector<int> id[101];
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v[a-1].push_back({b-1,-c});
		id[b-1].push_back(a-1);
	}

	
	
	queue<int> q;
	vector<int> visit(N,0);
	q.push(N-1);
	visit[N-1] = 1;
	while(!q.empty()){
		int here = q.front(); q.pop();
		
		for(int i = 0; i < id[here].size(); i++){
			int next = id[here][i];
			if(visit[next])continue;
			visit[next] = 1;
			q.push(next);
		}
	}

	
	
	
	
	bool flag = false;
	vector<int> cost(N, INF);
	vector<int> dp(N,-1);
	cost[0] = 0;
	

	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(cost[j] == INF)continue;
			int here = j;
			for(int k = 0; k < v[j].size(); k++){
				int next = v[here][k].first;
				int c = v[here][k].second;

				if(cost[here] + c < cost[next]){
					cost[next] = cost[here] + c;
					dp[next] = here;
					if(i == N-1 && visit[next])flag = true;
				}
			}
		}
	}
	if(flag || cost[N-1] == INF){
		cout << -1;
	}
	else {
		int end = N-1;
		stack<int> s;

		while(end != -1){

			s.push(end);
			end = dp[end];
		}
	
		while(!s.empty()){
			cout << s.top()+1 << " ";
			s.pop();
		}

	}
	

}
	



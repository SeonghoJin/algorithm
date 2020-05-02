#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<int> ind(10000+1);
vector<vector<pair<int,int>>> adj(10000+1,vector<pair<int,int>>());
vector<vector<pair<int,int>>> inadj(10000+1,vector<pair<int,int>>());
vector<vector<int>> check(10000+1,vector<int>());
vector<int> ans(10000+1,0);
vector<int> visit(10000+1, 0);
int main()
{
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	
	cin >> N >> M;
	int start, end;

	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
		inadj[b].push_back({a,c});
		check[b].push_back(0);
		ind[b]++;
	}

	cin >> start >> end;
	
	queue<int> q;

	q.push(start);
	ans[start] = 0;
	int can = 0;
	
	while(!q.empty()){
		int here = q.front(); q.pop();
		//cout << here << " " << ans[here].first << " " << ans[here].second << '\n';
		if(ans[here] >= can){
			can = ans[here];
		}
		//cout << "IN" << '\n';
		for(pair<int,int> temp : adj[here]){
			int next = temp.first;
			int cost = temp.second;

			if(ans[next] <= ans[here] + cost){
				ans[next] = ans[here] + cost;
			}
			ind[next]--;
			if(ind[next] == 0){
				q.push(next);
			}
		}
		//cout << '\n';
	}
	
	q.push(end);
	
	while(!q.empty()){
		int here = q.front(); q.pop();

		for(int i = 0; i < inadj[here].size(); i++){
			int next = inadj[here][i].first;
			int cost = inadj[here][i].second;
			if(ans[here] - cost == ans[next]){
				check[here][i] = 1;
				if(visit[next] == 0){
					visit[next] = 1;
					q.push(next);
				}
			}
		}		
	}

	int sum = 0;

	for(int i = 1; i <= N; i++){
		for(int j = 0; j < check[i].size(); j++){
			sum += check[i][j];
		}
	}

	cout << ans[end] << " " << sum;
}
#include <bits/stdc++.h>

using namespace std;

int N, M;
string str[51];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
pair<int,int> parent[51][51];
pair<int,int> find(pair<int,int> i){return (parent[i.first][i.second] == i ? i : parent[i.first][i.second] = find(parent[i.first][i.second]));}
bool Union(pair<int,int> a, pair<int,int> b){
	pair<int,int> pa = find(a);
	pair<int,int> pb = find(b);
	if(pa == pb)return false;
	parent[pa.first][pa.second] = pb; 
	return true;
}

void pprint(pair<int,int> t){
	cout << t.first << " " << t.second << '\n';
}
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	cin >> N >> M;
	for(int i = 0; i < N; i++)cin >> str[i];

	vector<pair<int,int>> p;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(str[i][j] == 'K' || str[i][j] == 'S')p.push_back({i,j});
			parent[i][j] = {i,j};
		}
	}
	priority_queue<pair<int,pair<pair<int,int>,pair<int,int>>>> pq;

	for(int i = 0; i < p.size(); i++){
		pair<int,int> start = p[i];
		
		queue<pair<int,int>> q;
		vector<vector<int>> visit(51,vector<int>(51,-1));
		q.push(start);
		visit[start.first][start.second] = 0;
		while(!q.empty()){
			pair<int,int> temp = q.front(); q.pop();
			int y = temp.first;
			int x = temp.second;
			for(int i = 0; i < 4; i++){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(nx >= 0 && nx < N && ny >= 0 && ny < N && str[ny][nx] != '1' && visit[ny][nx] == -1){
					visit[ny][nx] = visit[y][x] + 1;
					q.push({ny,nx});
				}
			}
		}
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				//cout << visit[i][j] << " ";
				if((str[i][j] == 'K' || str[i][j] == 'S') && visit[i][j] != -1){
					pq.push({-visit[i][j],{start,{i,j}}});
				}
			}
		//	cout << '\n';
		}
		//cout << '\n';

	}

	int K = 0;
	int ans = 0;
	while(K != M && !pq.empty()){
		pair<int,pair<pair<int,int>,pair<int,int>>> temp = pq.top(); pq.pop();

		pair<int,int> here = temp.second.first;
		pair<int,int> next = temp.second.second;

		int cost = temp.first;
		if(Union(here,next)){
			
			K++;
			ans+=-cost;
		}
	}

	if(K == M)cout << ans;
	else{cout << -1;}	
}
	



#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
int N, M;
string m[51];
int check[51][51];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
int sy, sx;
int ty, tx;

void precalc(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(m[i][j] == '.'){
				for(int k = 0; k < 4; k++){
					int ny = i + dy[k];
					int nx = j + dx[k];
					if(ny >= 0 && ny < N && nx >= 0 && nx < M && m[ny][nx] == 'g'){
						check[i][j] = 1;
					}
				}
			}
			if(m[i][j] == 'S'){
				sy = i;
				sx = j;
			}
			if(m[i][j] == 'F'){
				ty = i;
				tx = j;
			}
		}
	}
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	cin >> N >> M;

	for(int i = 0; i < N; i++){
		cin >> m[i];
	}

	precalc();

	priority_queue<pair<pii,pii>,vector<pair<pii,pii>>, greater<pair<pii,pii>>> pq;
	
	pq.push({{0,check[sy][sx]},{sy,sx}});
	vector<vector<pii>> path(51,vector<pii>(51,{987654321, 987654321}));
	int count = 0;
	while(!pq.empty()){
		pair<pii,pii> temp = pq.top(); pq.pop();
		int y = temp.second.first;
		int x = temp.second.second;
		pii cost = temp.first;
		if(cost.first > path[y][x].first)continue;
		if(cost.first == path[y][x].first && cost.second >= path[y][x].second)continue;
		path[y][x] = {cost.first,cost.second};
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(ny < 0 || ny >= N || nx < 0 || nx >= M)continue;
			int a = m[ny][nx] == 'g';
			int b = check[ny][nx];

			if(cost.first + a > path[ny][nx].first)continue;
			if(cost.first + a == path[ny][nx].first && cost.second + b > path[ny][nx].second)continue;

			pq.push({{cost.first+a,cost.second+b},{ny,nx}});
		}
	}
	
	cout << path[ty][tx].first << " " << path[ty][tx].second;

	
}
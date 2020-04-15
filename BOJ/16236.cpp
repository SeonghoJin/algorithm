#include <bits/stdc++.h>

using namespace std;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int N;
int m[20][20];
int d[20][20];
int s_y;
int s_x;
int s_w = 2;
int s_c = 0;

void bfs(){
	vector<vector<int>> visit(N,vector<int>(N,0));
	visit[s_y][s_x] = 1;
	queue<pair<int,int>> q;
	q.push({s_y,s_x});

	while(!q.empty()){
		int here_y = q.front().first; 
		int here_x = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++){
			int ny = here_y + dy[i];
			int nx = here_x + dx[i];
			if(ny >= 0 && ny < N && nx >= 0 && nx < N && visit[ny][nx] == 0 && m[ny][nx] <= s_w){
				visit[ny][nx] = visit[here_y][here_x] + 1;
				q.push({ny,nx});
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			d[i][j] = max(visit[i][j] - 1,0);
			
			}
			}
	
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> m[i][j];
			if(m[i][j] == 9){
				s_y = i;
				s_x = j;
			}
		}
	}
	int ans = 0;
	while(1){
		bfs();

		int ny = -1;
		int nx = -1;
		int nd = 987654321;

		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(m[i][j] != 9 && d[i][j] < nd && m[i][j] > 0 && m[i][j] < s_w && d[i][j] > 0){
					ny = i;
					nx = j;
					nd = d[i][j];
				}
			}
		}
		if(ny == -1 && nx == -1)break;
		m[s_y][s_x] = 0;
		s_y = ny;
		s_x = nx;
		m[s_y][s_x] = 9;
		s_c++;
		if(s_c == s_w){s_w++; s_c = 0;}
		ans+=nd;
		
	}
	cout << ans;
}
	



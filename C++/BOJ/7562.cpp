#include <bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;
int dy[8] = {1,1,-1,-1,2,2,-2,-2};
int dx[8] = {2,-2,2,-2,1,-1,1,-1};
int m[301][301];
int N;

bool check(int y, int x){
	return y >= 0 && y < N && x >= 0 && x < N;
}

int bfs(int starty, int startx, int goaly, int goalx){
	for(int i = 0; i < N; i++)fill(m[i], m[i]+N,-1);
	queue<ii> q;
	q.push({starty, startx});
	m[starty][startx] = 0;

	while(!q.empty()){
		ii temp = q.front(); q.pop();
		int y = temp.first;
		int x = temp.second;
		int dep = m[y][x];
		//cout << y << " " << x << " " << '\n';
		if(goaly == y && goalx == x){
			return dep;
		}
		for(int i = 0; i < 8; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(check(ny, nx) && m[ny][nx] == -1){
				m[ny][nx] = dep + 1;
				q.push({ny, nx});
			}

		}

	}
	return -1;
}



int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	int T;
	cin >> T;
	while(T--){
		cin >> N;
		int sy, sx, gy, gx;
		cin >> sy >> sx >> gy >> gx;
		cout << bfs(sy,sx,gy,gx) << '\n';
	}
	
}
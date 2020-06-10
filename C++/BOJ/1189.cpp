#include <bits/stdc++.h>

using namespace std;

string m[5];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
int R, C, K;
int ans = 0;
int visit[5][5];
bool check(int y, int x){
	return y >=0 && y < R && x >= 0 && x < C && m[y][x] != 'T' && visit[y][x] == 0;
}
void dfs(int y, int x, int depth){
	if(depth > K)return;
	if(y == 0 && x == C-1){
		if(depth == K){
			ans++;
		}
		return;
	}
	
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(check(ny,nx)){
			visit[ny][nx] = 1;
			dfs(ny,nx,depth+1);
			visit[ny][nx] = 0;
		}
	}
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	cin >> R >> C >> K;
	for(int i = 0; i < R; i++){
		cin >> m[i];
	}
	visit[R-1][0] = 1;
	dfs(R-1, 0, 1);
	cout << ans << '\n';
}
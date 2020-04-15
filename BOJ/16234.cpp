#include <bits/stdc++.h>

using namespace std;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int N, L, R;
int m[50][50];

int visit[50][50];
int group[50][50];
int group_cur = 1;
int tt[2501];
pair<int, int> dfs(int y, int x){
	visit[y][x] = 1;
	group[y][x] = group_cur;
	int ret_p = m[y][x];
	int ret_j = 1;

	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny >= 0 && ny < N && nx >=0 && nx < N && visit[ny][nx] == 0 && abs(m[ny][nx] - m[y][x]) >= L && abs(m[ny][nx] - m[y][x]) <= R){
			pair<int,int> temp = dfs(ny,nx);
			ret_p += temp.first;
			ret_j += temp.second;
		}
	}
	return {ret_p, ret_j};
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	cin >> N >> L >> R;

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)cin >> m[i][j];
	int ans = 0;
	while(1){
		bool flag = true;
		group_cur = 1;
		for(int i = 0; i < N; i++){fill(visit[i], visit[i]+N, 0);
		fill(group[i], group[i]+N, 0);}
		fill(tt, tt+2501, 0);
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(visit[i][j] == 0){
					pair<int,int> temp = dfs(i,j);  
					tt[group_cur] = temp.first/temp.second;
					if(temp.second > 1)flag = false;
					group_cur++;
				}
			}
		}
		if(flag)break;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				m[i][j] = tt[group[i][j]];
				
			}
			
		}
		ans++;
	}
	cout << ans;
	
}
	



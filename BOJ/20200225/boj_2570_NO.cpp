#include <bits/stdc++.h>

using namespace std;

int N, M;
int m[100][100];
int dy[4] = {-1,-1,1,1};
int dx[4] = {-1,1,-1,1};
int mapping(int y, int x){
	return N*y+x;
}

vector<int> adjlist[10001];
int b[10001];
int visit[10001];
int bipartite(int x){
	if(visit[x])return 0;
	visit[x] = 1;
	
	for(int i = 0; i < adjlist[x].size(); i++){
		int next = adjlist[x][i];
		
		if(b[next] == -1 || bipartite(b[next])){
			b[next] = x;
			return 1;
		}
	}
	
	return 0;
}

int main(){
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	fill(b,b+10001,-1);
	cin >> N >> M;
	
	for(int i = 0; i < M; i++){
		int y, x;
		cin >> y >> x;
		m[y-1][x-1] = 1;
	}
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			if(m[i][j] == 1)continue;
			int t = mapping(i,j);
			for(int k = 0; k < 4; k++){
				
				int ty = i;
				int tx = j;
				int c = 1;
				while(ty + c*dy[k] >= 0 && ty + c*dy[k] < N && tx + c*dx[k] >= 0 && tx + c*dx[k] < N){
					int tty = ty + c * dy[k];
					int ttx = tx + c * dx[k];
					if(m[tty][ttx] == 0){
						int new_t = mapping(tty,ttx);
						adjlist[t].push_back(new_t);
					}
					c++;
				}
				
			}
			
		}
}
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
int N, M, T;
int v[50][50];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
void erase(){
	vector<vector<int>> visit(50,vector<int>(50,0));
	bool flag = true;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(visit[i][j] || v[i][j] == -1)continue;
			visit[i][j] = 1;
			queue<pii> q;
			q.push({i,j});
			vector<pii> tt;
			while(!q.empty()){
				pii temp = q.front(); q.pop();
				int y = temp.first;
				int x = temp.second;
				tt.push_back({y,x});
				for(int k = 0; k < 4; k++){
					int ny = y + dy[k];
					int nx = (x + dx[k] + M)%M;
					if(ny >= 0 && ny < N && visit[ny][nx] == 0 && v[ny][nx] == v[y][x]){
						visit[ny][nx] = 1;
						q.push({ny, nx});
					}
				}
			}

			if(tt.size() > 1){
				flag = false;
				for(int i = 0; i < tt.size(); i++){
					pii temp = tt[i];
					v[temp.first][temp.second] = -1;
				}
			}
		
		}
	}
			
	if(flag == true){
		double avg = 0;
		double count = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(v[i][j] != -1){
					avg+= v[i][j];
					count++;	
				}
			}
		}
		avg = avg/count;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(v[i][j] != -1){
					if(v[i][j] > avg){v[i][j]--;}
					else if(v[i][j] < avg){v[i][j]++;}
				}
			}
		}
	}
	
}

void turn(int num,int t,int dir){
	
	int start = num-1;
	t = t%M;
	dir = (dir == 0? 1 : -1);
	int temp[51];
	while(start < N){
		for(int i = 0; i < M; i++){
			temp[(i+M+dir*t)%M] = v[start][i];
		}
		for(int i = 0; i < M; i++){
			v[start][i] = temp[i];
		}
		start += num;
	}
}
void print(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << v[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    
	cin >> N >> M >> T;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> v[i][j];
		}
	}
	while(T--){
		int a, b, c;
		cin >> a >> b >> c;
		turn(a,c,b);
		erase();
	}
	int ans = 0;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(v[i][j] != -1){
				ans += v[i][j];
			}
		}
	}
	cout << ans;
}
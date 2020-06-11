#include <bits/stdc++.h>
 
using namespace std;
using dots = pair<int,int>;
int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};
string m[51];
bool checkmap[51][51];
int N, M;
bool check(int y, int x){
	if(y >= 0 && y < N && x >= 0 && x < M && m[y][x] == '.')return true;
	return false;
}
void print(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << m[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}
int check1(int y, int x){
	if(y >= 0 && y < N && x >= 0 && x < M && m[y][x] != '#')return true;
	return false;
}
 
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
 
	int t;
	cin >> t;
	while(t--){
		cin >> N >> M;
		queue<dots> good;
		queue<dots> goodche;
		queue<dots> badche;
		queue<dots> bad;
		for(int i = 0; i < N; i++){
			cin >> m[i];
			for(int j = 0; j < M; j++){
				if(m[i][j] == 'G'){
					good.push({i,j});
					goodche.push({i,j});
				}
				else if(m[i][j] == 'B'){
					bad.push({i,j});
					badche.push({i,j});
				}
			}
		}	
 
		while(!bad.empty()){
			dots temp = bad.front(); bad.pop();
			int y = temp.first;
			int x = temp.second;
			for(int i = 0; i < 4; i++){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(check(ny,nx)){
					m[ny][nx] = '#';
				}
			}
		}
		bool flag = true;
		vector<vector<bool>> visit(N,vector<bool>(M,0));
		if(m[N-1][M-1] == '.'){
		visit[N-1][M-1] = 1;
		queue<dots> q;
		q.push({N-1, M-1});
		while(!q.empty()){
			dots temp = q.front(); q.pop();
			int y = temp.first;
			int x = temp.second;
 
			for(int i = 0; i < 4; i++){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(check1(ny,nx) && visit[ny][nx] == 0){
					visit[ny][nx] = 1;
					q.push({ny,nx});
				}
			}
		}
	
		}
	for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(m[i][j] == 'G'){
					if(visit[i][j] != 1)flag = false;
				}
				if(m[i][j] == 'B'){
					if(visit[i][j] != 0)flag = false;
				}
			}
		}
		cout << (flag ? "Yes" : "No") << '\n';
	}
}
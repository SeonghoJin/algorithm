#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
using da = pair<pii, int>;
int dp[51][51][65];
string m[51];
int N, M;
int starty, startx;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
bool check(int y, int x, int hasKey){
	
	if(y >= 0 && y < N && x >= 0 && x < M){
		if(m[y][x] == '#')return false;
		if(m[y][x] >= 'A' && m[y][x] <= 'F'){
			int k = m[y][x] - 'A';
			if((1 << k) & hasKey){
				return true;
			}
			else return false;
		}
		else{
			return true;
		}
	}
	return false;
}

void printm(int hasKey){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << dp[i][j][hasKey] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	cin >> N >> M;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			for(int k = 0; k < 64; k++){
				dp[i][j][k] = -1;
			}
		}
	}

	for(int i = 0; i < N; i++){
		cin >> m[i];
		for(int j = 0; j < M; j++){
			if(m[i][j] == '0'){
				starty = i;
				startx = j;
			}
		}
	}
	
	
	queue<da> q;
	dp[starty][startx][0] = 0;
	q.push({{starty, startx}, 0});
	int answer = 987654321;
	while(!q.empty()){
		da next = q.front(); q.pop();
		int y = next.first.first;
		int x = next.first.second;
		int hasKey = next.second;
		int depth = dp[y][x][hasKey];
		
		if(m[y][x] == '1'){
			answer = min(answer, depth);
			break;
		}
		for(int i = 0; i < 4; i++){
			int ny = dy[i] + y;
			int nx = dx[i] + x;
	
			if(check(ny, nx, hasKey)){
				int newKey = -1;
				bool flag = false;
				if(m[ny][nx] >= 'a' && m[ny][nx] <= 'f'){
					newKey = hasKey | (1 << (m[ny][nx] - 'a'));
					swap(hasKey,newKey);
					flag = true;
				}
				if(dp[ny][nx][hasKey] != -1 && dp[ny][nx][hasKey] <= depth+1){
					if(flag)swap(hasKey, newKey);
					continue;
				}
				dp[ny][nx][hasKey] = depth+1;
				
				q.push({{ny,nx}, hasKey});
				if(flag)swap(hasKey,newKey);
				
			}
		}
	}
	
	cout << (answer == 987654321? -1 : answer);
}
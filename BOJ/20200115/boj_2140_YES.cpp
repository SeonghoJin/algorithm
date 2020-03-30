#include <iostream>
#include <vector>
using namespace std;

int map[101][101];
int dy[8] = {0,0,-1,1,1,-1,1,-1};
int dx[8] = {1,-1,0,0,1,-1,-1,1};
int N;
	
struct point{
	int y, x;
	point(int _y, int _x) : y(_y), x(_x){
		
	}
};
vector<point> v;
int ans = 0;
void print(){
	cout << '\n';
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(map[i][j] == '#')
				cout << '#';
			else{cout << map[i][j];}
		}
		cout << '\n';
	}
	cout << '\n';
}
void dfs(int n, int c){
	if(n == v.size()){
		ans = max(ans, c);
		return;
	}
	
	int y = v[n].y;
	int x = v[n].x;
	bool flag = true;
	
	for(int i = 0; i < 8; i++){
		int ty = y + dy[i];
		int tx = x + dx[i];
		
		if(0 <= ty && ty < N && 0 <= tx && tx < N && map[ty][tx] != '#' && map[ty][tx] == 0){
			flag = false;
		}
	}
	
	if(flag){
		for(int i = 0; i < 8; i++){
			int ty = y + dy[i];
			int tx = x + dx[i];
			
			if(0 <= ty && ty < N && 0 <= tx && tx < N && map[ty][tx] != '#'){
				map[ty][tx]--;
			}
		}
		dfs(n+1, c+1);
		for(int i = 0; i < 4; i++){
			int ty = y + dy[i];
			int tx = x + dx[i];
			
			if(0 <= ty && ty < N && 0 <= tx && tx < N && map[ty][tx] != '#'){
				map[ty][tx]++;
			}
		}
	}
	else{dfs(n+1,c);}
	
}


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++){
		string s;
		cin >> s;
		
		for(int j = 0; j < N; j++){
			map[i][j] = s[j];
		if(map[i][j] == '#'){
			v.push_back(point(i,j));
		}
		else{
			map[i][j] -= '0';
		}
			
	}
	}
	dfs(0, 0);
	cout << ans;
	
	
}
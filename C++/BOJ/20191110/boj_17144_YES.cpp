#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int R,C,T;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int w1_dx[4] ={1,0,-1,0};
int w1_dy[4] ={0,-1,0,1};
int w2_dx[4] ={1,0,-1,0};
int w2_dy[4] ={0,1,0,-1};

int map[51][51], temp[51][51];
pair<int, int> cl[2];
bool isWide(int y, int x){
	return 	y >= 0 && y < R && x >= 0 && x < C && map[y][x] != -1;
	
}

void wind1(){
	for(int i = 0; i < 51; i++)fill(temp[i], temp[i]+51, 0);
	
	int y = cl[0].first;
	int x = cl[0].second;
	
	int dir = 0;
	int _y = y;
	int _x = x;
	
	while(1){
		int new_y = _y + w1_dy[dir];
		int new_x = _x + w1_dx[dir];
		if(new_y <= y && new_y >= 0 && new_x < C && new_x >= 0){
			if(map[_y][_x] != -1)temp[new_y][new_x] = map[_y][_x];
			_y = new_y;
			_x = new_x;
		}
		else{
			dir = (dir+1)%4;
		}
		if(_y == y && _x == x)break;
	}
	
	for(int i = 0; i <= y; i++){
		for(int j = 0; j < C; j++){
			if(i == y || i == 0 || j == 0 || j == C-1)map[i][j] = temp[i][j];
		}
	}
	
}
void wind2(){
	for(int i = 0; i < 51; i++)fill(temp[i], temp[i]+51, 0);
	
	int y = cl[1].first;
	int x = cl[1].second;
	
	int dir = 0;
	int _y = y;
	int _x = x;
	
	while(1){
		int new_y = _y + w2_dy[dir];
		int new_x = _x + w2_dx[dir];
		if(new_y >= y && new_y < R && new_x < C && new_x >= 0){
			if(map[_y][_x] != -1)temp[new_y][new_x] = map[_y][_x];
			_y = new_y;
			_x = new_x;
		}
		else{
			dir = (dir+1)%4;
		}
		if(_y == y && _x == x)break;
	}
	
	for(int i = y; i < R; i++){
		for(int j = 0; j < C; j++){
			if(i == y || i == R-1 || j == 0 || j == C-1)map[i][j] = temp[i][j];
		}
	}
}


void bfs(){
	
	queue<pair<pair<int, int>, int>> q;
	
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++){
			temp[i][j] = 0;
			if(map[i][j] > 0){
				q.push({{i,j}, map[i][j]});
			}
		}
	
	
	while(!q.empty()){
		pair<pair<int, int>, int> t = q.front(); q.pop();
		int y = t.first.first;
		int x = t.first.second;
		int cap = t.second;
		int exit_cap = t.second/5;
		for(int i = 0; i < 4; i++){
			if(isWide(y+dy[i],x+dx[i])){
				map[y][x] -= exit_cap;
				temp[y+dy[i]][x+dx[i]] += exit_cap;
			}
		}
	}
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			map[i][j] += temp[i][j];
		}
	}
	
}

void print(){
	cout << '\n';
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}
}
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> R >> C >> T;
	
	int cur = 0;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++){
			cin >> map[i][j];
			if(map[i][j] == -1){cl[cur++] = {i,j};}
		}
	
	while(T--){
		bfs();
		wind1();
		wind2();
		map[cl[0].first][cl[0].second] = -1;
		map[cl[1].first][cl[1].second] = -1;
	}
	int ret = 0;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(map[i][j] > 0){
				ret += map[i][j];
			}
		}
	}
	cout << ret;
	
}
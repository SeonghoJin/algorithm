#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;


int N,M; // 2 <= N,M <= 100
int map[100][100]; // x = map[i][j], x = 0 일때는 좌표 i,j는 불통, x = 1일때는 통과. 
// 목표는 N-1, M-1좌표에 최단으로 가는 것.
int answer = -1;
queue<pair<int,int>> path;

static void input(){
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		string str;
		cin >> str;
		for(int j = 0; j < M; j++){
			 map[i][j] = str.at(j)-48;
		}
	}
	
}

static void bfs(){
	
	path.push(make_pair(0,0));
	while(!path.empty()){
		int x = path.front().first;
		int y = path.front().second;
		if(x == M && y == N) break;
		
		bool flag = false;
		path.pop();
		if(x+1 < M && map[y][x+1] == 1)map[y][x+1] = map[y][x]+1, path.push(make_pair(x+1,y)),flag=true;
		if(x-1 >=0 && map[y][x-1] == 1)map[y][x-1] = map[y][x]+1, path.push(make_pair(x-1,y)),flag=true;
		if(y+1 < N && map[y+1][x] == 1)map[y+1][x] = map[y][x]+1, path.push(make_pair(x,y+1)),flag=true;
		if(y-1 >=0 && map[y-1][x] == 1)map[y-1][x] = map[y][x]+1, path.push(make_pair(x,y-1)),flag=true;
	}
	
	
}

	
int main(){
	input();
	bfs();
	cout << map[N-1][M-1];
}

/*#include <iostream>

using namespace std;

int N, M;
int cy, cx, d, map[51][51];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

bool check(int y, int x){
	return y >= 0 && y < N && x >= 0 && x < M && map[y][x] == 0;
}
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> N >> M;
	cin >> cy >> cx >> d;
	
	int tile = 0;
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)cin >> map[i][j];
	while(1){
		
		tile++;
		map[cy][cx] = -1;
		
		bool flag = true;
		
		while(1){
			bool f = false;
			for(int i = 1; i <= 4; i++){
				if(check(cy+dy[(d-i+4)%4],cx+dx[(d-i+4)%4])){
					cy += dy[(d-i+4)%4];
					cx += dx[(d-i+4)%4];
					d = (d-i+4)%4;
					f = true; 
					break;
				}
			}
			if(f){break;}
			cy += dy[(d+2)%4];
			cx += dx[(d+2)%4];
			if(cy < 0 || cy >= N || cx < 0 || cx >= M || map[cy][cx] == 1){flag = false; break;}
			
		}
		if(!flag)break;
	}
	cout << tile;
}*/
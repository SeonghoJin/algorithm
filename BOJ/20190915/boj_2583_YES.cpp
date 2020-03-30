#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[101][101];

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int M, N, K;
int dfs(int y, int x){
	if(map[y][x] == 1 || !(y >= 0 && y < M && x >= 0 && x < N))return 0;
	map[y][x] = 1;
	
	int ret = 1;
	for(int i = 0; i < 4; i++){
		ret+=(dfs(y+dy[i],x+dx[i]));
	}
	
	return ret;
}

int main(){
	
	
	
	cin >> M >> N >> K;
	vector<int> s;
	for(int i = 0; i < K; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		for(int j = x1; j < x2; j++){
			for(int k = y1; k < y2; k++){
				map[k][j] = 1;
			}
		}
	}
	int count = 0;	
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(map[i][j] == 0){
				count++;
				s.push_back(dfs(i,j));
			}
		}
	}
	sort(s.begin(),s.end());
	cout << count << '\n';
	for(auto it = s.begin(); it != s.end(); it++){
		cout << *it << ' ';
	}
	
	
}
/*
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int answer = 0;
int N;
vector<vector<int>> map(500,vector<int>(500));
vector<vector<int>> dp(500,vector<int>(500,-1));
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool canmove(int y, int x){
	return (y < N && y >= 0) && (x < N && x >= 0);
}

int canlive(int y, int x){
	
	int& ret = dp[y][x];
	if(ret != -1)return ret;
	
	ret = 1;	
	for(int i = 0; i < 4; i++){
		int ty = y + dy[i]; 
		int tx = x + dx[i];
	
		if(canmove(ty,tx) && (map[y][x] < map[ty][tx])){
			ret = max(canlive(ty,tx)+1,ret);
		}
		
	}
	
	return ret;
}


int main(){
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> map[i][j];
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			answer = max(canlive(i,j),answer);
		}
	}
	
	cout << answer << '\n';
	
	
}*/
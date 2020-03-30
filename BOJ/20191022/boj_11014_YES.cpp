/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
string map[80];
int dx[6] = {-1,1,-1,1, 1, -1};
int dy[6] = {1,1,0,0,-1,-1};
vector<int> adjlist[6400];

int mapping(int y, int x){
	return y*M+x;
}

bool ischeck(int y, int x){
	if(y >= 0 && y < N && x >= 0 && x < M && map[y][x] != 'x') return true;
	return false;
}

void precalc(){
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(j & 1)continue;
			if(map[i][j] == 'x')continue;
			for(int k = 0; k < 6; k++){
				if(ischeck(i+dy[k],j+dx[k])){
					adjlist[mapping(i,j)].push_back(mapping(i+dy[k],j+dx[k]));
				}
			}
			
		}
	}
}


int visit[6401], matched[6401]; 
int dfs(int n){
	if(visit[n])return 0;
	visit[n] = 1;
	
	for(int i = 0; i < adjlist[n].size(); i++){
		int next = adjlist[n][i];
		
		if(matched[next] == -1 || dfs(matched[next])){
			matched[next] = n;
			return 1;
		}
	}
	
	return 0;
}

int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--){
	cin >> N >> M;
	for(int i = 0; i < 6400; i++)adjlist[i].clear();
	int ans = 0;
	
	for(int i = 0; i < N; i++)
		cin >> map[i];
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++){
			if(map[i][j] == 'x')ans++;
		}
	
	precalc();
	
	fill(matched,matched+6401,-1);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++){
			int num = mapping(i,j);
			fill(visit,visit+6401,0);
			if(dfs(num))ans++;
		}
	
	cout <<N*M - ans << '\n';
	}
}*/
/*
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int M, N;
int cache[1001][1001];
int crush[1001][1001];
string map[1001];

int dx[4] ={0,0,1,-1};
int dy[4] ={1,-1,0,0};

bool islimit(int i,int j){
	
	return i <= N && i > 0 && j <= M && j > 0 && map[i][j]=='0' && cache[i][j]==0;
}

bool cancrush(int i, int j){
	return i <= N && i > 0 && j <= M && j > 0 && map[i][j]=='1' && crush[i][j]==0;	
}

bool cacrush(int i, int j){
	return i <= N && i > 0 && j <= M && j > 0 && map[i][j]=='0' && crush[i][j]==0;	
}

int bfs(){
	
	queue<pair<pair<int,int>,int>> q;
	q.push(make_pair(make_pair(1,1),0));
	cache[1][1]=1;
	while(!q.empty()){
	
		pair<pair<int, int>,int> p = q.front();
		q.pop();
		int i = p.first.first;
		int j = p.first.second;
		int iscrush = p.second;
		
		if(i == N && j == M){return cache[i][j] == 0 ? crush[i][j] : cache[i][j];}
		
		for(int t = 0; t < 4; t++){
			
			int ty = i+dy[t];
			int tx = j+dx[t];
			if(iscrush == 0 && islimit(ty,tx)){
				
				cache[ty][tx] = cache[i][j]+1;
				q.push(make_pair(make_pair(ty,tx),iscrush));
			}
			else if(iscrush == 1 && cacrush(ty,tx)){
				crush[ty][tx] = crush[i][j]+1;
				q.push(make_pair(make_pair(ty,tx),1));
			}
			else if(iscrush == 0 && cancrush(ty,tx)){
				crush[ty][tx] = cache[i][j]+1;
				q.push(make_pair(make_pair(ty,tx),1));
			}
		}
	}
	
	return -1;
	
}


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++){
		string s = "";
		cin >> s;
		string p = "0";
		p+=s;
		map[i]=p;
	}
	

	
	cout << bfs();
	
	
}*/
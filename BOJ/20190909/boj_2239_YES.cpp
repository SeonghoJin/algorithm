/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using pii = pair<int, int>;

vector<pii> vacants;
vector<vector<int>> sdoku(9,vector<int>(9,0));
vector<vector<int>> answer;
bool flag = true;

vector<vector<int>> makecandidates(){
	
	vector<vector<int>> candidates(vacants.size());
	for(int i = 0; i < vacants.size(); i++){
		int y = vacants[i].first;
		int x = vacants[i].second;
		int Arr[10] ={0,};
		
		for(int j = 0; j < 9; j++){
			Arr[sdoku[y][j]]=1;
			Arr[sdoku[j][x]]=1;
		}
		
		
		int dy = (y/3)*3;
		int dx = (x/3)*3;
		
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				Arr[sdoku[dy+j][dx+k]]=1;	
			}
		}
		
		for(int j = 1; j <= 9; j++){
			if(Arr[j] == 0){candidates[i].push_back(j);
							
		}
		}
		
		
	}
	return candidates;
}

bool check(int i, int j, int p){
	
		
		for(int k = 0; k < 9; k++){
			if(sdoku[k][j] == p || sdoku[i][k] == p)return false;
		}
		
		
		int dy = (i/3)*3;
		int dx = (j/3)*3;
		
		for(int t = 0; t < 3; t++){
			for(int k = 0; k < 3; k++){
				if(sdoku[dy+t][dx+k] == p)return false;	
			}
		}
	
		return true;
}


void dfs(vector<vector<int>>& candidates, int N, int n){
	
	if(!flag)return;
	if(N == n){
		flag = false;
		answer = sdoku;
		return;
	}
	
	for(int i = 0; i < candidates[n].size(); i++){
		int y = vacants[n].first;
		int x = vacants[n].second;
		if(check(y,x,candidates[n][i])){
			sdoku[y][x] = candidates[n][i];
			dfs(candidates, N, n+1);
			sdoku[y][x] = 0;
		}
	}
	
	
}

int main(){
	
	for(int i = 0; i < 9; i++){
		string str;
		cin >> str;
		for(int j = 0; j < 9; j++){
			sdoku[i][j] = str[j]-'0';
			if(sdoku[i][j] == 0)vacants.push_back(make_pair(i,j));
								
		}
	}
	
	vector<vector<int>> candidates = makecandidates();
	
	dfs(candidates,vacants.size(), 0);
	
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << answer[i][j];
		}
		cout << '\n';
	}
	
}
*/
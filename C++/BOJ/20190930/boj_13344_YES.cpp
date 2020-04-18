/*
#include <vector>
#include <iostream>
#include <string>
using namespace std;
using pii = pair<int, int>;

const string s1 = "consistent";
const string s2 = "inconsistent";
vector<vector<int>> v(50000,vector<int>());
vector<vector<int>> vv(50000,vector<int>());
int parent[50000];
int find(int i){return i == parent[i] ? i : parent[i] = find(parent[i]);}
void Union(int i, int j){
	parent[find(i)] = find(j);
}
bool isUnion(int i, int j){
	return find(i) == find(j);
}
int visit[50000];
int temp_visit[50000];
bool dfs(int n){
	if(visit[n] == 1)return true;
	else if(visit[n] == -1)return false;
	int k = n;
	visit[n] = -1;
	bool flag = true;
	for(int i = 0; i < vv[n].size(); i++){
		flag &= dfs(vv[n][i]);
	}
	visit[n] = 1;
	if(flag == false)visit[n] = -2;
	return flag;	
}



int main(){

	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; i++)parent[i] = i;
	for(int i = 0; i < M; i++){
		int a,b;
		char c;
		cin >> a >> c >> b;
		if(c == '>'){v[b].push_back(a);}
		else if(c == '<'){v[a].push_back(b);}
		else{Union(a,b);}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < v[i].size(); j++){
			vv[find(i)].push_back(find(v[i][j]));
		}
	}
	
	bool flag = true;
	
	for(int i = 0; i < N; i++){
		flag &= dfs(find(i));
	}

	cout << (flag ? s1 : s2);
	
}
*/
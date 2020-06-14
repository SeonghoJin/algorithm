#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};
int N, K;
int m[13][13];
vector<int> has[13][13];
pii where[13];
int dir[13];
void print(){
	/*
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cout << m[i][j] << " ";
		}
		cout << '\n';
	}*/
	cout << '\n';
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			for(int k = 0; k < has[i][j].size(); k++){
				cout << has[i][j][k] << "";
			}
			if(has[i][j].size() == 0)cout << '0';
			cout << " ";
		}
		cout << '\n';
	}
	cout << '\n';
	for(int i = 1; i <= K; i++){
		cout << dir[i] << " ";
	}
	cout << '\n';
	/*
	for(int i = 1; i <= K; i++){
		cout << i << " is " << where[i].first << " " << where[i].second << '\n';
	}
	cout << '\n';*/
}
bool check(int y, int x){
	return (y > 0 && y <= N && x > 0 && x <= N);
}

void red(int num, int y, int x, int ty, int tx){
	while(1){
		int t = has[y][x].back(); has[y][x].pop_back();
		has[ty][tx].push_back(t);
		where[t] = {ty,tx};
		if(t == num)break;
	}
	return;
}

void white(int num, int y, int x, int ty, int tx){
	stack<int> temp;
	while(1){
		int t = has[y][x].back(); has[y][x].pop_back();
		temp.push(t);
		if(t == num)break;
	}
	while(!temp.empty()){
		int t = temp.top(); temp.pop();
		where[t] = {ty, tx};
		has[ty][tx].push_back(t);
	}
	return;
}

void blue(int num, int y, int x, int ty, int tx){
	dir[num] = (dir[num] >= 2 ? 2 : 0) + (dir[num]+1)%2;
	ty = dy[dir[num]] + y;
	tx = dx[dir[num]] + x;

	if(!check(ty,tx) || m[ty][tx] == 2){
		return;
	}
	else if(m[ty][tx] == 1){
		red(num,y,x,ty,tx);
	}
	else if(m[ty][tx] == 0){
		white(num,y,x,ty,tx);
	}
	else return;
}
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	cin >> N >> K;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> m[i][j];
		}
	}

	for(int i = 1; i <= K; i++){
		int a, b, c;
		cin >> a >> b >> c;
		where[i] = {a,b};
		has[a][b].push_back(i);
		dir[i] = c-1;
	}

	int turn = 0;
	
	while(1){
		turn++;
		bool flag = false;
		if(turn > 1000)break;

		for(int i = 1; i <= K; i++){
			pii t = where[i];
			int y = t.first;
			int x = t.second;
			int ty = y + dy[dir[i]];
			int tx = x + dx[dir[i]];
			if(!check(ty,tx) || m[ty][tx] == 2){
				blue(i,y,x,ty,tx);
			}
			else if(m[ty][tx] == 1){
				red(i,y,x,ty,tx);
			}
			else if(m[ty][tx] == 0){
				white(i,y,x,ty,tx);
			}
			t = where[i];
			if(has[t.first][t.second].size() >= 4)flag = true;
		}
		if(flag)break;
	}

	cout << (turn > 1000 ? -1 : turn);
}
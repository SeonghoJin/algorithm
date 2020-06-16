#include <bits/stdc++.h>

using namespace std;

int K;
string state[4];
int is[4][4];
int dy[2] = {-1,1};
void calc(){
	is[0][1] = is[1][0] = state[0][2] != state[1][6];
	is[1][2] = is[2][1] = state[1][2] != state[2][6];
	is[2][3] = is[3][2] = state[2][2] != state[3][6]; 
}

void rotate(int num, int dir){
	int visit[4];
	fill(visit, visit+4, 0);

	queue<int> q;

	q.push(num);
	visit[num] = dir;
	while(!q.empty()){
		int here = q.front(); q.pop();

		for(int i = 0; i < 2; i++){
			int ny = dy[i] + here;
			if(ny < 0 || ny >= 4)continue;
			if(visit[ny] != 0)continue;
			if(is[here][ny] == 0)continue;
			visit[ny] = -visit[here];
			q.push(ny);
		}
	}

	for(int i = 0; i < 4; i++){
		int temp[8];
		int d = visit[i];
		for(int j = 0; j < 8; j++){
			temp[(j+8+d)%8] = state[i][j];
		}
		for(int j = 0; j < 8; j++){
			state[i][j] = temp[j];
		}
	}

}
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(false);

	for(int i = 0; i < 4; i++){
		cin >> state[i];
	}

	cin >> K;
	calc();
	while(K--){
		int a, b;
		cin >> a >> b;
		rotate(a-1,b);
		calc();
	}

	int ans = 0;
	for(int i = 0, k = 1; i < 4; i++,k*=2){
		if(state[i][0] == '1')ans+=k;
	}
	cout << ans;
}
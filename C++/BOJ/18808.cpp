#include <bits/stdc++.h>

using namespace std;
int N, M, K;
vector<vector<int>> s[101];
int note[40][40];

vector<vector<int>> rotate(vector<vector<int>> sticker){
	int R = sticker.size();
	int C = sticker[0].size();

	vector<vector<int>>res(C, vector<int>(R));

	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			res[j][R-i-1] = sticker[i][j];
		}
	}
	
	return res;
}

bool check(int y, int x, vector<vector<int>>& sticker){
	int R = sticker.size();
	int C = sticker[0].size();
	
	if(y + R - 1 >= N)return false;
	if(x + C - 1 >= M)return false;

	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(sticker[i][j] == 1){
				if(note[y+i][x+j])return false;
			}
		}
	}
	
	return true;
}

void attach(vector<vector<int>> sticker){
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < M; k++){
				if(check(j,k,sticker)){
					for(int l = 0; l < sticker.size(); l++){
						for(int m = 0; m < sticker[0].size(); m++){
							if(sticker[l][m] == 1){
								note[j+l][k+m] = sticker[l][m];
							}
						}
					}
					return;
				}
			}
		}
		sticker = rotate(sticker);
	}
	return;
}

void print(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << note[i][j];
		}
		cout << '\n';
	}
	cout << '\n';	
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	cin >> N >> M >> K;
	
	for(int i = 0; i < K; i++){
		int R, C;
		cin >> R >> C;
		s[i] = vector<vector<int>>(R, vector<int>(C));

		for(int j = 0; j < R; j++){
			for(int k = 0; k < C; k++){
				cin >> s[i][j][k];
			}
		}
	}

	for(int i = 0; i < K; i++){
		attach(s[i]);
	}
	int ans = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			ans+=(note[i][j]);
		}
	}

	cout << ans;
}
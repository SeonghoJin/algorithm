#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
int path[13][101];
int N, M;
int m[51][51];
pii home[101];
pii chicken[13];
int c_cur = 0;
int h_cur = 0;
void precalc(){
	for(int i = 0; i < c_cur; i++){
		for(int j = 0; j < h_cur; j++){
			int p = abs(home[j].first - chicken[i].first) + abs(home[j].second - chicken[i].second);
			path[i][j] = p;
		}
	}
}
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(false);

	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> m[i][j];
			if(m[i][j] == 1){
				home[h_cur++] = {i,j};
			}
			else if(m[i][j] == 2){
				chicken[c_cur++] = {i,j};
			}
		}
	}

	precalc();
	int ans = INT_MAX;

	for(int i = 0; i < (1 << c_cur); i++){
		int sum = 0;
		for(int j = 0; j < c_cur; j++){
			sum+=((i & (1 << j)) > 0);
		}
		if(sum != M)continue;

		vector<int> sh(h_cur,INT_MAX);
		for(int j = 0; j < c_cur; j++){
			if((i & (1 << j)) == 0)continue;

			for(int k = 0; k < h_cur; k++){
				sh[k] = min(sh[k], path[j][k]);
			}
		}
		int temp = 0;
		for(int j = 0; j < h_cur; j++){
			temp += (sh[j]);
		}
		ans = min(ans, temp);
	}
	cout << ans;
}
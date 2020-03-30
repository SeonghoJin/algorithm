#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	
	int N,M;
	cin >> N >> M;
	
	vector<vector<int>> v(N+1,vector<int>(N+1,987654321));
	vector<vector<int>> p(N+1,vector<int>(N+1,0));
	for(int i = 1; i <= N; i++){
		v[i][i] = 0;
	}
	
	while(M--){
		int a, b, c;
		cin >> a >> b >> c;
		v[a][b] = min(v[a][b],c);
		p[a][b] = a;
	}
	
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			for(int k = 1; k <= N; k++){
				if(v[j][k] > v[j][i]+v[i][k]){
					v[j][k] = v[j][i]+v[i][k];
					p[j][k] = i;
				}
			}
	
	int answer = 987654321;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(i == j)continue;
			answer = min(answer, v[i][j]+v[j][i]);
		}
	}
	
	if(answer == 987654321){cout << -1;}
	else cout << answer;
}
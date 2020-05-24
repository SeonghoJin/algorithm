#include <bits/stdc++.h>

using namespace std;
int m[1001][1001];
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	int answer = 0;
	for(int i = 0; i < N; i++){
		string str;
		cin >> str;
		for(int j = 0; j < str.size(); j++){
			m[i][j] = str[j] - '0';
			answer = max(answer, m[i][j]);
		}
	}


	for(int i = 0; i < N-1; i++){
		for(int j = 0; j < M-1; j++){
			int len = min({m[i][j], m[i+1][j], m[i][j+1]});
			if(m[i+1][j+1] == 1){
				m[i+1][j+1] = len+1;
				answer = max(answer, len+1);
			}
		}
	}

	cout << answer*answer;
}
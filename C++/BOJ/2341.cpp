#include <bits/stdc++.h>

using namespace std;

int N, W;
int dp[50][4];
int level[4] = {1,86,172,256};
string code[4] = {"00","01","10","11"};
int arr[50];
int MAX = 987654321;
bool flag = false;
vector<int> answer;
vector<int> temp;

void find(int n, int k){
	//cout << n << " " << k << '\n';
	if(flag)return;
	if(n == 0){
		answer = temp;
		flag = true;
		return;
	}
	
	for(int i = 0; i < 4; i++){
		if(i == k){
			int next = abs(arr[n] - level[k]) + W;
			if(dp[n-1][i] + next == dp[n][k]){
				temp.push_back(i);
				find(n-1,i);
				temp.pop_back();
			}
		}
		else{
			int next = abs(arr[n] - level[k]) + 3*W;
			if(dp[n-1][i] + next == dp[n][k]){
				temp.push_back(i);
				find(n-1,i);
				temp.pop_back();
			}
		}
	}

}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N >> W;
	for(int i = 0; i < 50; i++){fill(dp[i], dp[i]+4, MAX);}
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}

	for(int i = 0; i < 4; i++){
		dp[0][i] = abs(level[i] - arr[0]) + 2*W;
	}

	for(int i = 1; i < N; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				if(j == k){
					dp[i][j] = min(dp[i][j],dp[i-1][k] + abs(level[j] - arr[i]) + W);
				}
				else{
					dp[i][j] = min(dp[i][j],dp[i-1][k] + abs(level[j] - arr[i]) + 3*W);
				}
			}

		}
	}
    
	int ans = MAX;
	for(int i = 0; i < 4; i++){
		ans = min(ans, dp[N-1][i]);
	}
	/*
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 4; j++){
			cout << dp[i][j] << " ";
		}
		cout << '\n';
	}
	*/
	cout << ans << '\n';
	for(int i = 0; i < 4; i++){
		if(ans == dp[N-1][i]){
			temp.push_back(i);
			find(N-1, i);
			break;
		}
	}
	
	reverse(answer.begin(), answer.end());
	/*
	for(int i = 0; i < answer.size(); i++){
		cout << answer[i] << " ";
	}
	cout << '\n';
	*/
	cout << code[answer[0]];
	
	for(int i = 1; i < answer.size(); i++){
		cout << (answer[i] == answer[i-1] ? "0" : "1" + code[answer[i]]);
	}
}
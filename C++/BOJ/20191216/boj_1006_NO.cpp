#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 10001;


int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int T;
	cin >> T;
	
	while(T--){
		int N, M;
		cin >> N >> M;
		int Arr[2][MAX];
		
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < N; j++){
				cin >> Arr[i][j];
			}
		}
		
		
		int dp[3][MAX];
		for(int i = 0; i < 3; i++)fill(dp[i], dp[i]+MAX, 0);
		int ans = 0;
		
		dp[0][0] = (Arr[0][0] + Arr[1][0] <= M);
		dp[0][1] = max(dp[0][0] + (Arr[1][1] + Arr[0][1] <= M), (Arr[0][0] + Arr[0][1] <= M) + (Arr[1][0] + Arr[1][1] <= M));
		dp[1][1] = (Arr[0][0] + Arr[0][1] <= M);
		dp[2][1] = (Arr[1][0] + Arr[1][1] <= M);
		
		ans = max({dp[0][0],dp[0][1],dp[1][1],dp[2][1]});
		
		for(int i = 2; i < N; i++){
			int bf = (i + N - 1)%N;
			int bbf = (i + N - 2)%N;
			
			dp[0][i] = max(dp[0][i], max({dp[0][bf], dp[1][bf], dp[2][bf]})+(Arr[0][i] + Arr[1][i] <= M));
			dp[0][i] = max(dp[0][i], dp[0][bbf] + (Arr[0][i] + Arr[0][bf] <= M) + (Arr[1][i] + Arr[1][bf] <= M));
			dp[1][i] = max({dp[1][i], max(dp[2][bf],dp[0][bbf])+(Arr[0][i] + Arr[0][bf] <= M),dp[0][bbf]}); 
			dp[2][i] = max({dp[2][i], max(dp[1][bf],dp[0][bbf])+(Arr[1][i] + Arr[1][bf] <= M),dp[0][bbf]});
			
			ans = max({dp[0][i], dp[1][i], dp[2][i]});
		}
		
		
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < N; j++){
				cout << dp[i][j] << " ";
			}
			cout << '\n';
		}
		for(int i = 0; i < 3; i++)fill(dp[i], dp[i]+MAX, 0);
		cout << '\n';
		
		dp[0][N-1] = (Arr[0][N-1] + Arr[1][N-1] <= M);
		dp[0][0] = max(dp[0][N-1] + (Arr[1][0] + Arr[0][0] <= M), (Arr[0][N-1] + Arr[0][0] <= M) + (Arr[1][N-1] + Arr[1][0] <= M));
		dp[1][0] = (Arr[0][N-1] + Arr[0][0] <= M);
		dp[2][0] = (Arr[1][N-1] + Arr[1][0] <= M);
		
		ans = max({dp[0][N-1],dp[0][0],dp[1][0],dp[2][0]});
		
		for(int i = 1; i < N-1; i++){
			int bf = (i + N - 1)%N;
			int bbf = (i + N - 2)%N;
			
			dp[0][i] = max(dp[0][i], max({dp[0][bf], dp[1][bf], dp[2][bf]})+(Arr[0][i] + Arr[1][i] <= M));
			dp[0][i] = max(dp[0][i], dp[0][bbf] + (Arr[0][i] + Arr[0][bf] <= M) + (Arr[1][i] + Arr[1][bf] <= M));
			dp[1][i] = max({dp[1][i], max(dp[2][bf],dp[0][bbf])+(Arr[0][i] + Arr[0][bf] <= M),dp[0][bbf]}); 
			dp[2][i] = max({dp[2][i], max(dp[1][bf],dp[0][bbf])+(Arr[1][i] + Arr[1][bf] <= M),dp[0][bbf]});
			
			ans = max({dp[0][i], dp[1][i], dp[2][i]});
		}
		
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < N; j++){
				cout << dp[i][j] << " ";
			}
			cout << '\n';
		}
		
		cout << 2*N - ans;
		
	
	}
}
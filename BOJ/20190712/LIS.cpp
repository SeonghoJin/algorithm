#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	
	vector<int> arr;
	
	int N;
	cin >> N;
	arr.resize(N,0);
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	}
	
	vector<int> dp(N+1,0);
	
	int ans = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < i; j++){
			if(arr[j] < arr[i]){
				if(dp[i] < dp[j]+1){
					dp[i] = dp[j]+1;
				}
			}
		}
	}
	
	
	for(int i = 1; i <= N; i++){
		cout << dp[i] << " ";
	}
	
}
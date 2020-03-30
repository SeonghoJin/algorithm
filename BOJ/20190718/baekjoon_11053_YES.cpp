#include <iostream>
#include <cmath>
using namespace std;

int N;

int Arr[1001]={0,};
int dp[1001];
int main(){
	cin >> N;
	int rett = 0;
	for(int i = 1; i <= N; i++){
		cin >> Arr[i];
		int temp = 0;
		for(int j = 0; j < i; j++){
			if(Arr[i] > Arr[j])temp=max(temp,dp[j]);
		}
		dp[i] = temp+1;
		rett = max(rett,dp[i]);
	}
	

	cout << rett;
}

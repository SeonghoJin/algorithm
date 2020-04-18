#include <iostream>
#include <cmath>
using namespace std;


int N;
int arr[15];
int answer = 0;

bool impossible(int n){
	
	for(int i =1; i < n; i++){
		if(arr[i] == arr[n] || abs(i-n) == abs(arr[i]-arr[n]))return false;
	}
	
	return true;
}


void dfs(int n){
	if(n == N){answer++; return;}
	
	for(int i = 1; i <= N; i++){
		arr[n+1] = i;
		if(impossible(n+1)){
			dfs(n+1);
		}
		arr[n+1] = 0;
	}
	
	
}




int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> N;
	dfs(0);
	cout << answer;
	
}
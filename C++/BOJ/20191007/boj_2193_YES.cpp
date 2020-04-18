/*#include <iostream>
#include <algorithm>
using namespace std;

int N; 
long long cahce[100][2];

long long dfs(int n, int k){
	if(n == N){ return 1;}
	
	long long& ret = cahce[n][k];
	if(ret != -1)return ret;
	ret = 0;
	if(k == 0){
		ret += dfs(n+1,1);
	}
	ret += dfs(n+1,0);
	
	return ret;
}

int main(){
	
	cin >> N;
	for(int i = 0; i < 100; i++){fill(cahce[i],cahce[i]+2,-1);}
	cout << dfs(1,1);
}*/
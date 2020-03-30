/*
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int N, M;
	
	int Arr[1000001];
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		cin >> Arr[i];
	}
	
	int lo = 0, hi = 0, sum = 0, ans = 987654321;
	while(1){
		if(sum >= M)sum-=(Arr[lo++]== 1 ? 1 : 0);
		else if(hi == N)break;
		else{sum+=(Arr[hi++]== 1 ? 1 : 0);}
		if(sum == M)ans = min(ans,hi-lo);
	}
	ans = ans ==987654321 ?  -1: ans; 
	cout << ans;
}

*/
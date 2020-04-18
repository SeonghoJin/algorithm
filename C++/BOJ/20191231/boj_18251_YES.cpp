/*#include <iostream>
#include <algorithm>

using namespace std;

const long long MAX = 300'001;
const long long N_MAX = 1e9+7;
long long arr[MAX];
long long ans = -N_MAX;
long long c_ans = -N_MAX;
long long N;
int l, r;
void dfs(long long n, int depth){
	if(n > N)return;
	
	dfs(2*n, depth +1);
	
	if(l <= depth && depth <= r){
	if(c_ans + arr[n] < arr[n]){
		c_ans = arr[n];
	}
	else{
		c_ans += arr[n];
	}
	
	ans = max(ans, c_ans);
	}
	
	dfs(2*n+1, depth+1);
	
}


int main(){
	
	cin >> N;
	
	
	fill(arr, arr+MAX, N_MAX);
	
	for(long long i = 1; i <= N; i++){
		cin >> arr[i];
	}
	
	for(int i = 0; i <= 21; i++){
		for(int j = i; j <= 22; j++){
			c_ans = -N_MAX;
			l = i;
			r = j;
			dfs(1, 0);
		}
	}
	
	cout << ans;
	
	
	
}*/
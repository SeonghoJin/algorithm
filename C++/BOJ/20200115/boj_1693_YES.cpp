/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 18;
int dp[100001][MAX];
vector<int> adjlist[100001];

int make(int n, int k, int p){
	
	int& ret = dp[n][k];
	if(ret != -1)return ret;
	
	ret = k;
	
	for(int next : adjlist[n]){
		if(next == p)continue;
		
		int t = 987654321;
		for(int i = 1; i < MAX; i++){
			if(i == k)continue;
			t = min(t, make(next,i,n));
		}
		
		ret += t;
	}
	
	return ret; 
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int N;
	cin >> N;
	for(int i = 0; i < 100001; i++){
		fill(dp[i], dp[i]+MAX, -1);
	}
	for(int i = 0; i < N-1; i++){
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	
	int ans = 987654321;
	
	for(int i = 1; i < MAX; i++){
		ans = min(ans, make(1,i,0));
	}
	
	cout << ans;
	
}*/
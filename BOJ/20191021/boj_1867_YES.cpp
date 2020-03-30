#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,visit[501], matched[501];
vector<int> P[501];

int dfs(int num){
	if(visit[num])return 0;
	visit[num] = 1;
	
	for(int i = 0; i < P[num].size(); i++){
		int next = P[num][i];
		
		if(!matched[next] || dfs(matched[next])){
			matched[next] = num;
			return 1;
		}
	}
	return 0;
}
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	for(int i = 0; i < K; i++){
		int a, b;
		cin >> a >> b;
		P[a].push_back(b);
	}
	
	int ans = 0;
	
	for(int i = 1; i <= N; i++){
		fill(visit,visit+501,0);
		if(dfs(i))ans++;
	}
	cout << ans;
	
	
}
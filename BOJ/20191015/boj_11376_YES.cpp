#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int visit[2001];
vector<vector<int>> k;
int matched[2001];
int dfs(int n){
	if(visit[n])return 0;
	visit[n] = 1;
	
	for(int i = 0; i < k[n].size(); i++){
		int next = k[n][i];
		
		if(!matched[next] || dfs(matched[next])){
			matched[next] = n;
			return 1;
		}
	}
	return 0;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	k.push_back(vector<int>());
	for(int i = 0; i < N; i++){
		int T;
		cin >> T;
		vector<int> temp;
		while(T--){
			int t;
			cin >> t;
			temp.push_back(t);
		}
		k.push_back(temp);
		k.push_back(temp);
	}
	
	int ans = 0;
	
	for(int i = 1; i < 2*N-1; i++){
		fill(visit,visit+2*N-1,0);
		if(dfs(i))ans+=1;
	}
	cout << ans;
}

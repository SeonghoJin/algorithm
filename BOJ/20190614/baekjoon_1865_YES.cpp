/*
첫 번째 줄에는 테스트케이스의 개수 TC(1 ≤ TC ≤ 5)가 주어진다. 그리고 두 번째 줄부터 TC개의 테스트케이스가 차례로 주어지는데 각 테스트케이스의 첫 번째 줄에는 지점의 수 N(1 ≤ N ≤ 500), 도로의 개수 M(1 ≤ M ≤ 2500), 웜홀의 개수 W(1 ≤ W ≤ 200)이 주어진다. 그리고 두 번째 줄부터 M+1개의 줄까지 도로의 정보가 주어지는데 각 도로의 정보는 S, E, T 세 정수로 주어진다. S와 E는 연결된 지점의 번호, T는 이 도로를 통해 이동하는데 걸리는 시간을 의미한다. 그리고 M+2~M+W+1번째 줄까지 웜홀의 정보가 S, E, T 세 정수로 주어지는데 S는 시작 지점, E는 도착 지점, T는 줄어드는 시간을 의미한다. T는 10,000보다 작거나 같은 자연수 또는 0이다.

두 지점을 연결하는 도로가 한 개보다 많을 수도 있다. 지점의 번호는 1부터 N까지 자연수로 중복 없이 매겨져 있다.

출력
TC개의 줄에 걸쳐서 만약에 시간이 줄어들면서 출발 위치로 돌아오는 것이 가능하면 YES, 불가능하면 NO를 출력한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using point = pair<int ,int>;


int TC,N,M,W;
const int INF = 987654321;
bool bellman_ford(vector<vector<point>>& adj){
	
	vector<int> shortpass(501,INF);
	shortpass[1] = 0;
	bool flag = false;
	for(int j = 1; j <= N; j++){
		for(int i = 1; i <= N; i++){
		
			if(shortpass[i] >= INF ) continue;
		
			for(int j = 0; j < adj[i].size(); j++){
				int num = adj[i][j].first;
				int weight = adj[i][j].second+shortpass[i];
			
				if(shortpass[num] > weight)shortpass[num] = weight;
			
			}
		}
	}
	
	for(int i = 1; i <= N; i++){
		
			if(shortpass[i] >= INF ) continue;
		
			for(int j = 0; j < adj[i].size(); j++){
				int num = adj[i][j].first;
				int weight = adj[i][j].second+shortpass[i];
			
				if(shortpass[num] > weight){
					return true;
				}
			
			}
		}
	

	
	return false;
	
}


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> TC;
	
	while(TC--){
		cin >> N >> M >> W;
		vector<vector<point>> adj(501,vector<point>());
		for(int i = 0; i < M; i++){
			int a,b,c;
			cin >> a >> b >> c;
			adj[a].push_back(make_pair(b,c));
			adj[b].push_back(make_pair(a,c));
		}
		
		for(int i = 0; i < W; i++){
			int a,b,c;
			cin >> a >> b >> c;
			adj[a].push_back(make_pair(b,-c));
		}
		
		if(bellman_ford(adj))cout << "YES" << '\n';
		else cout << "NO" << '\n';
		
		
	}
}



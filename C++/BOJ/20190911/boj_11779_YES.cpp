/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

using vvpii = vector<vector<pair<int,int>>>;
using pii = pair<int, int>;

int main(){
	
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	
	vvpii adjli(N+1);
	
	for(int i = 0; i < M; i++){
		int a,b,c;
		cin >> a >> b >> c;
		adjli[a].push_back({b,c});
	}
	
	int start,end;
	cin >> start >> end;
	
	vector<int> route(N+1);
	vector<int> cost_(N+1,987654321);
	priority_queue<pii> pq;
	
	cost_[start] = 0;
	pq.push({0,start});
	
	while(!pq.empty()){
		
		pii temp = pq.top();
		pq.pop();
		int cost = -temp.first;
		int num = temp.second;
		
		for(int i = 0; i < adjli[num].size(); i++){
			
			int neighbor_cost = adjli[num][i].second+cost;
			int neighbor = adjli[num][i].first;
			
			if(neighbor_cost < cost_[neighbor]){
				cost_[neighbor] = neighbor_cost;
				route[neighbor] = num;
				pq.push({-(neighbor_cost),neighbor});
			}
			
		}
		
	}
	cout << cost_[end] << '\n';
	
	stack<int> s;
	
	int ss = end;
	while(ss != 0){
		s.push(ss);
		ss = route[ss];
	}
	cout << s.size() << '\n';
	
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	
	
	
}
*/
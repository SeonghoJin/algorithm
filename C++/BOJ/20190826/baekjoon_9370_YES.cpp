
#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

using vvpii = vector<vector<pair<int,int>>>; 
using vpii = vector<pair<int,int>>;
using pii = pair<int, int>;
vector<int> daijstra(vvpii& adjlist,int start){
	
	vector<int> shortest(adjlist.size(),987654321);
	shortest[start] = 0;
		
	priority_queue<pii> pq;
	pq.push(make_pair(0,start));
	
	while(!pq.empty()){
		
		pii temp = pq.top();
		pq.pop();
		
		int length = -temp.first;
		int number = temp.second;
		for(int i = 0; i < adjlist[number].size(); i++){
			int neighborlength = length+adjlist[number][i].second;
			int neighbornumber = adjlist[number][i].first;
			
			if(shortest[neighbornumber] > neighborlength){
				shortest[neighbornumber] = neighborlength;
				pq.push(make_pair(-neighborlength,neighbornumber));
			}
		}
		
	}
	
	return shortest;
	
}

int main(){
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		vector<int> candidtes;
		int n,m,t,s,g,h;
		cin >> n >> m >> t >> s >> g >> h;
		vvpii adjlist(n+1);
		
		for(int i = 0; i < m; i++){
			int a,b,c;
			cin >> a >> b >> c;
			adjlist[a].push_back(make_pair(b,c));
			adjlist[b].push_back(make_pair(a,c));
		}
		
		for(int i = 0; i < t; i++){
			int a;
			cin >> a;
			candidtes.push_back(a);
		}
		
		vector<int> shortest_s = daijstra(adjlist, s);
		vector<int> shortest_g = daijstra(adjlist, g);
		vector<int> shortest_h = daijstra(adjlist, h);
		vector<int> answer;
		for(int t = 0; t < candidtes.size(); t++){
			int i = candidtes[t];
			int s_can_i = shortest_s[i];
			
			int g_can_h = shortest_g[h];
			int s_can_g = shortest_s[g];
			int s_can_h = shortest_s[h];			
			int g_can_i = shortest_g[i];
			int h_can_i = shortest_h[i];
			
			int mi = min(g_can_h+s_can_g+h_can_i,g_can_h+s_can_h+g_can_i);
			if(mi == s_can_i){
				answer.push_back(i);
			}
			
			
		}
		
		sort(answer.begin(),answer.end());
		for(int i = 0; i < answer.size(); i++){
			cout << answer[i] << " ";
		}
		cout << '\n';
		
	}
	
}
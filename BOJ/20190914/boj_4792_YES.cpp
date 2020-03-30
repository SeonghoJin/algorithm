/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int parent[1001];

int find(int i){return i == parent[i] ? i : parent[i] = find(parent[i]);}

bool isUnion(int i, int j){return find(i) == find(j);}

void Union(int i, int j){
	parent[find(i)] = find(j);
}


int main(){
	
	while(1){
		int N, M, K;
		cin >> N >> M >> K;
		if(N == 0)break;
		
		priority_queue<pair<int, pair<int, int>>> pq1; 
		priority_queue<pair<int, pair<int, int>>> pq2; 
		queue<pair<char,pair<int,int>>> q;
		vector<int> visit(N+1,0);
		while(M--){
			char c;
			int a, b;
			cin >> c >> a >> b;
			pq1.push({(c == 'B' ? 1 : 0),{a,b}});
			pq2.push({(c == 'R' ? 1 : 0),{a,b}});
		}
		
		int Blue_count_Min = 0, Blue_count_MAX = 0,count = 0;
		for(int i = 0; i <= N; i++)parent[i] = i;
		
		while(!pq1.empty() && count != N-1){
			
			pair<int, pair<int, int>> temp = pq1.top();
			pq1.pop();
			int num1 = temp.second.first;
			int num2 = temp.second.second;
			int color = temp.first;
			
			if(isUnion(num1,num2))continue;
			count++;
			Blue_count_MAX +=(color == 1 ? 1 : 0);
			Union(num1,num2);
		
		}
		for(int i = 0; i <= N; i++)parent[i] = i;
		count = 0;
		while(!pq2.empty() && count != N-1){
			
			pair<int, pair<int, int>> temp = pq2.top();
			pq2.pop();
			int num1 = temp.second.first;
			int num2 = temp.second.second;
			int color = temp.first;
			
			if(isUnion(num1,num2))continue;
			count++;
			Blue_count_Min+=(color == 0 ? 1 : 0);
			Union(num1,num2);
		}
		cout << (Blue_count_Min <= K && K <= Blue_count_MAX)<< '\n';
				
	}
	
}

*/


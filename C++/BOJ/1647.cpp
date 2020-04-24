#include <bits/stdc++.h>

using namespace std;

const int MAX = 2*10e5+1;
int N, M;
int parent[MAX];

int find(int i){return i == parent[i] ? i : parent[i] = find(parent[i]);}

bool Union(int i, int j){
	int a = find(i);
	int b = find(j);
	if(a == b)return false;
	parent[a] = b;
	return true;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	
	cin >> N >> M;
	int ans = 0;
	
	priority_queue<pair<int,pair<int,int>>> pq;
	for(int i = 0; i < N; i++)parent[i] = i;
	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({-c,{a,b}});
	}
	int K = 0;
	int ma = 0;
	while(K != N-1){
		
		pair<int,pair<int,int>> temp = pq.top(); pq.pop();

		int start = temp.second.first;
		int end = temp.second.second;
		int cost = temp.first;
		
		if(Union(start,end)){
			ans+=-cost;
			K++;
			ma = max(ma, -cost);
		}
	}

	cout << ans - ma << '\n';
	
}
	



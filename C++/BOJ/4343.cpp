#include <bits/stdc++.h>

using namespace std;

const int MAX = 2*10e5+1;
int N, M;
int parent[501];

int find(int i){return i == parent[i] ? i : parent[i] = find(parent[i]);}

bool Union(int i, int j){
	int a = find(i);
	int b = find(j);
	if(a == b)return false;
	parent[a] = b;
	return true;
}

double dist(int a1, int b1, int a2, int b2){
	return sqrt((a1-a2)*(a1-a2) + (b1-b2) * (b1-b2));
}




int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	int T;
	cin >> T;
	while(T--){
	cin >> N >> M;
	
	priority_queue<pair<double,pair<int,int>>> pq;
	vector<pair<int,int>> where;
	for(int i = 0; i < M; i++)parent[i] = i;
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		where.push_back({a,b});
	}

	for(int i = 0; i < M; i++){
		for(int j = i+1; j < M; j++){
			int a1 = where[i].first;
			int b1 = where[i].second;
			int a2 = where[j].first;
			int b2 = where[j].second;
			pq.push({-dist(a1,b1,a2,b2),{i,j}});
		}
	}

	int K = 0;
	double ma = 0;
	int k = M- N;
	while(K != k && !pq.empty()){
		
		pair<double,pair<int,int>> temp = pq.top(); pq.pop();

		int start = temp.second.first;
		int end = temp.second.second;
		double cost = -temp.first;
		
		if(Union(start,end)){
			K++;
			ma = max(cost,ma);
		}
	}

	printf("%.2f\n", ma);
	}	
}
	
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using pii = pair<int ,int>;
const int MAX = 1e5;
int N, M, Q;
pair<int,pii> edges[MAX];
pii qry[MAX];
int p[MAX];
int c[MAX];


int lo[MAX], hi[MAX];
pii result[MAX];
	
int find(int i){return i == p[i] ? i : p[i] = find(p[i]);}

bool isUnion(int i, int j){
	int a = find(i);
	int b = find(j);
	if(a == b)return false;
	p[a] = b;
	c[b] += c[a];
	return true;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
		edges[i].second.first--;
		edges[i].second.second--;
	}
	sort(edges,edges+M);
	
	cin >> Q;
	
	for(int i = 0; i < Q; i++){cin >> qry[i].first >> qry[i].second;
							  qry[i].first--;
							  qry[i].second--;}
	
	fill(hi, hi+Q, M+1);
	
	while(1){
		bool flag = false;
		
		vector<int> G[MAX+1];
		
		for(int i = 0; i < Q; i++){
			if(lo[i] + 1 < hi[i]){
				flag = true;
				G[(lo[i]+hi[i])/2].push_back(i);
			}
		}
		
		if(!flag)break;
		
		for(int i = 0; i < N; i++){p[i] = i; c[i] = 1;}
		
		for(int i = 0; i < M; i++){
			int u = edges[i].second.first, v = edges[i].second.second, w = edges[i].first;
			isUnion(u,v);
			
			for(int j : G[i+1]){
				int a = find(qry[j].first), b = find(qry[j].second);
				if(a == b){
					hi[j] = i+1;
					result[j].first = w;
					result[j].second = c[a];
				}
				else lo[j] = i+1;
			}
		
		}
		
	}
	
	for(int i = 0; i < Q; i++){
		if(lo[i] == M)cout << -1 << '\n';
		else{ cout << result[i].first << " " << result[i].second << '\n';}
	}
	
}
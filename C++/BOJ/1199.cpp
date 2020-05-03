#include<bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> adj;

struct edge{
	int cnt, to;
	edge* reverse;

	edge(): edge(-1,0){}
	edge(int to, int cnt) : to(to), cnt(cnt), reverse(nullptr){

	}
};

vector<edge*> edges[1001];

void find(int n){

	for(edge* e : edges[n]){
		if(e->cnt > 0){
			e->cnt--;
			e->reverse->cnt--;

			find(e->to);
		}
	}
	cout << n+1<< " ";

}

int main()
{

	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N;
	
	adj = vector<vector<int>>(N,vector<int>(N));

	for(int i = 0; i < N; i++){
		int sum = 0;
		for(int j = 0; j < N; j++){
			cin >> adj[i][j];
			sum += adj[i][j];
		}
		if(sum & 1){
			cout << -1;
			return 0;
		}
	}

	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			if(adj[i][j] > 0){
				edge* here = new edge(j,adj[i][j]);
				edge* rev = new edge(i,adj[i][j]);
				here->reverse = rev;
				rev->reverse = here;
				edges[i].push_back(here);
				edges[j].push_back(rev);	
			}			
		}
	}

	find(0);
	

}
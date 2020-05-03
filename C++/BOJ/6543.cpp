#include<bits/stdc++.h>

using namespace std;
const int MAX = 5001;
vector<int> adj[MAX];
int cur = 1;
int gcur = 1;
stack<int> s;
int cnt[MAX];
int group[MAX];

int SCC(int n){
	int here = cnt[n] = cur++;
	s.push(n);
	for(int next : adj[n]){

		if(cnt[next] == 0){
			cnt[n] = min(cnt[n], SCC(next));
		}
		else if(group[next] == 0){
			cnt[n]= min(cnt[n], cnt[next]);
		}

	}

	if(cnt[n] == here){

		while(1){
			int t = s.top(); s.pop();
			group[t] = gcur;			
			if(t == n){
				break;
			}
		}		
		gcur++;
	}
	return cnt[n];
}



int main()
{

	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	while(1){
		int N, M;
		cin >> N;
		if(N == 0)return 0;
		cin >> M;
		cur = 1;
		gcur = 1;
		for(int i = 1; i <= N; i++){
			cnt[i] = 0;
			group[i] = 0;
			adj[i].clear();
		}

		for(int i = 0; i < M; i++){
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}

		for(int i = 1; i <= N; i++){
			if(cnt[i] == 0){
				SCC(i);
			}
		}
		vector<int> check(gcur+10);
		for(int i = 1; i <= N; i++){
			
			for(int next : adj[i]){
				int hg = group[i];
				int ng = group[next];
				if(hg == ng)continue;
				check[hg] = 1;	
			}
		}

		for(int i = 1; i <= N; i++){
			//cout << group[i] << " ";
			if(check[group[i]] == 0){
				cout << i << " ";
			}
		}	
		cout << '\n';	

	}
	
}
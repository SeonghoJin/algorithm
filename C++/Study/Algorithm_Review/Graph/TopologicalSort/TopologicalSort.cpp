#include<bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> v(N+1);
	vector<int> indeg(N+1);
	for(int i = 0; i < M; i++){
		int T; 
		cin >> T;

		int start,end;
		cin >> start;

		for(int j = 0; j < T-1; j++){
			cin >> end;
			indeg[end]++;
			v[start].push_back(end);
			start = end;
		}

	}

	vector<int> ans;

	queue<int> q;
	
	for(int i = 1; i <= N; i++){
		if(indeg[i] == 0){
			q.push(i);
		}
	}

	while(!q.empty()){
		int here = q.front(); q.pop();
		ans.push_back(here);
		for(int i = 0; i < v[here].size(); i++){
			int next = v[here][i];
			indeg[next]--;
			if(indeg[next] == 0)q.push(next);
		}
	}

	if(ans.size() != N){
		cout << 0;
		return 0;
	}	
	else{
		for(int i : ans){
			cout << i << '\n';
		}
	}

}
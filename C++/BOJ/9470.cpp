#include<bits/stdc++.h>

using namespace std;


int main()
{
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int T;
	cin >> T;

	while(T--){
		int K,M,P;
		cin >> K >> M >> P;

		vector<int> ind(M+1);
		vector<int> ans(M+1);
		vector<vector<int>> adj(M+1,vector<int>());
		vector<vector<int>> inadj(M+1,vector<int>());

		vector<int> topo;

		for(int i = 0; i < P; i++){
			int a, b;
			cin >> a >> b;
			ind[b]++;
			adj[a].push_back(b);
			inadj[b].push_back(a);
		}
		queue<int> q;
		for(int i = 1; i <= M; i++){
			if(ind[i] == 0){
				q.push(i);
				ans[i] = 1;
			}
		}

		while(!q.empty()){
			int here = q.front(); q.pop();
			topo.push_back(here);
			//cout << here << " ";
			for(int next : adj[here]){
				ind[next]--;
				if(ind[next] == 0){
					q.push(next);
				}
			}
		}
		//cout << '\n';
		int temp = 0;
		for(int here : topo){
			pair<int, int> check = {ans[here],0};
			//cout << here <<  " : " ;
			for(int before : inadj[here]){
				//cout << before << " ";
				if(check.first == ans[before]){
					check.second++;
				}
				else if(check.first < ans[before]){
					check.first = ans[before];
					check.second = 1;
				}
			}
			//cout << '\n';
			if(check.second > 1)check.first++;
			ans[here] = check.first;
			temp = max(temp, ans[here]);
		}
		
		cout << K << " " << temp << '\n';

	}

}
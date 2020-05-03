#include<bits/stdc++.h>

using namespace std;

const int MAX = 200001;

vector<vector<int>> adj;

int N, M;

int rev(int n)
{
	return n >= M? n - M : n + M;
}

int gcur = 1;
int cur = 1;
vector<int> group;
vector<int> cnt;
stack<int> s;
int SCC(int n){
	int result = cnt[n] = cur++;

	s.push(n);

	for(int next : adj[n]){

		if(cnt[next] == 0){
			cnt[n] = min(cnt[n], SCC(next));
		}
		else if(group[next] == 0){
			cnt[n] = min(cnt[n], cnt[next]);
		}

	}

	if(result == cnt[n]){

		while(1){
			int t = s.top(); s.pop();
			group[t] = gcur;
			if(t == n)break;
		}
		gcur++;


	}
	return cnt[n];
}


int main()
{

	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	vector<int> state;
	cin >> N >> M;
	state = vector<int>(2*M);
	vector<vector<int>> room(N,vector<int>());
	group = vector<int>(2*M);
	cnt = vector<int>(2*M);
	for(int i = 0; i < N; i++){
		cin >> state[i];
	}

	for(int i = 0; i < M; i++){
		int n;
		cin >> n;
		for(int j = 0; j < n; j++){
			int k;
			cin >> k;
			room[k-1].push_back(i);
		}
	}
	adj = vector<vector<int>>(2*M,vector<int>());	
	for(int i = 0; i < N; i++){
		int x = room[i][0];
		int y = room[i][1];
		if(state[i] == 1){
			adj[rev(y)].push_back(rev(x));
			adj[x].push_back(y);
			adj[y].push_back(x);
			adj[rev(x)].push_back(rev(y));
		}
		else{
			adj[y].push_back(rev(x));
			adj[x].push_back(rev(y));
			adj[rev(y)].push_back(x);
			adj[rev(x)].push_back(y);
		}
	}

	for(int i = 0; i < 2*M; i++){
		if(cnt[i] == 0){
			SCC(i);
		}
	}

	for(int i = 0; i < M; i++){
		if(group[i] == group[i+M]){
			cout << 0 << '\n';
			return 0;
		}
	}
	cout << 1;

}
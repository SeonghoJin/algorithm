#include <bits/stdc++.h>

using namespace std;

vector<int> adjlist[2001];

int mapping(int n){
	
	return n > 0 ? 2 * n - 1  : 2 * abs(n);
}

int neg(int n){
	return n & 1 ? n + 1 : n - 1;
}
int cur = 1; int group_cur = 1;
int in[2001]; int group[2001];
stack<int> s;
int makeSCC(int n){
	int here = in[n] = cur++;
	s.push(n);
	for(int i = 0; i < adjlist[n].size(); i++){
		int next = adjlist[n][i];

		if(in[next] == 0){
			here = min(here, makeSCC(next));
		}
		else if(group[next] == 0){
			here = min(here, in[next]);
		}
	}

	
	if(here == in[n]){

		while(1){
			int temp = s.top(); s.pop();
			group[temp] = group_cur;
			if(temp == n)break;
		}
		group_cur++;
	}

	return here;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	while(1){
		cur = 1; group_cur = 1;
		fill(group,group+2001,0);
		fill(in,in+2001,0);
		stack<int> n_s;
		s.swap(n_s);
		for(int i = 0; i < 2001; i++)adjlist[i].clear();
		int N, M;
		cin >> N;
		if(cin.eof())break;
		cin >> M;

		for(int i = 0; i < M; i++){
			int a, b;
			cin >> a >> b;
			int c = mapping(a);
			int d = mapping(b);
			if(a == b){
				adjlist[neg(c)].push_back(c);
			}
			else{
			adjlist[neg(d)].push_back(c);
			adjlist[neg(c)].push_back(d);
			}
		}
	
		for(int i = 1; i <= 2*N; i++){
			if(group[i] == 0)makeSCC(i);
		}
	

		int flag = true;
		for(int i = 1; i <= N; i++){
			if(group[2*i] == group[2*i -1])flag = false;
		}
		cout << flag << '\n';
	}

	

}

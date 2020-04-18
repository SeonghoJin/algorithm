/*
	//  Generator
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;
const int MAX = 100001;
int V,E,low[MAX],t_low[MAX],state[MAX],t_state[MAX],cnt,t_cnt;
stack<int> s;
stack<int> t_s;
vector<int> adj[MAX];
const int VISIT = 1;
const int NOT = 0;
const int EXPLORED = 2;
vector<vector<int>> SCC;
vector<vector<int>> t_SCC;

int SCC_count = 0;
int dfs1(int n){
	low[n] = ++cnt;
	s.push(n);
	state[n] = EXPLORED;
	int result = low[n];
	for(int i = 0; i < adj[n].size(); i++){
		int next = adj[n][i];
		
		if(state[next] == NOT){
			result = min(result, dfs1(next));
		}
		else if(state[next] == EXPLORED){
			result = min(result, low[next]);
		}
	}
	
	if(result == low[n]){
		
		vector<int> scc;
		
		while(1){
			int t = s.top();
			s.pop();
			scc.push_back(t);
			state[t] = VISIT;
			if(t == n)break;
		}
		sort(scc.begin(),scc.end());
		SCC.push_back(scc);
		SCC_count++;
	}
	
	return result;
}

int dfs2(int n){
	t_low[n] = ++cnt;
	t_s.push(n);
	t_state[n] = EXPLORED;
	int result = t_low[n];
	for(int i = 0; i < adj[n].size(); i++){
		int next = adj[n][i];
		
		if(t_state[next] == NOT){
			result = min(result, dfs2(next));
		}
		else if(t_state[next] == EXPLORED){
			result = min(result, t_low[next]);
		}
	}
	
	if(result == t_low[n]){
		
		vector<int> scc;
		
		while(1){
			int t = t_s.top();
			t_s.pop();
			scc.push_back(t);
			if(t == n)break;
		}
		sort(scc.begin(),scc.end());
		t_SCC.push_back(scc);
		
	}
	t_state[n] = VISIT;
	return result;
}

bool check(){
	if(SCC.size() != t_SCC.size())return false;
	for(int i = 0; i < SCC.size(); i++){
		if(SCC[i].size() != t_SCC[i].size())return false;
	}
	
	for(int i = 0; i < SCC.size(); i++){
		for(int j = 0; j < SCC[i].size(); i++){
			if(SCC[i][j] != t_SCC[i][j])return false;
		}
	}
	return true;
}

int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	srand(time(NULL));
	
	int V = 1+rand()%20;
	int E = 1+ rand()%V +V/2;
 	//cin >> V >> E;
	cout <<"V = "<<  V << " "<< "E = " << E << '\n';
	for(int i = 0; i < E; i++){
		int a,b;
		a = 1 + rand()%(V-1);
		b = a;
		while(a == b){
			b = 1 + rand()%(V-1);
		}
		cout << a << " " << b << '\n';
		adj[a].push_back(b);
	}
	
	for(int i = 1; i <= V; i++){
		if(state[i] == NOT)dfs1(i);
		if(t_state[i] == NOT)dfs2(i);
	}
	
	sort(SCC.begin(),SCC.end());
	cout << SCC.size() << '\n';
	for(int i = 0; i < SCC.size(); i++){
		for(int j = 0; j < SCC[i].size(); j++){
			cout << SCC[i][j] << " ";
		}
		cout << -1 << '\n';
	}
	cout << '\n';
	
	sort(t_SCC.begin(),t_SCC.end());
	cout << t_SCC.size() << '\n';
	for(int i = 0; i < t_SCC.size(); i++){
		for(int j = 0; j < t_SCC[i].size(); j++){
			cout << t_SCC[i][j] << " ";
		}
		cout << -1 << '\n';
	}
	
	cout << check();
	
}
*/
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;
const int MAX = 100001;
int V,E,low[MAX],t_low[MAX],state[MAX],t_state[MAX],cnt,t_cnt;
stack<int> s;
stack<int> t_s;
vector<int> adj[MAX];
const int VISIT = 1;
const int NOT = 0;
const int EXPLORED = 2;
vector<vector<int>> SCC;
vector<vector<int>> t_SCC;

int SCC_count = 0;
int dfs1(int n){
	low[n] = ++cnt;
	s.push(n);
	state[n] = EXPLORED;
	cout << "정점 " << n << ": " << low[n] << '\n';
	int result = low[n];
	for(int i = 0; i < adj[n].size(); i++){
		int next = adj[n][i];
		if(state[next] == NOT){
			cout << "정점 " << n << "->" << next << '\n';
			result = min(result, dfs1(next));
		}
		else if(state[next] == EXPLORED){
			cout << "reverse : 정점 " << n << "->" << next << '\n';
			result = min(result, low[next]);
		}
	}
	if(result == low[n]){
		vector<int> scc;
		cout << "정점 " << n << "  stackOutstart\n";
		while(1){
			int t = s.top();
			s.pop();
			cout << "정점 " << t << "  stackOut\n";
			scc.push_back(t);
			state[t] = VISIT;
			if(t == n)break;
		}
		sort(scc.begin(),scc.end());
		SCC.push_back(scc);
		SCC_count++;
	}
	
	return result;
}

int dfs2(int n){
	t_low[n] = ++cnt;
	t_s.push(n);
	t_state[n] = EXPLORED;
	cout << "정점 " << n << ":" << low[n] << '\n';
	int result = t_low[n];
	for(int i = 0; i < adj[n].size(); i++){
		int next = adj[n][i];
		
		if(t_state[next] == NOT){
			cout << "정점 " << n << "->" << next << '\n';
			result = min(result, dfs2(next));
		}
		else if(t_state[next] == EXPLORED){
			cout << "reverse : 정점 " << n << "->" << next << '\n';
			result = min(result, t_low[next]);
		}
	}
	if(result == t_low[n]){
		cout << "정점 " << n << "  stackOutstart\n";
		vector<int> scc;
		
		while(1){
			int t = t_s.top();
			t_s.pop();
			scc.push_back(t);
			cout << "정점 " << t << "  stackOut\n";
			if(t == n)break;
		}
		sort(scc.begin(),scc.end());
		t_SCC.push_back(scc);
	}
	t_state[n] = VISIT;
		
	return result;
}


int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> V >> E;
	
	for(int i = 0; i < E; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	
	for(int i = 1; i <= V; i++){
		if(state[i] == NOT)dfs1(i);
	}
	cout << "\n\n";
	for(int i = 1; i <= V; i++){
		if(t_state[i] == NOT)dfs2(i);
	}
	
	sort(SCC.begin(),SCC.end());
	
	cout << SCC.size() << '\n';
	for(int i = 0; i < SCC.size(); i++){
		for(int j = 0; j < SCC[i].size(); j++){
			cout << SCC[i][j] << " ";
		}
		cout << -1 << '\n';
	}
	cout << '\n';
	
	sort(t_SCC.begin(),t_SCC.end());
	cout << t_SCC.size() << '\n';
	for(int i = 0; i < t_SCC.size(); i++){
		for(int j = 0; j < t_SCC[i].size(); j++){
			cout << t_SCC[i][j] << " ";
		}
		cout << -1 << '\n';
	}
	
	
}

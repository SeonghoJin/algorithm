#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int Unvisited = 0;
const int Explored = 1;
const int Visitied = 2;
int P = 0;	
void _EdgeAttriCheck_usingST(vector<int>& state,vector<int>& Parent,vector<int>& num, vector<int>& low,vector<vector<int>>& adj,int n, int& P){
	/*cout << n << endl;*/
	num[n] = low[n] = P++; 
	state[n] = Explored;
	vector<int> neighbor = adj[n];
	
	for(int i = 0; i < neighbor.size(); i++){
		int t = neighbor[i];
		
		if(state[t] == Unvisited){
			Parent[t] = n;
			_EdgeAttriCheck_usingST(state,Parent,num,low,adj,t,P);
			low[n] = min(low[n],low[t]);
		}
		else{
				if(state[t] == Explored){
				low[n] = min(low[n], low[t]);
				/*cout << "REVERSE_EDGE " << n << "->" << t << endl;
				cout << "REVERSE_EDGE IN SPANNING TREE " << num[n] << "->" << num[t] << endl;*/
				}
				else{
					/*cout << "FOWARRD_EDGE " << n << "->" << t << endl;*/
				}
			
		}
	}
	
	/*if(low[n] < num[n]){
		cout << "IN CIRCLE VERTEX " << n  << " ANCESTER " << low[n] <<endl;
		cout << "IN CIRCLE VERTEXT IN SPANNING TREE " << num[n] << endl;
	}*/
	
	state[n]=Visitied;
}

void EdgeAttriCheck_usingST(vector<vector<int>>& adj){
	
	int N = adj.size();
	vector<int> state(N),Parent(N),num(N),low(N);
	
	int C = 0;
	for(int i = 0; i < N; i++){
		if(state[i] == Unvisited)
	/*cout << "COMPONENT " << 1 + C++ << '\n' */ _EdgeAttriCheck_usingST(state,Parent,num,low,adj,i,P);
	}
	
	
	vector<vector<int>> SCC;
	map<int ,int> mapping;
	int NUM= 0;
	for(int i = 0; i < N; i++){
		/*cout << "i =" << i << " " << num[i]  << " " << low[i] << '\n'; */
	}
	for(int i = 0; i < N; i++){
		int p = low[i];
		if(mapping.find(p) == mapping.end()){
			SCC.push_back(vector<int>(1,i));
			mapping.push(make_pair(p,NUM++));
		}
		else{
			SCC[mapping.find(p)->second].push_back(i);
		}
	}
	cout << SCC.size() << '\n';
	sort(SCC.begin(),SCC.end());
	for(int i = 0; i < SCC.size(); i++){
		sort(SCC[i].begin(),SCC[i].end());
		for(int j = 0; j < SCC[i].size(); j++){
			cout << SCC[i][j]+1 << " ";
		}
		cout << -1;
		cout << endl;
	}
	
}

int main(){
	
	int E;
	int N;
	cin >> N >>E;
	vector<vector<int>> adj(N,vector<int>());
	for(int i = 0; i < E; i++){
		int a,b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
	}
	EdgeAttriCheck_usingST(adj);
}
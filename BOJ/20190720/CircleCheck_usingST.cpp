/*
#include <iostream>
#include <vector>
using namespace std;
const int Unvisited = 0;
const int Explored = 1;
const int Visitied = 2;

void _EdgeAttriCheck_usingST(vector<int>& state,vector<int>& Parent,vector<int>& num, vector<int>& low,vector<vector<int>>& adj,int n, int& P){
	cout << n << endl;
	num[n] = low[n] = P; 
	state[n] = Explored;
	vector<int> neighbor = adj[n];
	
	for(int i = 0; i < neighbor.size(); i++){
		int t = neighbor[i];
		
		if(state[t] == Unvisited){
			Parent[t] = n;
			P+=1;
			_EdgeAttriCheck_usingST(state,Parent,num,low,adj,t,P);
			low[n] = min(low[n],low[t]);
		}
		else{
			if(Parent[n] != t ){
				if(state[t] == Explored){
				low[n] = min(low[n], low[t]);
				cout << "REVERSE_EDGE " << n << "->" << t << endl;
				cout << "REVERSE_EDGE IN SPANNING TREE " << num[n] << "->" << num[t] << endl;
				}
				else{
					cout << "FOWARRD_EDGE " << n << "->" << t << endl;
					cout << "FORWARD_EDGE IN SPANNING TREE " << num[n] << "->" << num[t] << endl;
				}
			}
		}
	}
	
	if(low[n] < num[n]){
		cout << "IN CIRCLE VERTEX " << n  << " ANCESTER " << low[n] <<endl;
		cout << "IN CIRCLE VERTEXT IN SPANNING TREE " << num[n] << endl;
	}
	
	state[n]=Visitied;
}

void EdgeAttriCheck_usingST(vector<vector<int>>& adj){
	
	int N = adj.size();
	vector<int> state(N),Parent(N),num(N),low(N);
	
	int P = 0;
	for(int i = 0; i < N; i++){
		if(state[i] == Unvisited)
	_EdgeAttriCheck_usingST(state,Parent,num,low,adj,i,P);
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
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	EdgeAttriCheck_usingST(adj);
}*/
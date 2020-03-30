#include <iostream>
#include <stack>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 5000; 
int N, M;
int cnt = 1, scnt =1, group[2*MAX+1],low[2*MAX+1];
vector<int> adj[2*MAX+1];
stack<int> s;

int rev(int t){
	return (t > N ? t-N : t+N);
}

int makeSCC(int n){
	int result = low[n] = cnt++;
	
	s.push(n);
	
	for(int i = 0; i < adj[n].size(); i++){
		int next = adj[n][i];
		if(low[next] == 0){
			result = min(result, makeSCC(next));
		}
		else if(!group[next]){
			result = min(result, low[next]);
		}
	}
	
	if(result == low[n]){
		
		while(1){
			int t = s.top(); s.pop();
			group[t] = scnt;
			if(t == n){break;}
		}
		scnt++;
	}
	
	return result;
}

int main(){
	
	//R 0 B 1
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int a[3];
		char b[3];
		
		for(int i = 0; i < 3; i++){
			cin >> a[i] >> b[i];
			if(b[i] == 'R')a[i] = a[i]+N;
		}
		
		for(int i = 0; i < 3; i++){
			
			adj[rev(a[i])].push_back(a[(i+1)%3]);
			adj[rev(a[(i+1)%3])].push_back(a[i]);
		}
		
	}
	for(int i = 1; i <= 2*N; i++){
		if(low[i] == 0)makeSCC(i);
	}
	int fl = 1;
	for(int i = 1; i <= N; i++){
		if(group[i] == group[rev(i)]){fl = 0; break;}
	}
	
	if(fl){
		for(int i = 1; i <= N; i++){
			cout << (group[i] < group[i+N] ? 'B' : 'R');
		}
	}
	else{cout << -1;}
	
}
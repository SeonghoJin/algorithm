/*#include <iostream>
#include <algorithm>
using namespace std;

int Arr[1000001];
int parent[1000001];
int sz[1000001];
int find(int i){
	return (i == parent[i] ? i : parent[i] = find(parent[i]));}

bool Union(int i, int j){
	int a = find(parent[i]);
	int b = find(parent[j]);
	if(a == b)return false;
	
	parent[a] = b;
	sz[b] += sz[a];
	
	return true;
}

int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int N;
	cin >> N;
	for(int i = 0; i <= 1000000; i++){
		parent[i] = i;
		sz[i] = 1;
	}
	while(N--){
		char c;
		cin >> c;
		if(c == 'I'){
			int a, b;
			cin >> a >> b;
			Union(a,b);
		}
		else{
			int t;
			cin >> t;
			cout << sz[find(t)] << '\n';
		}
	}
}*/
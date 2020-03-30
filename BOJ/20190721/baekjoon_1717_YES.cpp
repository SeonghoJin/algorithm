/*
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent(1'000'000);

int isParent(int i){
	return parent[i] == i ? i : parent[i] = isParent(parent[i]);
}

bool isSameSet(int i, int j){
	return isParent(i) == isParent(j);
}


void Union(int i, int j){
	
	if(!isSameSet(i,j))parent[isParent(i)] = j;
	
}


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		parent[i] = i;
	}
	
	for(int i = 0; i < m; i++){
		int a,b,c;
		cin >> a >> b >> c;
		if(a == 0){
			Union(b,c);
		}
		else{
			if(isSameSet(b,c)){
				cout << "YES" << '\n';
			}
			else{
				cout << "NO" << '\n';
			}
		}
	}
}*/
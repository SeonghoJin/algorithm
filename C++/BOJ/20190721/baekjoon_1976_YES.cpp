#include <iostream>
#include <vector>

using namespace std;
int n, m;
	
vector<int> parent(201);

int isParent(int i){
	return parent[i] == i ? i : parent[i] = isParent(parent[i]);
}

bool isSameSet(int i, int j){
	return isParent(i) == isParent(j);
}


void Union(int i, int j){
	
	if(!isSameSet(i,j))parent[isParent(i)] = j;
	
}

void print(){
	int p,t;
	cin >> p;

	for(int i = 0; i < m-1; i++){
		cin >> t;
		if(!isSameSet(p,t)){cout << "NO"; return;}
		p = t;
	}
	cout << "YES";
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> n >> m;
	
	for(int i = 1; i <=n; i++){
		parent[i] = i;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int t;
			cin >> t;
			if(t == 1){Union(i,j);}
		}
	}
	
	print();
}
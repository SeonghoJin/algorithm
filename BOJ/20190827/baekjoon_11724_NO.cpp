#include <iostream>
#include <vector>

using namespace std;

vector<int> v(1001);
int N;

int find(int i){
	return i == v[i] ? i : v[i] = find(v[i]);
}


bool isunion(int i, int j){
	return find(i) == find(j);
}

void uni(int i, int j){
	if(!isunion(i,j)){
		N--;
		v[find(i)] = find(j);
	}
}




int main(){
	int  M;
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++){
		v[i] = i;
	}
	
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		uni(a,b);
	}
	
	
	cout << N;
}
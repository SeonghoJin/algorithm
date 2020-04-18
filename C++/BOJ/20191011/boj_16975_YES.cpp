/*#include <iostream>
#include <cmath>
using namespace std;

int N;
long long t[400000];
long long val[100000];

void update(int i, int j, int k, int root = 1, int root_i = 0, int root_j = N-1){
	if((i == root_i && j == root_j) || (root_i >= root_j)){t[root] += k; return;}
	
	int mid = (root_i+root_j)/2;
	
	if(i <= mid ){
		update(i,min(mid,j),k,root*2,root_i, mid);
	}
	if(j > mid){
		update(max(mid+1,i),j,k,root*2+1,mid+1, root_j);
	}
	
}

long long search(int n, int root = 1, int root_i = 0, int root_j = N-1){
	
	if(n == root_i && root_i == root_j){return t[root];}
	
	int mid = (root_i+root_j)/2;
	
	if(root_i <= n && n <= mid){
		return search(n,root*2,root_i,mid)+t[root];
	}
	else{
		return search(n,root*2+1,mid+1,root_j)+t[root];
	}
	
}

int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> val[i];
	}
	
	int Q;
	cin >> Q;
	
	for(int i = 0; i < Q; i++){
		int a;
		cin >> a;
		if(a == 1){
			int b,c,d;
			cin >> b >> c >> d;
			b--, c--;
			update(b,c,d);
		}
		else{
			int b;
			cin >> b;
			b--;
			cout << search(b)+val[b] << '\n';
		}
	}
}*/
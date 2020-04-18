#include <iostream>
#include <cmath>
using namespace std;

const int MOD = 1'000'000'007;

int N, M, K;
long long v[100000];
long long Arr1[100000*4];
long long Arr2[100000*4];

long long makeRMQ_MIN(int root, int i, int j){
	if(i == j){Arr1[root] = v[i]; return Arr1[root];}
	
	int mid = (i+j)/2;
	
	long long lv = makeRMQ_MIN(root*2,i,mid);
	long long rv = makeRMQ_MIN(root*2+1,mid+1,j);
	
	Arr1[root] = min(lv,rv);
	
	return Arr1[root];
}

long long multi_MIN(int i, int j, int root = 1, int root_i = 0, int root_j = N-1){
	
	if(root_i == i && root_j == j)return Arr1[root];
	
	int mid = (root_i+root_j)/2;
	if(j <= mid){
		return multi_MIN(i,j,root*2,root_i,mid);
	}
	
	if(mid < i){
		return multi_MIN(i,j,root*2+1,mid+1,root_j);
	}
	
	return min(multi_MIN(i,mid,root*2,root_i,mid),multi_MIN(mid+1,j,root*2+1,mid+1,root_j));
}

void change_MIN(int idx, int c, int root = 1, int root_i = 0, int root_j = N-1){
	
	if(root_i == root_j && root_j == idx){
		v[idx] = c;
		Arr1[root] = c;
		return; 
	}
	
	int mid = (root_i+root_j)/2;
	
	if(idx <= mid){
		change_MIN(idx, c, root*2, root_i, mid);
	}
	
	if(idx > mid){
		change_MIN(idx, c, root*2+1, mid+1, root_j);
	}
	
	Arr1[root] = min(Arr1[root*2],(Arr1[root*2+1]));
	
}

long long makeRMQ_MAX(int root, int i, int j){
	if(i == j){Arr2[root] = v[i]; return Arr2[root];}
	
	int mid = (i+j)/2;
	
	long long lv = makeRMQ_MAX(root*2,i,mid);
	long long rv = makeRMQ_MAX(root*2+1,mid+1,j);
	
	Arr2[root] = max(lv,rv);
	
	return Arr2[root];
}

long long multi_MAX(int i, int j, int root = 1, int root_i = 0, int root_j = N-1){
	
	if(root_i == i && root_j == j)return Arr2[root];
	
	int mid = (root_i+root_j)/2;
	if(j <= mid){
		return multi_MAX(i,j,root*2,root_i,mid);
	}
	
	if(mid < i){
		return multi_MAX(i,j,root*2+1,mid+1,root_j);
	}
	
	return max(multi_MAX(i,mid,root*2,root_i,mid),multi_MAX(mid+1,j,root*2+1,mid+1,root_j));
}

void change_MAX(int idx, int c, int root = 1, int root_i = 0, int root_j = N-1){
	
	if(root_i == root_j && root_j == idx){
		v[idx] = c;
		Arr2[root] = c;
		return; 
	}
	
	int mid = (root_i+root_j)/2;
	
	if(idx <= mid){
		change_MAX(idx, c, root*2, root_i, mid);
	}
	
	if(idx > mid){
		change_MAX(idx, c, root*2+1, mid+1, root_j);
	}
	
	Arr2[root] = max(Arr2[root*2],(Arr2[root*2+1]));
	
}


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		cin >> v[i];
	}
	makeRMQ_MIN(1,0,N-1);
	makeRMQ_MAX(1,0,N-1);
	
	while(M--){
		int a, b;
		cin >> a >> b;
		a--,b--;
		cout << multi_MIN(a,b) << " " << multi_MAX(a,b) << '\n';
	}
}

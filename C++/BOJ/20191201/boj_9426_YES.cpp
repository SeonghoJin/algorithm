#include <iostream>

using namespace std;

const int MAX = 1'200'001; 

int N, M;
int segtree[MAX];
int arr[MAX];

void update(int k, int differ, int root = 1, int root_i = 0, int root_j = MAX-1){
	if(root_j < k || root_i > k)return;
	segtree[root]+=differ;
	if(root_i == root_j)return;
	int mid = (root_i+root_j) >> 1;
	update(k,differ,root*2,root_i,mid);
	update(k,differ,root*2+1,mid+1,root_j);
}

int find(int k, int root = 1, int root_i = 0, int root_j = MAX-1){
	if(root_i == root_j){return root_i;}
	int mid = (root_i + root_j) >> 1;
	int lct = segtree[root*2];
	if(k <= lct){return find(k,root*2,root_i,mid);}
	else{return find(k-lct,root*2+1,mid+1,root_j);}
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	int i = 0;
	int ans = 0;
	for(i = 0; i < M; i++){
		update(arr[i],1);
	}
	ans += find((M+1)/2);
	for(i; i < N; i++){
		update(arr[i-M],-1);
		update(arr[i],1);
		ans+= find((M+1)/2);
	}
	cout << ans;
	
	
}
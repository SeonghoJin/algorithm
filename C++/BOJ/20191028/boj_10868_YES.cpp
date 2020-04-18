/*
#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 100000;

int arr[MAX];
int tree[4*MAX];

int search(int left, int right, int num, int n_left, int n_right){
	if(left == n_left && right == n_right){return tree[num];}
	int mid = (n_left+n_right)/2;
	
	int ret = 2100000000;
	if(left <= mid)ret = min(ret, search(left,min(right,mid),2*num, n_left, mid));
	if(right > mid)ret = min(ret, search(max(mid+1,left),right,2*num+1,mid+1,n_right));
	return ret;
}

void makeSeg(int num, int n_left, int n_right){
	if(n_left == n_right){tree[num] = arr[n_left]; return;}
	int mid = (n_left+n_right)/2;
	makeSeg(2*num, n_left, mid);
	makeSeg(2*num+1,mid+1,n_right);
	tree[num] = min(tree[num*2],tree[num*2+1]);
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	
	for(int i = 0;i < N; i++)cin >> arr[i];
	makeSeg(1,0,N-1);
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		cout << search(a,b,1,0,N-1) << '\n';
	}
}*/
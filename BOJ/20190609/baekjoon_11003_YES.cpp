/*#include <vector>
#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;
using vi = vector<int>;

int Arr[5'000'000];
int RMQ[5'000'000*4];

int N, L;

void makeRMQ(int root,int i, int j){
	
	if(j-i <= 1){
		RMQ[root] = Arr[i];
		return;
	}
	
	int mid = (i+j)/2;
	int leftindex = (root<<1);
	int rightindex = (root<<1)+1;
	
	makeRMQ(leftindex, i , mid);
	makeRMQ(rightindex, mid, j);
	
	RMQ[root] = min(RMQ[leftindex],RMQ[rightindex]);
	
	return;
	
}

int RangeQuery(int li, int ri, int i, int j, int root = 1){
	
	if(li == i && ri == j)return RMQ[root];
	
	int mid = (i+j)/2;
	int ret = 2100000000;
	if(ri <= mid){
		return RangeQuery(li,ri,i,mid,root*2);
	}
	
	if(li >= mid){
		return RangeQuery(li,ri,mid,j,root*2+1);
	}
	
	return min(RangeQuery(li,mid,i,mid,root*2), RangeQuery(mid,ri,mid,j,root*2+1));
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> L;
	
	for(int i = 0; i < N; i++){
		cin >> Arr[i];
	}
	makeRMQ(1,0,N);


	
	for(int i = 1; i <= N; i++){
		int k = max(0, i-L);
		cout << RangeQuery(k,i,0,N) << " ";
	}
	
	
	
}*/
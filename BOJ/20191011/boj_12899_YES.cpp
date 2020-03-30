/*
#include <iostream>
using namespace std;



int tree[8'000'004];

void update(int i, int j, int root = 1, int root_i = 0, int root_j = 2'000'001){
	if(root_i > i || root_j < i){return ;}
	if(root_i <= i && i <= root_j){tree[root]+= j; }
	if(root_i == root_j)return;
	int mid = (root_i + root_j) >> 1;	
	update(i,j,root*2, root_i , mid);
	update(i,j, root*2+1, mid+1, root_j);
}

int find(int i, int root = 1, int root_i = 0, int root_j = 2'000'001){
	if(root_i == root_j)return root_i;
	int mid = (root_i + root_j) >> 1;
	int lft = tree[root*2];
	
	if(i <= lft){return find(i,root*2,root_i,mid);}
	else{return find(i-lft,root*2+1,mid+1,root_j);}
}



int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		
		int a,b;
		cin >> a >> b;
		
		if(a == 1){
			update(b,1);
		}
		else{
			int k = find(b);
			cout << k << '\n';
			update(k,-1);
		}
		
	}
	
}*/

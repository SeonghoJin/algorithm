#include <iostream>
#include <vector>
using namespace std;

vector<int> tree(1 << 15);
int N;

void Multiplebytwo_left(int dep,int n){
	if(dep == N-1){tree[n]*=2; return;}
	tree[n]= tree[n]*2 + 1;
	Multiplebytwo_left(dep+1,2*n);
	Multiplebytwo_left(dep+1,2*n+1);
}

void Multiplebytwo_right(int dep,int n){
	if(dep == N-1){tree[n]= 2*tree[n] + 1; return;}
	tree[n]*=2;
	Multiplebytwo_right(dep+1,2*n);
	Multiplebytwo_right(dep+1,2*n+1);
}

void makePerfectBinarytree(int dep,int n){
	tree[n] = 1;
	if(dep == N-1){return;}
	makePerfectBinarytree(dep+1,2*n);
	makePerfectBinarytree(dep+1,2*n+1);
	Multiplebytwo_left(dep+1, 2*n);
	Multiplebytwo_right(dep+1, 2*n+1);
}

void preOrder(int dep,int n){
	
	if(dep == N)return;
	cout << tree[n] << " ";
	preOrder(dep+1,2*n);
	preOrder(dep+1,2*n+1);
	
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	
	makePerfectBinarytree(0,1);
	preOrder(0,1);
	
}
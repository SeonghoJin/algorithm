#include <iostream>

using namespace std;

int N;
int tree[1 << 21];
int _tree[1 << 21];
int ans_tree[1 << 21];
long long ans = 0;
void makeMaximum(int dep,int n){
	
	if(dep == N-1){
		tree[n]+=max(tree[n*2],tree[n*2+1]);
		return;
	}
	makeMaximum(dep+1,n*2);
	makeMaximum(dep+1,n*2+1);
	tree[n]+=max(tree[n*2],tree[n*2+1]);
	
}

void makeanswer(int dep,int n){
	
	
	if(dep == N){return;}
	ans+=tree[n]-tree[2*n]-_tree[n]+_tree[2*n];
	ans+=tree[n]-tree[2*n+1]-_tree[n]+_tree[2*n+1];
	makeanswer(dep+1,2*n);
	makeanswer(dep+1,2*n+1);
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N;
	_tree[1] = 0;
	for(int i = 2; i < (1 << N+1); i++){
		cin >> tree[i];
		_tree[i]=tree[i];
	}

	makeMaximum(0,1);
	makeanswer(0,1);
	
	cout << ans;
}
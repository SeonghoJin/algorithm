#include <iostream>

using namespace std;

const int MAX = 500'001;

int segtree[MAX*4];
int lazy[MAX*4];
int N;
	
void update_lazy(int n, int l, int r){
	if(lazy[n] == 0)return;
	
	int t = r - l + 1;
	
	if(l != r){
		lazy[2*n] ^= lazy[n];
		lazy[2*n + 1] ^= lazy[n];
	}
	
	if(t & 1){
		segtree[n] ^= lazy[n];
	}
		
	lazy[n] = 0;
}

void update(int li, int ri, int v, int n = 1, int n_li = 0, int n_ri = N-1){
	update_lazy(n, n_li, n_ri);
	
	if(ri < n_li || n_ri < li)return;
	if(li <= n_li && n_ri <= ri){
		
		if(n_li != n_ri){
		lazy[2*n] ^= v;
		lazy[2*n+1] ^= v;
		}
		
		if((n_ri - n_li + 1) & 1){
			segtree[n] ^= v;
		}
			
		return;
	}
	
	int mid = (n_li + n_ri)/2;
	
	update(li, ri, v, 2*n, n_li, mid);
	update(li, ri, v, 2*n+1, mid+1, n_ri);
	
	segtree[n] = segtree[2*n+1]^segtree[2*n];
	
		
}

int find(int li, int ri, int n = 1, int n_li = 0, int n_ri = N-1){
	update_lazy(n,n_li, n_ri);
	
	if(ri < n_li || n_ri < li)return 0;
	
	if(li <= n_li && n_ri <= ri){
		return segtree[n];
	}
	int mid = (n_li + n_ri)/2;
	return find(li, ri, 2*n, n_li, mid)^find(li, ri, 2*n+1, mid+1, n_ri);
}
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> N;
	
	for(int i = 0; i < N; i++){
		int t;
		cin >> t;
		update(i,i,t);
	}
	
	int M;
	cin >> M;
	
	while(M--){
		
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1){
			int d;
			cin >> d;
			update(min(b,c),max(b,c),d);
		}
		else{
			cout << find(min(b,c),max(b,c)) << '\n';
		}
		
	}
	
}
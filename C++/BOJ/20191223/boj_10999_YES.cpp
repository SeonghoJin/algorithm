/*#include <iostream>

using namespace std;

const int MAX = 1000001;

long long segtree[4*MAX];
long long lazy[4*MAX];
int N, M, K;

void update_lazy(int node, int start, int end) {

        segtree[node] += (end-start+1)*lazy[node];
        // leaf가 아니면
        if (start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    
}

void update(int left, int right, long long v, int root = 1, int root_left = 0, int root_right = N-1){
	update_lazy(root, root_left, root_right);
	if(right < root_left || root_right < left)return ;
	
	if(left <= root_left && root_right <= right){
		segtree[root] += (root_right - root_left + 1) * v;
		if(root_left != root_right){
			lazy[root*2] += v;
			lazy[root*2+1] += v;
		}
		return ;
	}
	
	int mid = (root_left + root_right) >> 1;
	
	update(left, right, v, root*2, root_left, mid);
	update(left, right, v, root*2+1, mid+1, root_right);
	
	segtree[root] = segtree[root*2] + segtree[root*2+1];
}

long long find(int left, int right, int root = 1, int root_left = 0, int root_right = N - 1){
	
	update_lazy(root, root_left, root_right);
	
	if(right < root_left || root_right < left)return 0;
	
	if(left <= root_left && root_right <= right){
		return segtree[root];
	}
	
	int mid = (root_left + root_right) >> 1;
	
	long long ret = 0;
	
	ret += find(left, right, root*2, root_left, mid);
	ret += find(left, right, root*2+1, mid+1, root_right);
	
		
	return ret;
}


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N >> M >> K;
	
	for(int i = 0; i < N; i++){
		int temp;
		cin >> temp;
		update(i,i,temp);
		
	}
	
	int T = M+K;
	while(T--){
		int C;
		cin >> C;
		if(C == 1){
			int l, r, v;
			cin >> l >> r >> v;
			l--;
			r--;
			update(l,r,v);
		}
		else{
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			cout << find(l,r) << '\n';
		}
		
	}
	
}*/
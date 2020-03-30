#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 500'001;

struct student{
	int x,y,z;
	
	public :
		student(){
			
		}
	
	bool operator < (const student& rhs) const{
		return x < rhs.x;
	}
};

int N;
int tree[4*MAX_N];
student students[MAX_N];

void update(int idx, int v, int root = 1, int root_li = 1, int root_ri = N){
	if(root_ri < idx || root_li > idx)return;
	
	tree[root] = min(tree[root], v);
	if(root_li == root_ri)return;
	int mid = (root_li + root_ri)/2;
	
	update(idx, v, root*2, root_li, mid);
	update(idx, v, root*2+1, mid+1, root_ri);
}

int query(int li, int ri, int root = 1, int root_li = 1, int root_ri = N){
	if(root_ri < li || ri < root_li)return 987654321;
	
	if(li <= root_li && root_ri <= ri){return tree[root];}
	
	int mid = (root_li + root_ri)/2;
	
	return min(query(li,ri,root*2,root_li,mid), query(li,ri,root*2+1,mid+1,root_ri));
}

int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		int t;
		cin >> t;
		students[t].x = i+1;
	}
	for(int i = 0; i < N; i++){
		int t;
		cin >> t;
		students[t].y = i+1;
	}
	for(int i = 0; i < N; i++){
		int t;
		cin >> t;
		students[t].z = i+1;
	}
	

	
	sort(students+1, students+N+1);
	
	fill(tree,tree+4*MAX_N, 987654321);
	
	int ans = 0;
	
	for(int i = 1; i <= N; i++){
		int idx = students[i].y;
		int v = students[i].z;
		update(idx,v);
		int temp = query(1,idx);
		if(temp == v)ans++;
	}
	
	cout << ans;
}
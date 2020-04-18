#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 300'001;
vector<pair<int, int>> segtree[4*MAX];

int Arr[MAX];
int N, M, Q;
int need[MAX];
int current[MAX];
int ans[MAX];
int c = 0;
int pp =0;
void makesegtree(int root = 1, int l = 0, int r = M-1){
	
	if(l == r){
		segtree[root].push_back({Arr[l], 1});
		return;
	}
	
	int mid = (l + r) >> 1;
	
	makesegtree(root*2, l, mid);
	makesegtree(root*2+1, mid+1, r);
	
	int li = l, ri = mid+1;
	int idx = 0;
	vector<int> temp(r-l+1);
	while(li <= mid || ri <= r){
		
		if((Arr[li] <= Arr[ri] && li <= mid) || ri > r){
			temp[idx++] = Arr[li++];
		}
		else{
			temp[idx++] = Arr[ri++];
		}
		
	}
	int cnt = 0;
	segtree[root].push_back({temp[0],1});
	
	for(int i = 0; i < temp.size() - 1; i++){
		Arr[l+i] = temp[i];
		if(temp[i] != temp[i+1]){
			segtree[root].push_back({temp[i+1],1});
			cnt++;
		}
		else{
			segtree[root][cnt].second++;
		}
	}
	
	Arr[l+temp.size()-1] = temp[temp.size()-1];
		
}

void find(int l, int r, int root = 1, int root_l = 0, int root_r = M-1){
	if(root_r < l || root_l > r)return;
	
	if(l <= root_l && root_r <= r){
		for(int i = 0; i < segtree[root].size(); i++){
			pair<int, int> temp  = segtree[root][i];
			current[temp.first] += c*temp.second;
			if(ans[temp.first] == 0 && current[temp.first] >= need[temp.first]){
				ans[temp.first] = pp;
			}
		}
		return;
	}
	
	int mid = (root_l + root_r) >> 1;
	
	find(l,r,root*2,root_l, mid);
	find(l, r,root*2+1, mid+1, root_r);
	
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < M; i++)cin >> Arr[i];
	for(int i = 1; i <= N; i++)cin >> need[i];
	makesegtree();
	cin >> Q;

	
	for(pp = 1; pp <= Q; pp++){
		int a, b;
		cin >> a >> b >> c;
		a--;
		b--;
		if(a <= b){
			find(a,b);
		}
		else{
			find(a,M-1);
			find(0,b);
		}
	}
	
	for(int i = 1; i <= N; i++){
		if(ans[i]){
			cout << ans[i] << '\n';
		}
		else{
			cout << "NIE" << '\n';
		}
	}
	
}
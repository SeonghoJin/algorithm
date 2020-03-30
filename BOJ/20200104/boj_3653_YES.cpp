/*#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 300'001;
int tree[MAX];
int where[MAX];

void update(int i, int diff){
	
	while(i <= MAX){
		tree[i] += diff;
		i += (i & -i);
	}
	
}

int sum(int i){
	int ret = 0;
	
	while(i){
		ret += tree[i];
		i -= (i & -i);
	}
	
	return ret;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int T;
	cin >> T;
	
	while(T--){
		fill(tree, tree+MAX, 0);
		int N, M;
		cin >> N >> M;
		
		for(int i = 1; i <= N; i++){
			where[i] = N-i+1;
			update(i,1);
		}
			
		
		while(M--){
			int t;
			cin >> t;
			
			cout << sum(N) - sum(where[t]) << ' ';
			update(where[t],-1);
			where[t] = ++N;
			update(where[t],1);
			
		}
		cout << '\n';
	}
}*/
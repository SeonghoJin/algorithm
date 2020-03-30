/*#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
const int MAX = 1'000'001;
int tree[MAX];

void update(int i, int diff){
	
	while(i < MAX){
		tree[i] += diff;
		i += (i & -i);
	}
	
}

long long sum(int i){
	long long ret = 0;
	while(i){
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int N;
	cin >> N;
	
	
	while(N--){
		int a, b, c;
		cin >> a >> b;
		if(a == 1){
			
			int hi = MAX-1;
			int lo = 1;
			int mid = (lo + hi)/2;
			
			while(lo < hi){
				if(sum(mid) < b){
					lo = mid;
				}
				else{
					hi = mid;
				}
				mid = (lo + hi)/2;
				cout << lo << " " << hi << '\n';
				
			}
			mid = (lo + hi)/2;
			cout << mid << '\n';
			update(lo,-1);
		}
		else{
			cin >> c;
			update(b,c);
		}
	}
	
}*/
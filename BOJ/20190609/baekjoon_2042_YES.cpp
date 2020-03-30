#include <iostream>
#include <vector>

using namespace std;
using lli = long long;
lli tree[1000001]={0,};
static lli Arr[1000001]={0,};
static int N,M,K;

lli sum(int i){
	long long ret = 0;
	
	while(i){
		ret+=tree[i];
		i -= (i & -i);
	}
	return ret;
}

void update(int i, int v){
	while(i <= N){
		tree[i]+=v;
		i += (i & -i);
	}
	
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M >> K;
		
	for(int i = 1; i <= N; i++){
		int a;
		cin >> Arr[i];
		update(i,Arr[i]);
	}
	
	int T = M+K;
	
	while(T--){
		int W,a,b;
		cin >> W >> a >> b;
		if(W==1){
			update(a,b-Arr[a]);
			Arr[a] = b;
		}
		else{
			cout << sum(b)-sum(a-1) << '\n';
		}
	}
}
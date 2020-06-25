#include <bits/stdc++.h>

using namespace std;
using matrix = vector<vector<long long >>;

const long long MOD = 1'000'000'007;
//정보과학관0
//전산관1
//미래관2
//신양관3
//환경직기념관4
//진리관5
//형남공학관6
//학생회관7

long long  adj[8][8] = {{0,1,1,0,0,0,0,0},
				 {1,0,1,1,0,0,0,0},
			 	 {1,1,0,1,1,0,0,0},
				 {0,1,1,0,1,1,0,0},
				 {0,0,1,1,0,1,1,0},
				 {0,0,0,1,1,0,0,1},
				 {0,0,0,0,1,0,0,1},
				 {0,0,0,0,0,1,1,0}
                };

matrix ans(8,vector<long long >(8,0));
matrix d(8,vector<long long >(8));
	
matrix operator * (const matrix &a, const matrix &b) {
    long long  n = a.size();
	matrix c(n,vector<long long >(n,0));
	
	for(long long  i = 0; i < n; i++){
		for(long long  j = 0; j < n; j++){
			for(long long  k = 0; k < n; k++){
				c[i][j]+=((a[i][k]*b[k][j])%MOD);
                c[i][j] %= MOD;
			}
		}
	}
	
	return c;
}


int main(){
	
    int K;
    cin >> K;
	for(long long  i = 0; i < 8; i++){
		for(long long  j = 0; j < 8; j++){
			d[i][j] = adj[i][j];
            ans[i][j] = adj[i][j];
		}
	}
	
	K-=1;

	while(K){
		if(K&1){ans=ans*d;}
		K/=2;
		d=d*d;
	}

    cout << ans[0][0];
}

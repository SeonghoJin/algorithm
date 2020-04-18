/*
#include <iostream>
#include <vector>

using namespace std;
using matrix = vector<vector<int>>;

matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
	matrix c(n,vector<int>(n,0));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				c[i][j]+=((a[i][k]*b[k][j])%1000);
			}
		}
	}
	
	return c;
}

int main(){
	
	int N, K;
	cin >> N >> K;
	
	matrix ans(N,vector<int>(N,0));
	matrix d(N,vector<int>(N));
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> d[i][j];
			ans[i][j] = d[i][j];
		}
	}
	
	K-=1;
	while(K){
		if(K&1){ans=ans*d;}
		K/=2;
		d=d*d;
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << ans[i][j]%1000 << " ";
		}
		cout << endl;
	}
	
	
}
*/
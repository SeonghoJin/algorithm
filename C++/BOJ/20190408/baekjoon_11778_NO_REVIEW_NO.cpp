#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<unsigned long long>> matrix;
unsigned long long mod = 1000000007;
matrix operator * (matrix &a, matrix &b){
    //행렬로 피보나치수 구하기
    long long n=a.size();
    matrix c(2, vector<unsigned long long>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}
unsigned long long gcd(unsigned long long a, unsigned long long b){
	unsigned long long c = a % b;
	if(c==0)return b;
	return gcd(b,c);
	
}
int main(){
    unsigned long long n=0,m=0;
    unsigned long long rgcd=0;
    cin >> n >> m;
    rgcd = gcd(n,m);
    matrix ans = {{1,0},{0,1}};
    matrix a = {{1,1},{1,0}};
    
    while(rgcd>0){
        if(rgcd%2==1){
            ans = ans * a;
        }
        a = a * a;
        rgcd /= 2;
    }
    cout << ans[0][1]%mod << endl;
    return 0;
}

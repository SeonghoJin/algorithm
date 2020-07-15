#include <bits/stdc++.h>

using namespace std;


long long temp[10];
long long ans[10];

long long power(long long n, long long i){
    long long ret = 1;
    for(long long j = 0; j < i; j++){
        ret *= n;
    }
    return ret;
}
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    long long N;
    cin >> N;

         N++;
    
        for(long long i = 0; N/power(10,i); i++){
            long long k = N/power(10,i+1);
            for(long long j = 0; j < 10; j++){
                ans[j] += k * power(10,i);
            }
            
            k = N%power(10,i+1);
            long long p = power(10,i);
            for(long long j = 0; j < 10; j++){
                if(p <= k){
                    ans[j]+=p;
                    k -= p;
                }
                else{
                    ans[j] += k;
                    break;
                }
            }

            if(N >= p){
                ans[0] -= p;
            }
        }
        for(long long i = 0; i < 10; i++){
            cout << ans[i] << " ";
        }

    }
    


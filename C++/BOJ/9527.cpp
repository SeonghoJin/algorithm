#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll  precalc[64];
ll cal(long long x){
    long long temp = x;
    long long sum = 0;

    while(x){
        if(x & 1)sum++;
        x /= 2;
    }
    long long ret = 0;
    int i = 0;
    long long k = 1;
    while(temp){
        if(temp & 1){
            ret += (precalc[i] + k * --sum);
        }
        i++;
        k*=2;
        temp/=2;
    }
    return ret;
}
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    long long sum = 0;
    

    precalc[1] = 1;
    precalc[0] = 0;
    for(long long i = 2; i < 60; i++){
        precalc[i] = precalc[i-1] * 2 + pow(2,i-1);
    }
    for(long long i = 0; i < 60; i++){
        precalc[i]++;
    }
    
    long long a, b;
    cin >> a >> b;
    cout << cal(b) - cal(a-1);
}
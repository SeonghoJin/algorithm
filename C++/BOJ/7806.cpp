#include <bits/stdc++.h>

using namespace std;
using ll = long long;
long long cnt(long long n, long long k){   
   long long ret = 0;
   for(long long i = k; i <= n; i *= k)ret += n/i;
   return ret;
}
ll pw(ll a, ll b) {
	ll ret = 1;
	while (b) {
		if (b & 1) ret *= a;
		a *= a, b >>= 1;
	}
	return ret;
}
int main(){

   long long a, b;
   while(scanf("%lld %lld", &a, &b) != EOF){
      if(a == 0)a = 1;

      long long temp = b;
      long long answer = 1;
      for(long long i = 2; i * i <= b; i++){
         if(temp < i)break;
         long long c = cnt(a,i);
         //for (ll j = i; j <= a; j *= i) c += a / j;
         long long cc = 0;
         while(temp%i == 0){
            cc++; temp/=i;
         }
         answer *= pw(i,min(c,cc));
     }
      cout << answer * (temp <= a ? temp : 1)<< '\n';
  }
}
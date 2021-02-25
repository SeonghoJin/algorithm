#include <bits/stdc++.h>
 
using namespace std;
 
long long f(long long a, long long b){
   return a%b == 0 ? 0 : b - a%b;
}
 
int main(){
   cin.tie(0);
   ios_base :: sync_with_stdio(0);
 
   int t;
   cin >> t;
   while(t--){
      long long a, b, c, d;
      cin >> a >> b >> c >> d;
      
      long long ans = min({f(a,b), f(a,c), f(a,d)});
      cout << ans << '\n';
   }
}
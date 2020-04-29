#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
 
    long long T;
    cin >> T;
    while(T--){
        long long a, b, c, d;
 
        cin >> a >> b >> c >> d;
        long long ans = 0;
        ans = min(a,b)*d + c * (max(a,b)-min(a,b));
        ans = min(ans, (a+b)*c);       
        
        cout << ans << '\n';
      
       
    }
 
}
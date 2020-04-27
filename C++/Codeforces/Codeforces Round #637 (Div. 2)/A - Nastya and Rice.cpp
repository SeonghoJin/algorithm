#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
   int T;
   cin >> T;
   while(T--){
       int n, a, b, c, d;
       cin >> n >> a >> b >> c >> d;
       
        int mi = (a-b)*n; 
        int ma = (a+b)*n;
        
        cout << ((ma < c-d || mi > c+d) ? "No" : "Yes") << '\n';
 
   }
}
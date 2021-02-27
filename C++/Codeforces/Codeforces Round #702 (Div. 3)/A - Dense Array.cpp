#include <bits/stdc++.h>
 
using namespace std;
 
int f(int a, int b){
   int ret = 0;
   int l = min(a,b);
   int r = max(a,b);
 
   while(l*2 < r){
      ret++;
      l*=2;
   }
   return ret;
}
 
int main(){
   cin.tie(0);
   ios_base :: sync_with_stdio(0);
 
   int t;
   cin >> t;
   while(t--){
      int n;
      cin >> n;
      vector<int> v(n);
      for(int i = 0; i < n; i++){
         cin >> v[i];
      }
 
      int answer = 0;
 
      for(int i = 0; i < n-1; i++){
         answer += f(v[i], v[i+1]);
      }
      cout << answer << '\n';
   }
   
}
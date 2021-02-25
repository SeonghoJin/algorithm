#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(){
   cin.tie(0);
   ios_base :: sync_with_stdio(0);
 
   int t;
   cin >> t;
   while(t--){
      int n;
      cin >> n;
      vector<int> v(n);
      vector<int> idx(n+1);
      for(int i = 0; i < n; i++){
         cin >> v[i];
         idx[v[i]] = i;
      }
      int iidx = n;
      for(int i = n; i > 0; i--){
         if(iidx > idx[i]){
            for(int j = idx[i]; j < iidx; j++){
               cout << v[j] << ' ';
            }
            iidx = idx[i];
         }
      }
      cout << '\n';
   }
}
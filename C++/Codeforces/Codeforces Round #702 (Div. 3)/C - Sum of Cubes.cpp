#include <bits/stdc++.h>
 
using namespace std;
 
vector<long long> v;
 
int main(){
   cin.tie(0);
   ios_base :: sync_with_stdio(0);
 
   int t;
   cin >> t;
 
   for(int i = 1; i < 10000; i++){
      v.push_back(1LL*i*i*i);
   }
 
   while(t--){
      long long x;
      cin >> x;
 
      bool flag = false;
      for(int i = 0; i < 9999; i++){
         int idx = lower_bound(v.begin(), v.end(), x-v[i]) - v.begin();
         if(v[idx] + v[i] == x){
            flag = true;
            break;
         }
      }
      cout << (flag ? "YES" : "NO") << '\n';
   }
}
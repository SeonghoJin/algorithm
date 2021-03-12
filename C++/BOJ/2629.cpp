#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

void fast_io(){
   cin.tie(0);
   ios_base :: sync_with_stdio(0);
}

void process(){
   int n;
   cin >> n;
   vector<int> v(n);
   for(int i = 0; i < n; i++){
      cin >> v[i];
   }

   vector<vector<bool>> dp(n+1, vector<bool>(40001,false));
   dp[0][0] = true;
   for(int i = 0; i < n; i++){
      for(int j = 0; j < 15001; j++){
         int weight = v[i];
         if(dp[i][j] == true){
            dp[i+1][j] = true;
            dp[i+1][abs(j-weight)] = true;
            if(j + weight <= 40000){
               dp[i+1][j+weight] = true;
            }
         }
      }
   }

   int k;
   cin >> k;
   while(k--){
      int a;
      cin >> a;
      cout << (dp[n][a] ? 'Y' : 'N') << " ";
   }
}

int main(){
   fast_io();
   process();
}
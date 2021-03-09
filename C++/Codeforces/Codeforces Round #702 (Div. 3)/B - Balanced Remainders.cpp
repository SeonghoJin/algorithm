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
 
      int a[3] = {0,0,0};
      
      for(int i = 0; i < n; i++){
         int temp;
         cin >> temp;
         a[temp%3]++;
      }
      int f = n/3;
      int answer = 0;
      for(int i = 0; i < 6; i++){
         int here = i%3;
         int next = (i+1)%3;
         if(a[here] > f){
            a[next] += a[here] - f;
            answer += a[here] - f;
            a[here] = f;
         }
      }
 
      cout << answer << '\n';
   }  
}
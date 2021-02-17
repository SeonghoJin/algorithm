#include <bits/stdc++.h>
 
using namespace std;
 
int f(int a, int b){
   int ret = 0;
   if(b == 1){
      ret++;
      b++;
   }
   while(a != 0){
      ret++;
      a/=b;
   }
   return ret;
}
 
int main(){
   cin.tie(0);
   ios_base :: sync_with_stdio(0);
 
   int T;
   cin >> T;
   while(T--){
      int a, b;
      cin >> a >> b;
 
      int answer = 987654321;
      answer = min(answer, f(a,b)); 
      int temp = b;
      while(temp <= 100){
         temp++;
         answer = min(answer, f(a,temp) + temp - b);
      }
 
 
      cout << answer << '\n';
   }
}
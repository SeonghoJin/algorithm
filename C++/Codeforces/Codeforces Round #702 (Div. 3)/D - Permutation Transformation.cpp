#include <bits/stdc++.h>
 
using namespace std;
 
vector<long long> v;
 
int maxIndex(vector<int>& v, int l, int r){
   int index = l;
   int pivot = v[l];
   for(int i = l; i < r; i++){
      if(v[i] > pivot){
         pivot = v[i];
         index = i;
      }
   }
   return index;
}
 
void dfs(vector<int>& v, vector<int>& dep, int l, int r, int depth){
   if(l >= r)return;
   int maxIdx = maxIndex(v,l,r);
   dep[maxIdx] = depth;
   dfs(v, dep, l, maxIdx, depth+1);
   dfs(v, dep, maxIdx+1, r, depth+1);
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
      vector<int> dep(n+1);
      for(int i = 0; i < n; i++){
         cin >> v[i];
      }
      dfs(v,dep,0,n,0);
      for(int i = 0; i < n; i++){
         cout << dep[i] << " ";
      }
      cout << '\n';
   }
}
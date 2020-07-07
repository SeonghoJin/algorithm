#include <bits/stdc++.h>

using namespace std;
int arr[101][101];
int cnt[101];
int N, M, R;

int main(){
   cin.tie(0);
   ios_base :: sync_with_stdio(0);
   for(int i = 0; i < 101; i++){
      fill(arr[i], arr[i]+101, 987654321);
   }
   cin >> N >> M >> R;

   for(int i = 0; i < N; i++){
      cin >> cnt[i+1];
      arr[i+1][i+1] = 0;
   }

   for(int i = 0; i < R; i++){
      int a, b, c;
      cin >> a >> b >> c;
      arr[a][b] = c;
      arr[b][a] = c;
   }

   for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
         for(int k = 1; k <= N; k++){
            if(arr[j][i] + arr[i][k] < arr[j][k]){
               arr[j][k] = arr[j][i] + arr[i][k];
            }
         }
      }
   }

   int answer = 0;

   for(int i = 1; i <= N; i++){
      int sum = 0;
      for(int j = 1; j <= N; j++){
         if(arr[i][j] <= M){sum += cnt[j];}
      }
      answer = max(answer, sum);
   }
   cout << answer;
}
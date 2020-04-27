
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
 
    int T;
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >> K;
 
        vector<int> arr(N);
        vector<int> check(N);
 
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        for(int i = 1; i < N-1; i++){
            if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
                check[i] = 1;
            }
        }
 
        for(int i = 1; i < N; i++){
            check[i] += check[i-1];
        }
 
        /*for(int i = 0; i < N; i++){
            cout << check[i] << " ";
        }*/
       // cout << '\n';
        int answer = 0;
        int answer2 = 1;
 
        for(int i = 1; i + K - 3 < N-1; i++){
   //         cout << check[i+K-3] << " ";
 
            if(answer < check[i+K-3] - check[i-1]){
               // cout << check[i+K-3] << " ";
 
                answer = check[i+K-3] - check[i-1];
                answer2 = i;
            }    
        }
       // cout << '\n';
        cout << answer+1 << " " << answer2 << '\n';
 
       
    }
 
}
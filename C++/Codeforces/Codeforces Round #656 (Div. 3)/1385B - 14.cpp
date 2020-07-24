#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> v(N*2);
 
        for(int i = 0; i < N*2; i++){
            cin >> v[i];
        }
 
        int arr[51];
        fill(arr,arr+51,0);
 
        for(int i = 0; i < N*2; i++){
            if(arr[v[i]] == 0){
                cout << v[i] << " ";
                arr[v[i]] = 1;
            }
        }
        cout << '\n';
    }
}
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
 
    int t;
    cin >> t;
 
    while(t--){
        int n, u, v;
        cin >> n >> u >> v;
 
        vector<int> arr(n);
 
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        bool flag = true;
        int maxdiff = 0;
        for(int i = 1; i < n; i++){
            if(abs(arr[i] - arr[i-1]) > 1){
                flag = false;
            }
            maxdiff = max(maxdiff, abs(arr[i] - arr[i-1]));
        }
 
        if(!flag){
            cout << 0 << "\n";
        }
        else{
            if(maxdiff == 0){
                cout << min(2*v, u+v) << '\n';
            }
            else{
                cout << min(u, v) << '\n';
            }
        }
 
    }
    
}

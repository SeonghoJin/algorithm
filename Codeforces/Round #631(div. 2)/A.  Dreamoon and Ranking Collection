#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
 
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
 
    int T;
    cin >> T;
 
    while(T--){
        int N, x;
        cin >> N >> x;
 
        int arr[202];
        fill(arr, arr+202,0);
        for(int i = 0; i < N; i++){
            int t;
            cin >> t;
            arr[t] = 1;
        }
        int start;
        for(int i = 1; i < 202; i++){
            if(x != 0 && arr[i] == 0){
                x--;
                arr[i] = 1;
            }
        }
 
        for(int i = 1; i < 202; i++){
            if(arr[i] == 0){
                cout << i-1 << '\n';
                break;
            }
        }
        
    }
 
}

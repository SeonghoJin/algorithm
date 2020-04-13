#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
 
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
 
    int T;
    cin >> T;
 
    while(T--){
        int N;
        cin >> N;
        
        vector<int> v(N);
        for(int i = 0; i < N; i++)cin >> v[i];
 
        sort(v.begin(), v.end());
        int pointer1 = -1;
        int pointer2 = 0;
        int cur = N/2;
        for(int i = 0; i < N; i++){
            if(i & 1){
                cout << v[cur+pointer1--] << ' ';
 
            }
            else{
                cout << v[cur+pointer2++] << ' ';
            }
        }
        cout << '\n';
    }
    
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
 
 
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
 
    int T;
    cin >> T;
 
    while(T--){
        int N;
        cin >> N;
 
        vector<long long> v(N);
        int t = 0;
        for(int i = 0; i < N; i++)cin >> v[i];
        long long ma = v[0];
      
        for(int i = 1; i < N; i++){
            long long diff = v[i-1] - v[i];
            if(diff > 0){
            for(int j = 30; j >= 0; j--){
                if(diff - pow(2,j) >= 0){
                    diff -= pow(2,j);
                    t = max(t, j+1);
                }    
            }
            v[i] = v[i-1] + diff;
            }
            
        }
 
        cout << t << '\n';
    }
    
}
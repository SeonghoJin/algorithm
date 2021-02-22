#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        long long sum = 0;
        long long tsum = 0;
        bool flag = true;
        for(int i = 0; i < n; i++){
            sum += i;
            int a;
            cin >> a;
            tsum += a;
            if(tsum < sum){
                flag = false;
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
}
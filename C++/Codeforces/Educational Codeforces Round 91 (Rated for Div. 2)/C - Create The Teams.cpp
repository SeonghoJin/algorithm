#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
 
    int T;
    cin >> T;
    while(T--){
        vector<int> v;
        int n, x;
        cin >> n >> x;
 
        for(int i = 0; i < n; i++){
            int t;
            cin >> t;
            v.push_back(t);
        }
 
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int answer = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            count++;
            if(count*v[i]>=x){
                answer++;
                count = 0;
            }
        }
        cout << answer << '\n';
    }
}
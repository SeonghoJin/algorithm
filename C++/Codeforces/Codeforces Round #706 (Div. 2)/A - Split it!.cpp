#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int,int>;
 
int main(){
 
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
 
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
 
        if(b == 0){
            cout << "YES" <<'\n';
        }
        else{
            int count = 0;
            int sz = s.size();
            for(int i = 0; i < sz/2; i++){
                if(s[i] == s[sz-1-i]){
                    count++;
                }
                else{break;}
            }
 
            if(count == sz/2 && sz % 2 ==0){
                count--;
            }
            if(count >= b){
                cout << "YES" << '\n';
            }
            else{
                cout << "NO" << '\n';
            }
        }
    }
 
}
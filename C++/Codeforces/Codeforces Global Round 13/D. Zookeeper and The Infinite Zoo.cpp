#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    int q;
    cin >> q;
    while(q--){
        ll a, b;
        cin >> a >> b;
        if(a > b){
            cout << "NO" << '\n';
            continue;
        }

        int sum = 0;
        bool f = false;
        for(int i = 0; i < 30; i++){
            if((1 << i) & a)sum++;
            if((1 << i) & b)sum--;
            if(sum < 0){f = true;}
        }
        if(f){
            cout << "NO" << '\n';
        }
        else{
            cout << "YES" << '\n';
        }
    }
}
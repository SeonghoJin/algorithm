#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
 
    int n, q;
    cin >> n >> q;
 
    vector<int> v(n);
    int a0 = 0;
    int b1 = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i]){
          b1++;  
        }
        else{a0++;}
    }
 
    while(q--){
        int c, d;
        cin >> c >> d;
        if(c == 1){
            if(v[d-1]){
                b1--;
                a0++;
            }
            else{
                b1++;
                a0--;
            }
            v[d-1] = 1 - v[d-1];
        }
        else{
            if(d <= b1){
                cout << "1" << '\n';
            }
            else{
                cout << "0" << '\n';
            }
        }
    }
    
}
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    int t;
    cin >> t;
 
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
 
        int temp = max({a, b, c});
        int count = 0;
 
        count += (a == temp) + (b == temp) + (c == temp);
 
        if(count == 1){
            cout << "NO" << '\n';
        }
        else{
            cout << "YES" << '\n';
            if(a == b && b == c && c == temp){
                cout << a << " " << b << " " << c << '\n';
            }
            else if(a == b && b == temp){
            cout << 1 << " " << b << " " << c << '\n';
            }
            else if(b == c && c == temp){
                cout << a << " " << 1 << " " << c << '\n';
            }
            else if(a == c && a == temp)
            {
                cout << a << " " << b << " " << 1 << '\n'; 
            }   
        }
        
    }
}
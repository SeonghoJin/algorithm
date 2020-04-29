#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
 
    long long T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
 
        int ze = 0;
        int on = 0;
 
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0')ze++;
            else{on++;}
        }
 
        if(ze == 0 || on == 0){
            cout << s << '\n';
            continue;
        }
 
        for(int i = 0; i < s.size()-1; i++){
            if(s[i] == s[i+1]){cout << s[i] << (char)('1'+'0'-s[i]);}
            else{cout << s[i];}
        }
        cout << s[s.size()-1] << '\n';
    }
 
}
#include <bits/stdc++.h>
 
using namespace std;
 
int f(string s, char c){
    if(s.size() == 1){
        return s[0] != c;
    }
    int left = 0;
    int mid = s.size()/2;
    for(int i = 0; i < mid; i++){
        if(s[i] != c){
            left++;
        }
    }
    left += f(s.substr(mid,mid),c+1);
 
    int right = 0;
 
    for(int i = mid; i < s.size(); i++){
        if(s[i] != c){
            right++;
        }
    }
    right += f(s.substr(0,mid), c+1);
 
    return min(left, right);
}
 
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
 
    int T;
    cin >> T;
 
    while(T--){
        int sz;
        string s;
        cin >> sz >> s;
        cout << f(s, 'a') << '\n';
    }
}
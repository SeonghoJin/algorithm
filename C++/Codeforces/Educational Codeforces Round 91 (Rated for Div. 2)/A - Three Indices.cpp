#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
 
    int T;
    cin >> T;
 
    while(T--){
        vector<int> v;
        int sz;
        cin >> sz;
 
        for(int i = 0; i < sz; i++){
            int a;
            cin >> a;
            v.push_back(a);
        }
        bool flag = false;
        for(int i = 1; i < sz-1; i++){
 
            int left = i-1;
            int right = i+1;
 
            while(left >= 0 && v[left] > v[i]){
                left--;
            }
 
            while(right < sz && v[right] > v[i]){
                right++;
            }
 
            if(left != -1 && right != sz){
                flag = true;
                cout << "YES" << '\n';
                cout << left+1 << " " << i+1 << " " << right+1 << '\n';
                break;
            }
        }
 
        if(flag == false){
            cout << "NO" << '\n';
        }
 
 
    }
}

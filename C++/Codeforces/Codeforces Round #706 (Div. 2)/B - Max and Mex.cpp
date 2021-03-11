#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<long long,long long>;
 
int main(){
 
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
 
    long long t;
    cin >> t;
    while(t--){
        long long a, b;
        cin >> a >> b;
        vector<long long> v(a);
     
        for(long long i = 0; i < a; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
 
        long long temp = -1;
        for(long long i = 0; i < v.size(); i++){
            if(v[i] != i){
                temp = i;
                break;
            }
        }
        ll sz = v.size();
        if(b == 0){
            cout << sz << '\n';
        }
        else if(temp == -1){
            cout << sz + b << '\n';
        }
        else{
            long long check = ceil((double(temp) + (*max_element(v.begin(), v.end())))/2);
            auto it = find(v.begin(), v.end(), check);
            cout << v.size() + (it == v.end()) << '\n';
        }
    }
}
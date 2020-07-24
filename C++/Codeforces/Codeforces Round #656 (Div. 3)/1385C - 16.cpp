#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
 
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
 
        vector<int> v(N);
        for(int i = 0; i < N; i++){
            cin >> v[i];
        }
        if(N == 1){
            cout << "0" <<'\n';
            continue;
        }
        bool flag = true;
        bool f = false;
        for(int i = N-1 ; i > 0; i--){
            if(flag){
                if(v[i-1] >= v[i])continue;
                else{
                    flag = false;
                }
            }
            if(flag == false){
                if(v[i-1] <= v[i])continue;
                else{
                    cout << i << '\n';
                    f = true;
                    break;
                }
            }
        }
        if(f)continue;
        else{ cout << "0" << '\n';}
    }
 
}
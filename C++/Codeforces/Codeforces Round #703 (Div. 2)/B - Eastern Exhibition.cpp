#include <bits/stdc++.h>
 
using namespace std;
 
long long count(vector<int>& v){
    sort(v.begin(), v.end());
    
    long long ans = 0;
    int sz = v.size();
 
    if(sz & 1){
        return 1;
    }
    else{
        return (v[sz/2]-v[(sz/2)-1]+1);
    }
}
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> vx(N);
        vector<int> vy(N);
 
        for(int i = 0; i < N; i++){
            cin >> vx[i] >> vy[i];
        }
 
        cout << count(vx) * count(vy) << '\n';
 
    }
}
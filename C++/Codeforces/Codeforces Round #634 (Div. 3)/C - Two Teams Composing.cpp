#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
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
        vector<int> ch(N+1);
        int x = N/2;
        
        for(int i = 0; i < N; i++){
            cin >> v[i];
            ch[v[i]]++;
        }
        int maxidx = 0;
        int count = 0;
        int unique = 0;
        for(int i = 1; i <= N; i++){
            if(count < ch[i]){
                count = ch[i];
                maxidx = i;
            }
            if(ch[i] > 0)unique++;
        }
        unique-=1;
        int ans = 0;
        if(unique >= count){
            ans = count;
            }
            else{
            count--;
            unique++;    
        }
        if(unique >= count){
            cout << count << '\n';
        }    
        else{
            cout << min(count, unique) << '\n';
        }
        
    }
}
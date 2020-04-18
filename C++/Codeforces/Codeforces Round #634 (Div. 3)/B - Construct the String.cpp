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
        int N, a, b;
        cin >> N >> a >> b;
 
        string s;
        int temp = 0;
        for(int i = 0; i < N; i++){
            s += ('a' + (temp++)%b);
        }
        cout << s << '\n';
    }
   
}
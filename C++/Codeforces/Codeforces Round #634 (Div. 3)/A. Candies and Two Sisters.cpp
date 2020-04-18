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
 
        int k = N/2;
        if(N % 2 == 0)k--;
        if(N == 1 || N == 2){
            cout << 0 << '\n';
        }
        else {cout << k << '\n';}
    } 
   
}
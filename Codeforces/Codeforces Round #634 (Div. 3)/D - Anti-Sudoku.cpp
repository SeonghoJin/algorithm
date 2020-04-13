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
        string s[9];
        for(int i = 0; i < 9; i++)cin >> s[i];
        s[1][1] = s[1][0];
        s[0][6] = s[0][5];
        s[2][5] = s[3][5];
        s[3][8] = s[2][8];
        s[4][2] = s[4][0];
        s[5][4] = s[6][4];
        s[6][7] = s[6][6];
        s[7][0] = s[7][1];
        s[8][3] = s[8][2];
       for(int i = 0; i < 9; i++){
            cout << s[i] << '\n';
        }
    }
}
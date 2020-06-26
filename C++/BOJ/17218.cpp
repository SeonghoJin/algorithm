#include <bits/stdc++.h>

using namespace std;
int dp[51][51];
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    string str1, str2;

    cin >> str1 >> str2;
    str1 = "0" + str1;
    str2 = "0" + str2;

    for(int i = 1; i < str1.size(); i++){
        for(int j = 1; j < str2.size(); j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(str1[i] == str2[j]){
                dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
            }
        }
    }
    

    string ans = "";

    int a = str1.size()-1;
    int b = str2.size()-1;

    while(dp[a][b] != 0){
        if(str1[a] == str2[b] && dp[a-1][b-1] == dp[a][b]-1){
            ans += str1[a];
            a--;
            b--;
        }
        else if(dp[a][b-1] == dp[a][b]){
            b--;
        }
        else if(dp[a-1][b] == dp[a][b]){
            a--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}
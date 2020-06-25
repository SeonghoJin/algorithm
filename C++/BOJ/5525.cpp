#include <bits/stdc++.h>

using namespace std;
int dp[1'000'001];
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    
    int N;
    int K;
    cin >> K >> N;
    string s;
    cin >> s;

    K = 2*K + 1;
    dp[0] = (s[0] == 'I');
    int answer = 0;
    for(int i = 1; i <= s.size(); i++){
        if(i == s.size()){
            if(dp[i-1] - K >= 0)answer += 1 + (dp[i-1] - K)/2;
            break;
        }
        if(s[i] != s[i-1]){
            dp[i] = dp[i-1] + 1;
        }
        else{
            if(dp[i-1] - K >= 0)answer += 1 + (dp[i-1] - K)/2;
            dp[i] = (s[i] == 'I');
        }
    }

    cout << answer;
}

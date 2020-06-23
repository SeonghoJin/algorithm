#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--){
        int a, b;
        cin >> a >> b;

        int answer1 = INT_MIN;
        int answer2 = INT_MIN;

        for(int i = 0; i < b; i++){
            int k;
            cin >> k;

            if(k > a-k){
                answer2 = max(answer2,a-k);
                answer1 = max({answer1, k, a-k});
            }
            else{
                answer2 = max(answer2,k);
                answer1 = max({answer1, k, a-k});
            }

        }
        cout << answer2 << " " << answer1 << '\n';
    }
}
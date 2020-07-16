#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<int> a, b;
vector<ll> s1, s2;
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    
    int T;

    cin >> T;
    int N, M;
    cin >> N;
    for(int i = 0; i < N; i++){
        int c;
        cin >> c;
        a.push_back(c);
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        int c;
        cin >> c;
        b.push_back(c);
    }

    for(int i = 0; i < N; i++){
        ll sum = 0;
        for(int j = i; j < N; j++){
            sum += a[j];
            s1.push_back(sum);
        }
    }
    for(int i = 0; i < M; i++){
        ll sum = 0;
        for(int j = i; j < M; j++){
            sum += b[j];
            s2.push_back(sum);
        }
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    long long ans = 0;
    for(auto it = s1.begin(); it != s1.end(); it++){
        long long here = *it;
        long long target = T-here;

        ans += upper_bound(s2.begin(), s2.end(),target) - lower_bound(s2.begin(),s2.end(),target);
    }
    cout << ans;
}
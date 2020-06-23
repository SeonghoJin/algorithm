#include <bits/stdc++.h>

using namespace std;

long long N, S;

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N >> S;

    queue<long long> q;
    long long sum = 0;
    long long sz = 987654321;
    for(long long i = 0; i < N; i++){
        long long a;
        cin >> a;
        sum += a;
        q.push(a);
        while(sum >= S){
            sz = min(sz, (long long)q.size());
            sum -= q.front();
            q.pop();
        }
    }

    cout << (sz == 987654321 ? 0 : sz);
}
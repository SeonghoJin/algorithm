#include <bits/stdc++.h>

using namespace std;
long long K, N;
long long arr[101];
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> K >> N;

    priority_queue<long long,vector<long long>, greater<long long>> pq;
    for(long long i = 0; i < K; i++){
        cin >> arr[i];
        pq.push(arr[i]);
    }
    long long answer;
    while(!pq.empty()){
        long long here = pq.top(); pq.pop();
        N--;
        if(N == 0){
            answer = here;
            break;
        }

        for(long long i = 0; i < K; i++){
            long long next = here * arr[i];
            pq.push(next);
            if(here % arr[i] == 0){
                break;
            }
        }
    }

    cout << answer;
}
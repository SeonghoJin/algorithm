#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[100004];
int MAX_DIST = 2e9;

typedef pair<int,int> pii;

int main(){
    scanf("%d%d",&N,&K);
    for(int i=1;i<=N;i++) scanf("%d", arr+i);
    sort(arr+1, arr+N+1);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for(int i=1;i<N;i++){
        int m = arr[i+1]-arr[i]-1;
        pq.push({1, (m+1)/2});
        pq.push({1, m/2});
    }
    pq.push({1, MAX_DIST});
    pq.push({1, MAX_DIST});

    long long ans = 0;
    while(K--){
        pii fr = pq.top(); pq.pop();
        cout << fr.first << " " << fr.second << '\n';
        if(fr.first > fr.second) {K++;continue;}
        ans += fr.first;
        pq.push({fr.first+1, fr.second});
    }
    printf("%lld\n", ans);

    return 0;
}
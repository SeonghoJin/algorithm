#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
int N, M, X;
vector<pii> adj[10'001];
vector<int> p;

int cal(int start){
    priority_queue<pii> pq;

    pq.push({0,start});
    vector<int> path(N+1, 987654321);

    path[start] = 0;

    while(!pq.empty()){
        pii temp = pq.top(); pq.pop();

        int cost = -temp.first;
        int here = temp.second;

        if(cost > path[here])continue;

        for(pii t : adj[here]){
            int next = t.first;
            int c = t.second;

            if(path[next] > cost + c){
                path[next] = cost+c;
                pq.push({-path[next], next});
            }
        }
    }
    if(start == X){
        p = path;
    }
    return path[X];
}
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio;

    cin >> N >> M >> X;

    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    int ans = INT_MIN;

    cal(X);
    for(int i = 1; i <= N; i++){
        if(X!=i)ans = max(ans, cal(i) + p[i]);
    }
    cout << ans;
}
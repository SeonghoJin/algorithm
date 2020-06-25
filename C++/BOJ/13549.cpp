#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
int visit[100001];

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    int start, end;
    cin >> start >> end;

    fill(visit, visit+100001, 987654321);
    visit[start] = 0;

    priority_queue<pii> pq;
    pq.push({visit[start], start});

    while(!pq.empty()){
        pii temp = pq.top();
        pq.pop();

        int here = temp.second;
        int cost = -temp.first;
        if(cost >visit[here])continue;

        int next = here + 1;
        if(next >= 0 && next <= 100'000 && cost + 1 < visit[next]){
            visit[next] = cost+1;
            pq.push({-visit[next], next});
        }
        next = here - 1;
        if(next >= 0 && next <= 100'000 && cost + 1 < visit[next]){
            visit[next] = cost+1;
            pq.push({-visit[next], next});
        }
        next = 2*here;
        if(next >= 0 && next <= 100'000 && cost < visit[next]){
            visit[next] = cost;
            pq.push({-visit[next], next});
        }
    }

    cout << visit[end];
}

#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> adjlist[101];
const int INF = 987654321;

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adjlist[a].push_back({b,c});
        adjlist[b].push_back({a,c});
    }


    vector<int> sp(N, INF);
    priority_queue<pair<int,int>> pq;
    
    pq.push({0,0});
    
    while(!pq.empty()){
        pair<int,int> temp = pq.top();
        pq.pop();
        int here = temp.second;
        int c = -temp.first;

        if(c > sp[here]){
            continue;
        }

        for(int i = 0; i < adjlist[here].size(); i++){
            int next = adjlist[here][i].first;
            int cost = adjlist[here][i].second;
            if(sp[here] + cost < sp[next]){
                sp[next] = sp[here] + cost;
                pq.push({-sp[next], next});
            }
        }
    }

}
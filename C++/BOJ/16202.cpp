#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> adj[1001];
bool flag[1001][1001];
int par[1001];
int N, M, K;

struct dot{
    int weight;
    int here;
    int next;
    dot(int _weight,int _here, int _next) : weight(_weight), here(_here), next(_next) {
    }
};


bool operator<(const dot& a, const dot& b){
    return a.weight > b.weight;
}

int parent(int i){return i == par[i] ? i : par[i] = parent(par[i]);}

bool Union(int i, int j){
    int pi = parent(i);
    int pj = parent(j);
    if(pi == pj)return false;

    par[pi] = pj;

    return true;
}

int MST(){

    for(int i = 1; i <= N; i++){
        par[i] = i;
    }
    priority_queue<dot> pq;
    
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < adj[i].size(); j++){
            if(flag[i][adj[i][j].first])continue;
            //cout << i << " " << adj[i][j].first << " " << adj[i][j].second << '\n';
            pq.push({adj[i][j].second, i, adj[i][j].first});
        }
    }

    int C = N-1;
    int ret = 0;
    
    while(C && !pq.empty()){
        dot temp = pq.top(); pq.pop();
        int weight = temp.weight;
        int here = temp.here;
        int next = temp.next;
        

        if(Union(here, next)){
            if(C == N-1){flag[here][next] = 1;}
            C--;
            ret += weight;
        }
    }
    
    return C == 0 ? ret : 0;
}
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N >> M >> K;

    for(int i = 1; i <= M; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b,i});
    }
    
    while(K--){
        cout << MST() << " ";
    }
}
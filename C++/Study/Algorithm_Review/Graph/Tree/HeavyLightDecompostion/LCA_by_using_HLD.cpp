#include <bits/stdc++.h>

using namespace std;
const int MAX_V = 100'001;
int N, M;
vector<int> adj[MAX_V];
int sz[MAX_V];
int par[MAX_V];
int dfs(int n, int p){

    sz[n] = 1;
    par[n] = p;
    for(int next : adj[n]){
        if(next != p)sz[n] += dfs(next, n);
    }
    return sz[n];
}
int depth[MAX_V];
vector<int> chain[MAX_V];
int chain_number[MAX_V];
int chain_idx[MAX_V];

void hld(int n, int p, int ch, int d){
    
    depth[n] = d;
    chain_number[n] = ch;
    chain_idx[n] = chain[ch].size();
    chain[ch].push_back(n);
    //cout << n << " " << p << " " << ch << " " << d << " " << sz[n] << '\n';
    int heavy = -1;

    for(int next : adj[n]){
        if(next == p)continue;
        if(heavy == -1 || sz[heavy] < sz[next]){
            heavy = next;
        }
    }

    if(heavy != -1){
        hld(heavy, n, ch, d);

        for(int next : adj[n]){
            if(next == heavy || next == p)continue;
            hld(next, n, next, d+1);
        }
    }
}

int LCA(int a, int b){

    while(chain_number[a] != chain_number[b]){

        //cout << a << " " << b << '\n';
        if(depth[a] > depth[b]){
            a = par[chain_number[a]];
        }
        else{
            b = par[chain_number[b]];
        }
    }
    return chain_idx[a] > chain_idx[b] ? b : a;
}
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N;
    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    hld(1,0,1,0);

    
    cin >> M;
    /*
    for(int i = 1; i <= N; i++){
        cout << chain_number[i] << ' ';
    }*/
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        cout << LCA(a,b) << '\n';
    }
}
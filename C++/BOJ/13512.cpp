#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
const int MAX_N = 100'001;

vector<int> adj[MAX_N];
int par[MAX_N];
int chain_number[MAX_N];
int chain_idx[MAX_N];
int depth[MAX_N];
vector<int> chain[MAX_N];
int sz[MAX_N];
int N, M;
vector<pii> segtree[MAX_N];
int dfs(int n, int p){
    sz[n] = 1;
    par[n] = p;
    for(int next : adj[n]){
        if(next == p)continue;
        sz[n] += dfs(next, n);
    }

    return sz[n];
}

void hld(int n, int p, int ch, int d){
    depth[n] = d;
    chain_number[n] = ch;
    chain_idx[n] = chain[ch].size();
    chain[ch].push_back(n);

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

void update(int ch, int idx, int r, int li, int ri){
    if(li > idx || ri < idx)return;
    if(li == ri){
        if(segtree[ch][r].first == 1){
            segtree[ch][r].first = 0;
            segtree[ch][r].second = INT_MAX;
        }
        else{
            segtree[ch][r].first = 1;
            segtree[ch][r].second = idx;
        }
        return;
    }
    int mid = (li + ri)/2;
    update(ch,idx,2*r,li,mid);
    update(ch,idx,2*r+1,mid+1,ri);
    
    segtree[ch][r].second = min(segtree[ch][2*r].second, segtree[ch][2*r+1].second);    
    //cout << ch << " " << idx << " " << r << " " << li << " " << ri << " " << segtree[ch][r].first << " " << segtree[ch][r].second << '\n';
}

int query(int ch, int ql, int qr, int r, int li, int ri){

    if(qr < li || ri < ql)return INT_MAX;
    
    if(ql <= li && ri <= qr){
        return segtree[ch][r].second;
    }
    int mid = (li + ri)/2;
    int qql = query(ch, ql, qr, 2*r, li, mid);
    int qqr = query(ch, ql, qr, 2*r+1, mid+1, ri);
    
    //cout << ch << " " << ql << " " << qr << " " << r << " " << li << " " << ri << " " << qql << " " << qqr <<'\n';
    return min(qql, qqr);
}

pii query1(int a){
    int answer = INT_MAX;
    int ans_ch = INT_MAX;
    while(chain_number[a] != 1){
        int ch = chain_number[a];
        int temp = query(ch,0,chain_idx[a],1,0,chain[ch].size()-1);
        if(temp != INT_MAX){
            ans_ch = ch;
            answer = temp;
            
        }
        a = par[chain_number[a]];
    }
    int ch = chain_number[a];
    int temp = query(ch, 0, chain_idx[a],1,0,chain[ch].size()-1);
    if(temp != INT_MAX){
        ans_ch = ch;
        answer = temp;
    }
    
    if(answer == INT_MAX){
        return {-1, -1};
    }
    else return {ans_ch, answer};
}

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N;
    for(int i = 0; i < N - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    hld(1,0,1,0);

    for(int i = 1; i <= N; i++){
        if(chain[i].size() > 0){
            segtree[i] = vector<pii>(chain[i].size()*4 + 1, {0,INT_MAX});
        }
    }
    /*
    for(int i = 1; i <= N; i++){
        if(chain[i].size() > 0){
            cout << "chain_number = " << i << '\n';
            for(int j = 0; j < chain[i].size(); j++){
                cout << chain[i][j] << " ";
            }
            cout << '\n';
        }
    }
    */
    cin >> M;
    
    while(M--){
        int a, b;
        cin >> a >> b;
        if(a == 1){
            update(chain_number[b], chain_idx[b], 1, 0, chain[chain_number[b]].size()-1);
        }
        else{
            pii temp = query1(b);
            if(temp.first == -1){
                cout << -1 <<'\n';
            }
            else{
            cout << chain[temp.first][temp.second] << '\n';
            }
        }
    }
}
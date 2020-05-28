#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
const int MAX_N = 100'001;
int N;
vector<pii> segtree(4*MAX_N, {INT_MAX,-1});

void update(int idx, int v, int r = 1, int li = 0, int ri = N-1){
    if(li == ri && idx == li){
        segtree[r] = {v, idx};
        //cout << idx << " " << v << " " << r << " " << li << " " << ri << " " << segtree[r].first << " " << segtree[r].second << '\n';
        return ;
    }

    if(li > idx || ri < idx)return;
    int mid = (li + ri)/2;
    update(idx,v,r*2, li, mid);
    update(idx,v,r*2+1,mid+1,ri);

    if(segtree[r*2].first <= segtree[r*2+1].first){
        segtree[r] = segtree[r*2];
    }
    else segtree[r] = segtree[r*2+1]; 
   // cout << idx << " " << v << " " << r << " " << li << " " << ri << " " << segtree[r].first << " " << segtree[r].second << '\n';
}

pii query(int ql, int qr, int r = 1, int li = 0, int ri = N-1){
    if(ql > ri || qr < li)return {INT_MAX, -1};
    if(ql <= li && ri <= qr){
        return segtree[r];
    }   

    int mid =(li + ri)/2;

    pii qql = query(ql,qr,r*2,li,mid);
    pii qqr = query(ql,qr,2*r+1,mid+1,ri);
    return qql.first <= qqr.first ? qql : qqr;
}
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N;
    
    for(int i = 0; i < N; i++){
        int k;
        cin >> k;
        update(i,k);
    }
    
    int Q;
    cin >> Q;
    while(Q--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            update(b-1,c);
        }
        else{
            cout << query(b-1,c-1).second+1 << '\n';
        }
    }
}
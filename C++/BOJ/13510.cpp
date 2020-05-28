#include <bits/stdc++.h>

using namespace std;
const int MAX_INT = 987654321;
const int MAX_V = 100'001;
int N, M;
vector<int> adj[MAX_V];
map<int,map<int,int>> weight;
map<int,pair<int,int>> edge;
vector<vector<int>> arr, tree;
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
int chain_sz[MAX_V];
int chain_map[MAX_V];
int map_inverse[MAX_V];
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

int update(int ch, int x, int v, int root, int root_li, int root_ri){
   //cout << ch << " " << x << " " << v << " " << root << " " << root_li << " " << root_ri << " " << tree[ch][root] << '\n';
   if(root_li == root_ri && root_ri == x){
      tree[ch][root] = v;
      return tree[ch][root];
   }   

   if(root_ri < x || x < root_li)return tree[ch][root];

   int mid = (root_li + root_ri)/2;
   tree[ch][root] = max(update(ch,x,v,root*2,root_li,mid), update(ch,x,v,root*2+1,mid+1,root_ri));
   return tree[ch][root];
}

int query(int ch, int li, int ri, int root, int root_li, int root_ri){
   //cout << ch << " " << li << " " << ri << " " << root << " " << root_li << " " << root_ri << '\n';
   if(root_ri < li || root_li > ri)return 0;
   if(li <= root_li && root_ri <= ri)return tree[ch][root];

   int mid = (root_li + root_ri)/2;
   return max(query(ch,li,ri,root*2,root_li,mid),query(ch,li,ri,root*2+1,mid+1,root_ri));
}

int lca(int a, int b){
   int answer = 0;
   while(chain_number[a] != chain_number[b]){
      //cout << a << " " << b << '\n';
      if(depth[a] > depth[b]){
         int chain_cur = chain_map[chain_number[a]];
         answer = max(answer, query(chain_cur, 0, chain_idx[a], 1, 0, arr[chain_cur].size()-1));
         a = par[chain_number[a]];
      }
      else{
         int chain_cur = chain_map[chain_number[b]];
         answer = max(answer, query(chain_cur, 0, chain_idx[b], 1, 0, arr[chain_cur].size()-1));
         b = par[chain_number[b]];
      }
   }
   int ma = max(chain_idx[a],chain_idx[b]);
   int mi = min(chain_idx[a],chain_idx[b]);
   int chain_cur = chain_map[chain_number[a]];
   answer= max(answer, query(chain_cur, mi+1, ma, 1, 0, arr[chain_cur].size()-1));
   return answer;
}

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N;
    for(int i = 0; i < N - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        weight[a][b] = c;
        weight[b][a] = c;
        edge[i+1] = {a,b};
    }
    dfs(1,0);
    hld(1,0,1,0);
   int cur = 0;
   
   
   for(int i = 1; i <= N; i++){
      if(chain[i].size() > 0){
         map_inverse[cur] = i;
         chain_map[i] = cur++;
      }

   }
   arr = vector<vector<int>>(cur);
   tree = vector<vector<int>>(cur);
   for(int i = 0; i < cur; i++){
      arr[i] = vector<int>(chain[map_inverse[i]].size());
      tree[i] = vector<int>(chain[map_inverse[i]].size() * 4 + 1, 0);
   }

   for(int i = 1; i <= N; i++){
      arr[chain_map[chain_number[i]]][chain_idx[i]] = weight[i][par[i]];
   }
   /*
   for(int i = 0; i < cur; i++){
      for(int j = 0; j < arr[i].size(); j++){
         cout << arr[i][j] << " ";
      }
      cout << '\n';
   }   
   */
   
  for(int i = 0; i < cur; i++){
     for(int j = 0; j < arr[i].size(); j++){
        update(i,j,arr[i][j],1,0,arr[i].size()-1);
     }
  }
  /*
   cout << '\n';
   for(int i = 0; i < tree[0].size(); i++){
      cout << tree[0][i] << ' ';
   }
   cout << '\n';
   */
   cin >> M;
   while(M--){
      int a, b, c;
      cin >> a >> b >> c;
      if(a == 1){
         //cout << "update" << '\n';
         pair<int,int> t = edge[b];
         int u = t.first;
         int v = t.second;
         if(par[u] == v){
            int chain_cur = chain_map[chain_number[u]];
            update(chain_cur, chain_idx[u], c, 1, 0, arr[chain_cur].size()-1);
         }
         else{
            int chain_cur = chain_map[chain_number[v]];
            update(chain_cur, chain_idx[v], c, 1, 0, arr[chain_cur].size()-1);
         }
      }
      else{
         //cout << "query" << '\n';
         //cout << query(0,b,c,1,0,arr[0].size()-1) << '\n';
         cout << lca(b,c) << '\n';
      }
   }
}
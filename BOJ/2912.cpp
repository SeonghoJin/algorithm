#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int MAX = 300010;
int segtree[4*MAX];
vector<int> v(MAX);
    
int N, C;
vector<vector<int>> arr; 

void maketree(int li, int ri, int root){
    
    if(li == ri){
        segtree[root] = v[li];
        return;
    }

    int count = (ri - li + 1)/2;

    int mid = (li + ri)/2;
    maketree(li, mid, root*2);
    maketree(mid+1, ri, root*2+1);

    int cc = segtree[root*2];
    if(cc != -1){
        int t = upper_bound(arr[cc].begin(), arr[cc].end(), ri) - lower_bound(arr[cc].begin(), arr[cc].end(), li);
        if(t > count){
            segtree[root] = cc;
            return;
        }
    }
    cc = segtree[root*2+1];
    if(cc != -1){
        int t = upper_bound(arr[cc].begin(), arr[cc].end(), ri) - lower_bound(arr[cc].begin(), arr[cc].end(), li);
        if(t > count){
            segtree[root] = cc;
            return;
        }
    }
    return ;
}

int query(int li, int ri, int root, int r_li, int r_ri){
    if(li > r_ri || ri < r_li) return -1;
    if(li <= r_li && r_ri <= ri){
    int cnt = upper_bound(arr[segtree[root]].begin(),arr[segtree[root]].end(),ri)-
              lower_bound(arr[segtree[root]].begin(),arr[segtree[root]].end(),li);
    if(cnt > (ri-li+1)/2) return segtree[root];
    else return -1;      
  }
  int mid = (r_li+r_ri)/2;
  int r1 = query(li,ri,2*root,r_li,mid);
  if(r1 != -1) return r1;
  int r2 = query(li,ri,2*root+1,mid+1,r_ri);
  if(r2 != -1) return r2;
  return -1;
}

int main(){

    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N >> C;
    arr = vector<vector<int>>(C+1, vector<int>());
    
    for(int i = 0; i < N; i++){
        cin >> v[i];
        arr[v[i]].push_back(i);
    }

    maketree(0,N-1,1);

    
    int M;
    cin >> M;
    while(M--){
        int a, b;
        cin >> a >> b;
        int t = query(a-1,b-1,1,0,N-1);
        if(t == -1)cout << "no" << '\n';
        else cout << "yes " << t << '\n';
    }



  
}
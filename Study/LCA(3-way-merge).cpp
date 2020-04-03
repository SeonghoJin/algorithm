#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> adj(10001,vector<int>());
int dep[10001];
int par[10001];
int check1[10001];
int check2[10001];

void precalc(int depth, int n){
	dep[n] = depth;
	for(int i = 0; i < adj[n].size(); i++){
        if(adj[n][i] != par[n])precalc(depth+1,adj[n][i]);
	}
}

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    
	int T;
	cin >> T;
	
	while(T--){
		int N;
		cin >> N;
		for(int i = 0; i <= N; i++){adj[i].clear();}
		fill(par,par+N+1,0);
        fill(check1,check1+N+1,0);
        fill(check2,check2+N+1,0);
		int a,b;
		for(int i = 0; i < N-1; i++){
			cin >> a >> b;
			adj[a].push_back(b);
            adj[b].push_back(a);
			par[b] = a;
		}
		for(int i = 1; i <= N; i++){
			if(par[i] == 0){precalc(0,i);}
		}

        queue<int> q;
		int x,y;
		cin >> x >> y;
		q.push(x);
        check1[x] = 1;
       /* for(int i = 1; i <= 6; i++){
            cout << "i = " << i << " " <<dep[i] << '\n';
            for(int j = 0; j < adj[i].size(); j++){
                cout << adj[i][j] << " ";
            }
            cout << '\n';
        }
        cout << '\n';
        */
        while(!q.empty()){
            int here = q.front(); q.pop();
          //  cout << here << "\n";
            for(int i = 0; i < adj[here].size(); i++){
                int next = adj[here][i];
                if(check1[next] == 0 && dep[next] < dep[here]){
                    check1[next] = 1;
                    q.push(next);
                }
            }
        }

        int ans = 0;
        check2[y] = 1;
        q.push(y);
        while(!q.empty()){
            int here = q.front(); q.pop();
           // cout << here << '\n';
            if(check1[here] == 1){ans = here; break;}
            for(int i = 0; i < adj[here].size(); i++){
                int next = adj[here][i];
                if(check2[next] == 0 && dep[next] < dep[here]){
                    check2[next] = 1;
                    q.push(next);
                }
            }
        }

        cout << ans << '\n';
		
	}
}
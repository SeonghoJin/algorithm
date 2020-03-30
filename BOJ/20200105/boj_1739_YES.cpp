/*#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int MAX = 2000*2+1;
vector<int> adj[MAX];

int sero(int n){
	return n+1000;
}

int neg(int n){
	return n > 2000 ? n - 2000 : n + 2000;
}

stack<int> st;
int group[MAX], g_cnt = 1, cnt = 1;
int pos[MAX];

int makeSCC(int n){
		int cur = pos[n] = cnt++;
	
	st.push(n);
	
	for(int i = 0; i < adj[n].size(); i++){
		int next = adj[n][i];
		
		if(pos[next] == 0){
			cur = min(cur, makeSCC(next));
		}
		else if(group[next] == 0){
			cur = min(cur, pos[next]);
		}
		
	}
	
	if(cur == pos[n]){
		int t;
		while(1){
			t = st.top(); st.pop();
			group[t] = g_cnt;
			if(t == n)break;
		}
		g_cnt++;
	}
	
	return cur;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int T;
	cin >> T;
	while(T--){
		int N, M, K;
		cin >> N >> M >> K;
		for(int i = 0; i < MAX; i++)adj[i].clear();
		fill(group, group+MAX, 0);
		fill(pos, pos+MAX, 0);
		cnt = g_cnt = 1;
		st = stack<int>();
		for(int i = 0; i < K; i++){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			b = sero(b);
			d = sero(d);
			
			int _a = neg(a), _b = neg(b), _c = neg(c), _d = neg(d);
			if(a == c && b == d)continue;
			if(a == c){
				if(b < d)adj[_a].push_back(a);
				else{
					adj[a].push_back(_a);
				}
			}
			else if(b == d){
				if(a < c){
					adj[_b].push_back(b);
				}
				else{adj[b].push_back(_b);}
			}
			else{
				if (a > c) b = neg(b), d = neg(d);
				if (b > d) a = neg(a), c = neg(c);

				adj[neg(a)].push_back(b); adj[neg(b)].push_back(a);
				adj[neg(a)].push_back(c); adj[neg(c)].push_back(a);
				adj[neg(d)].push_back(b); adj[neg(b)].push_back(d);
				adj[neg(d)].push_back(c); adj[neg(c)].push_back(d);
				
			}
		}
		
		for(int i = 1; i <= N; i++){
			if(pos[i] == 0)makeSCC(i);
			if(pos[neg(i)] == 0)makeSCC(neg(i));
		}
		
		for(int i = 1; i <= M; i++){
			if(pos[sero(i)] == 0)makeSCC(sero(i));
			if(pos[neg(sero(i))] == 0)makeSCC(neg(sero(i)));
		}
		
		bool flag = true;
		
		for(int i = 1; i <= N; i++){
			if(group[i] == group[neg(i)]){
				flag = false;
			}
		}
		
		for(int i = 1; i <= M; i++){
			int _i = sero(i);
			if(group[_i] == group[neg(_i)]){
				flag = false;
			}
		}
		
		cout << (flag ? "Yes" : "No") << '\n';
	}
	
	
	
	
}*/
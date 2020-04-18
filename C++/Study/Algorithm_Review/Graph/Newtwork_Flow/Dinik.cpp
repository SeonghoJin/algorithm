/*
첫 번째 줄에는 UCPC 구성원의 수 N(1≤N≤500)이 주어진다. 두 번째 줄에는 N개의 정수가 주어지는데, i번째 수가 1이면 i번 사람은 무조건 A진영에 들어가야 함을, 2라면 무조건 B진영에 들어가야 함을, 0이면 어느 진영에 들어가든지 상관 없다는 것을 의미한다.

세 번째 줄부터 N개의 줄에 걸쳐 i번 사람과 j번 사람이 다른 진영에 들어갈 때의 슬픔 정도 w[i, j]가 주어진다. (i+2)번째 줄에 j번째 수는 w[i, j]를 의미한다. 주어지는 입력은 항상 w[i, j]=w[j, i]를 만족하고, w[i, i]=0이다. w[i, j]는 1,000보다 크지 않은 음이 아닌 정수이다.
*/
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 505; //503 = A, 504 = B;

vector<int> A, B, mid, adjlist[MAX];
int weight[MAX][MAX];
int flow[MAX][MAX], source, sink;
int work[MAX];
int level[MAX], flag[MAX];
	
bool bfs(int source, int sink){
	fill(level, level+MAX, -1);
	
	queue<int> q;
	q.push(source);
	level[source] = 0;
	
	while(!q.empty()){
		int temp = q.front(); q.pop();
		for(auto next : adjlist[temp]){
			if(level[next] == -1 && weight[temp][next] - flow[temp][next] > 0){
				level[next] = level[temp]+1;
				q.push(next);
			}
		}
	}
	
	return level[sink] != -1;
}

int dfs(int now, int tot){
	if(now == sink)return tot;
	
	for(int& i = work[now]; i < adjlist[now].size(); i++){
		int next = adjlist[now][i];
		if(level[next] == level[now]+1 && weight[now][next] - flow[now][next] > 0){
			int fl = dfs(next, min(tot,weight[now][next] - flow[now][next] ));
			if(fl > 0){
				flow[now][next] += fl;
				flow[next][now] -= fl;
				return fl;
			}
		}
		
	}
	return 0;
	
}

int networkflow(int source, int sink){
	int totalflow = 0;
	
	while(bfs(source,sink)){
		fill(work,work+MAX,0);
		while(1){
			int fl = dfs(source, 987654321);
			if(!fl)break;
			totalflow+= fl;
		}
	}
	
	return totalflow;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int N;
	cin >> N;
	source = N;
	sink = N+1;
	
	for(int i = 0; i < N; i++){
		int temp;
		cin >> temp;
		if(temp == 0)mid.push_back(i);
		else if(temp == 1){
			weight[i][source] = weight[source][i] = 987654321;
			adjlist[i].push_back(source);
			adjlist[source].push_back(i);
		}
		else{
			weight[i][sink] = weight[sink][i] = 987654321;
			adjlist[i].push_back(sink);
			adjlist[sink].push_back(i);
		}
	}
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			int t; cin >> t;
			weight[i][j] = weight[j][i] = t;
			if(i == j)continue;
			adjlist[i].push_back(j);
		}
	
	cout << networkflow(source,sink) << '\n';
	queue<int> t_q;
	
	t_q.push(source);
	level[source] = 1;
	fill(level, level+MAX, 0);
	while(!t_q.empty()){
		int temp = t_q.front(); t_q.pop();
		
		for(int i = 0; i < MAX; i++){
			if(level[i] == 0 && weight[temp][i] - flow[temp][i] > 0){
				level[i] = 1;
				t_q.push(i);
			}
		}
	}
	vector<int> temp_A, temp_B;
	
	for(int i = 0; i < N; i++){
		if(level[i]){
			temp_A.push_back(i);
		}
		else temp_B.push_back(i);
	}
	
	for(auto i : temp_A){
		cout << i+1 << " ";
	}
	cout << '\n';
	
	for(auto i : temp_B){
		cout << i+1 << " ";
	}
	cout << '\n';
	
	
}

/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>; 


typedef struct _edge{
	int rev;
	int there;
	int cap;
	int flow;
	_edge(int rev, int there, int cap, int flow) : rev(rev), there(there), cap(cap), flow(flow){}
}edge;

pii s,t;
string str[101];
int N, M;
int dy[4] = {0,1,0,1};
int dx[4] = {1,0,-1,0};
int level[20001], work[20001];
vector<edge> adj[20001];


bool check(int y, int x){
	return !(y < 0 || y >= N || x < 0 || x >= M || str[y][x] == '#');
}

int mapping(int y, int x){
	return y*M+x;
}

bool bfs(int source, int sink){
	fill(level, level+20001, -1);
	queue<int> q;
	q.push(source);
	level[source] = 0;
	
	while(!q.empty()){
		int here = q.front(); q.pop();
		for(auto e : adj[here]){
			int there = e.there;
			
			if(level[there] == -1 && e.cap - e.flow > 0){
				level[there] = level[here]+1;
				q.push(there);
			}
		}
		
	}
		
	return level[sink] != -1;
}

int dfs(int here, int fl, int sink){
	if(here == sink)return fl;
	
	for(int& i = work[here]; i < adj[here].size(); i++){
		int there = adj[here][i].there;
		int cap = adj[here][i].cap - adj[here][i].flow;
		
		if(level[here] - level[there] == -1 && cap > 0){
			int cfl = dfs(there, min(cap,fl), sink);
			if(cfl > 0){
				adj[here][i].flow += cfl;
				adj[there][adj[here][i].rev].flow -= cfl;
				return cfl;
			}
		}
	}
	
	return 0;
}

int dinik(int source, int sink){
	int ret = 0;
	
	while(bfs(source,sink)){
		fill(work, work+20001, 0);
		while(1){
			int fl = dfs(source, 987654321, sink);
			if(fl == 0)break;
			ret += fl;
		}
	}
	
	return ret;
}



int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		cin >> str[i];
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(str[i][j] == 'K'){s = {i,j};}
			if(str[i][j] == 'H'){t = {i,j};}
		}
	}
	
	bool flag = true;
	
	for(int i = 0; i < 4; i++){
		int ty = dy[i] + s.first;
		int tx = dx[i] + s.second;
		if(check(ty,tx) && ty == t.first && tx == t.second){flag = false; break;}
	}
	
	if(!flag){
		cout << "-1";
	}
	else{
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(str[i][j] == '#')continue;
				int h_in = 2*mapping(i,j);
				int h_out = 2*mapping(i,j) + 1;
				
				if((i == s.first && j == s.second) || i == t.first && j == t.second){
					if(i == s.first && j == s.second){
						adj[h_in].push_back({(int)adj[h_out].size(), h_out, 987654321, 0});
						adj[h_out].push_back({(int)adj[h_in].size()-1,h_in, 0,0});
					}
					else{
						adj[h_in].push_back({(int)adj[h_out].size(), h_out, 987654321, 0});
						adj[h_out].push_back({(int)adj[h_in].size()-1,h_in, 0,0});
					}
				}
				else{
					adj[h_in].push_back({(int)adj[h_out].size(), h_out, 1, 0});
					adj[h_out].push_back({(int)adj[h_in].size()-1,h_in, 0,0});
				}
					for(int k = 0; k < 4; k++){
					if(k == 2 || k == 3)continue;
					int ty = i + dy[k];
					int tx = j + dx[k];
					
					if(check(ty, tx)){
						int t_in = 2 * mapping(ty,tx);
						int t_out = 2 * mapping(ty,tx) + 1;
						adj[h_out].push_back({(int)adj[t_in].size(), t_in, 1, 0});
						adj[t_in].push_back({(int)adj[h_out].size()-1, h_out, 0, 0});
						
						adj[t_out].push_back({(int)adj[h_in].size(), h_in, 1, 0});
						adj[h_in].push_back({(int)adj[t_out].size()-1, t_out, 0, 0});
					}
				}
			}
		}
		
		
		int res = dinik(2 * mapping(s.first, s.second), 2*mapping(t.first, t.second) + 1);
				
		cout << res;
	}
	
}
*/
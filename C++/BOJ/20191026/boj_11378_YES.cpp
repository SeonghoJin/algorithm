/*
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

const int V_MAX = 1003;

int adj[2*V_MAX][2*V_MAX], Flow[2*V_MAX][2*V_MAX];
int adj1[2*V_MAX][2*V_MAX], Flow1[2*V_MAX][2*V_MAX];

int N, M, K;
vector<int> adjlist[2*V_MAX];
vector<int> adjlist1[2*V_MAX];



int networkflow(int source, int sink){
	
	int total = 0;
	
	while(1){
		queue<int> q;
		vector<int> parent(2*V_MAX, -1);
		parent[source] = source;
		q.push(source);
		while(!q.empty() && parent[sink] == -1){
			int next = q.front(); q.pop();
			for(int k = 0; k < adjlist[next].size(); k++){
				int i = adjlist[next][k];
				if(adj[next][i] - Flow[next][i]  > 0 && parent[i] == -1){
					parent[i] = next;
					q.push(i);
				}
			}
		}
		if(parent[sink] == -1) break;
		int lowflow = 987654321;
		
		for(int i = sink; i != source; i = parent[i]){
			lowflow = min(lowflow, adj[parent[sink]][sink]-Flow[parent[sink]][sink]);
		}
		for(int i = sink; i != source; i = parent[i]){
			Flow[parent[i]][i] += lowflow;
			Flow[i][parent[i]] -= lowflow;
		}
		
		total += lowflow;
		
	}
	
	return total;
	
}


int networkflow1(int source, int sink){
	
	int total = 0;
	
	while(1){
		queue<int> q;
		vector<int> parent(2*V_MAX, -1);
		parent[source] = source;
		q.push(source);
		while(!q.empty() && parent[sink] == -1){
			int next = q.front(); q.pop();
			for(int k = 0; k < adjlist1[next].size(); k++){
				int i = adjlist1[next][k];
				if(adj1[next][i] - Flow1[next][i]  > 0 && parent[i] == -1){
					parent[i] = next;
					q.push(i);
				}
			}
		}
		if(parent[sink] == -1) break;
		int lowflow = 987654321;
		
		for(int i = sink; i != source; i = parent[i]){
			lowflow = min(lowflow, adj1[parent[sink]][sink]-Flow1[parent[sink]][sink]);
		}
		for(int i = sink; i != source; i = parent[i]){
			Flow1[parent[i]][i] += lowflow;
			Flow1[i][parent[i]] -= lowflow;
		}
		
		total += lowflow;
		
	}
	
	return total;
	
}

void t(){
	
	int a = networkflow(0,1002);
	int b = networkflow1(0,1002);
	cout << a << " " << b;
	
	if(a != b){
		for(int i = 0; i < 2*V_MAX; i++){
			if(adjlist[i].size() > 0){
				cout << "점" << i << " ";
				for(int j = 0; j < adjlist[i].size(); j++){
					cout << adjlist[i][j] << " ";
				}
				cout << '\n';
			}
		}
	}
	
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> N >> M >> K;
	srand(time(NULL));
	
	adj[0][1001] = K;
	adjlist[0].push_back(1001);
	adjlist[1001].push_back(0);
	adj1[0][1001] = N+K;
	adjlist1[0].push_back(1001);
	adjlist1[1001].push_back(0);
	int flag = 0;
	for(int i = 1; i <= N; i++){
		int T;
		cin >> T;
		adj[0][i] = 1;
		adjlist[0].push_back(i);
		adjlist[i].push_back(0);
		adjlist[1001].push_back(i);
		adjlist[i].push_back(1001);
		adj[1001][i] = K;
		
		adj1[1001][i] = 1+K;
		adjlist1[1001].push_back(i);
		adjlist1[i].push_back(1001);
		
		int visit[V_MAX*2];
		for(int i = 0; i < V_MAX*2; i++){visit[i] = 0;}
		if(T == 0)flag = 1;
		while(T--){
			int A;
			cin >> A;
			A = rand()%M + 1;
			adjlist[i].push_back(A+1003);
			adjlist[A+1003].push_back(i);
			adj[i][A+1003] = 1;
			adjlist1[i].push_back(A+1003);
			adjlist1[A+1003].push_back(i);
			adj1[i][A+1003] = 1;
		}
	}
	
	for(int i = 1; i <= M; i++){adj[1003+i][1002] = 1;
		adjlist[1003+i].push_back(1002);
		adjlist[1002].push_back(1003+i);
	adj1[1003+i][1002] = 1;
		adjlist1[1003+i].push_back(1002);
		adjlist1[1002].push_back(1003+i);
	}
	
	
	
	cout << (flag ? networkflow(0,1002) : networkflow1(0,1002));
}


#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

const int V_MAX = 1003;

int adj[2*V_MAX][2*V_MAX], Flow[2*V_MAX][2*V_MAX];
int adj1[2*V_MAX][2*V_MAX], Flow1[2*V_MAX][2*V_MAX];

int N, M, K;
vector<int> adjlist[2*V_MAX];
vector<int> adjlist1[2*V_MAX];



int networkflow(int source, int sink){
	
	int total = 0;
	
	while(1){
		queue<int> q;
		vector<int> parent(2*V_MAX, -1);
		parent[source] = source;
		q.push(source);
		while(!q.empty() && parent[sink] == -1){
			int next = q.front(); q.pop();
			for(int k = 0; k < adjlist[next].size(); k++){
				int i = adjlist[next][k];
				if(adj[next][i] - Flow[next][i]  > 0 && parent[i] == -1){
					parent[i] = next;
					q.push(i);
				}
			}
		}
		if(parent[sink] == -1) break;
		int lowflow = 987654321;
		
		for(int i = sink; i != source; i = parent[i]){
			lowflow = min(lowflow, adj[parent[sink]][sink]-Flow[parent[sink]][sink]);
		}
		for(int i = sink; i != source; i = parent[i]){
			Flow[parent[i]][i] += lowflow;
			Flow[i][parent[i]] -= lowflow;
		}
		
		total += lowflow;
		
	}
	
	return total;
	
}


int networkflow1(int source, int sink){
	
	int total = 0;
	
	while(1){
		queue<int> q;
		vector<int> parent(2*V_MAX, -1);
		parent[source] = source;
		q.push(source);
		while(!q.empty() && parent[sink] == -1){
			int next = q.front(); q.pop();
			for(int k = 0; k < adjlist1[next].size(); k++){
				int i = adjlist1[next][k];
				if(adj1[next][i] - Flow1[next][i]  > 0 && parent[i] == -1){
					parent[i] = next;
					q.push(i);
				}
			}
		}
		if(parent[sink] == -1) break;
		int lowflow = 987654321;
		
		for(int i = sink; i != source; i = parent[i]){
			lowflow = min(lowflow, adj1[parent[sink]][sink]-Flow1[parent[sink]][sink]);
		}
		for(int i = sink; i != source; i = parent[i]){
			Flow1[parent[i]][i] += lowflow;
			Flow1[i][parent[i]] -= lowflow;
		}
		
		total += lowflow;
		
	}
	
	return total;
	
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	//cin >> N >> M >> K;
	srand(time(NULL));
	int temp = 1;
	while(1){
		for(int i = 0; i < 2*V_MAX; i++){
			fill(adj[i],adj[i]+2*V_MAX, 0);
			fill(adj1[i],adj1[i]+2*V_MAX, 0);
			fill(Flow[i],Flow1[i]+2*V_MAX, 0);
			fill(Flow1[i],Flow1[i]+2*V_MAX, 0);
			adjlist[i].clear();
			adjlist1[i].clear();
		}
		
	N = rand()%100+1;
	M = rand()%110+1;
	K = rand()%50;
	adj[0][1001] = K;
	adjlist[0].push_back(1001);
	adjlist[1001].push_back(0);
	adj1[0][1001] = N+K;
	adjlist1[0].push_back(1001);
	adjlist1[1001].push_back(0);
	
	for(int i = 1; i <= N; i++){
		int T;
		//cin >> T;
		T = rand()%M;
		adj[0][i] = 1;
		adjlist[0].push_back(i);
		adjlist[i].push_back(0);
		adjlist[1001].push_back(i);
		adjlist[i].push_back(1001);
		adj[1001][i] = K;
		
		adj1[1001][i] = 1+K;
		adjlist1[1001].push_back(i);
		adjlist1[i].push_back(1001);
		
		int visit[V_MAX*2];
		fill(visit, visit+V_MAX*2, 0);
		while(T--){
			int A;
			//cin >> A;
			A = rand()%M + 1;
			if(visit[A] == 1)continue;
			visit[A] = 1;
			adjlist[i].push_back(A+1003);
			adjlist[A+1003].push_back(i);
			adj[i][A+1003] = 1;
			adjlist1[i].push_back(A+1003);
			adjlist1[A+1003].push_back(i);
			adj1[i][A+1003] = 1;
		}
	}
	
	for(int i = 1; i <= M; i++){adj[1003+i][1002] = 1;
		adjlist[1003+i].push_back(1002);
		adjlist[1002].push_back(1003+i);
	adj1[1003+i][1002] = 1;
		adjlist1[1003+i].push_back(1002);
		adjlist1[1002].push_back(1003+i);
	}
	
	int a = networkflow(0,1002);
	int b = networkflow1(0,1002);
	cout << temp++ << "번째 시도 \n";
	if(a != b){
		for(int i = 0; i < 2*V_MAX; i++){
			if(adjlist[i].size() > 0){
				cout << "점" << i << " ";
				for(int j = 0; j < adjlist[i].size(); j++){
					cout << adjlist[i][j] << " ";
				}
				cout << '\n';
			}
		}
	}
	
	}
}






*/






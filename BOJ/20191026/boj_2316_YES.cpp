#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

const int MAX = 410;
int N, P;

int cap[2*MAX][2*MAX];
int flow[2*MAX][2*MAX];

int networkflow(int source, int sink){
	
	int fl = 0;
	
	while(1){
		
		queue<int> q;
		vector<int> visit(2*MAX,-1);
		visit[source] = source;
		
		q.push(source);
		
		while(!q.empty() && visit[sink] == -1){
			int n = q.front(); q.pop();
			for(int there =1; there <= 2*N; there++){
				if(cap[n][there] - flow[n][there] > 0 && visit[there] == -1){
					visit[there] = n;
					q.push(there);
				}
			}
		}
		if(visit[sink] == -1)break;
		for(int i = sink; i != source; i = visit[i]){
			int p = visit[i];
			flow[p][i] += 1;
			flow[i][p] -= 1;
		}
		
		fl++;
	}
	return fl;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> N >> P;
	cap[1][2] = cap[3][4] = 987654321;
	
	for(int i = 3; i <= N; i++){
		cap[2*i-1][2*i] = 1;
	}
	
	for(int i = 0; i < P; i++){
		int a, b;
		cin >> a >> b;
		cap[2*a][2*b-1] = 1;
		cap[2*b][2*a-1] = 1;
	}
	
	cout << networkflow(1,4);
}
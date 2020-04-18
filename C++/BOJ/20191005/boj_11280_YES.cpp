
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;
const int MAX = 10000;

int low[2*MAX+2], group[2*MAX+2], cnt = 1, scnt = 1;
int N, M;
vector<int> adj[2*MAX+2];
stack<int> s;

int neg(int x){
	return x > N ? x-N : x+N;
}

int makeSCC(int n){
	int result = low[n] = cnt++;
	s.push(n);
	
	for(int i = 0; i < adj[n].size(); i++){
		int next = adj[n][i];
		if(low[next] == 0){
			result = min(result, makeSCC(next));
		}
		else if(group[next] == 0){
			result = min(result,low[next]);
		}
	}
	
	if(result == low[n]){
		
		while(1){
			int t = s.top(); s.pop();
			group[t] = scnt;
			if(t == n)break;
		}
		scnt++;
	}
	return result;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N >> M;
	for(int i = 0 ; i < M; i++){
		int a, b;
		cin >> a >> b;
		a = a > 0 ? a : N+-a;
		b = b > 0 ? b : N+-b;
		adj[neg(a)].push_back(b);
		adj[neg(b)].push_back(a);
	}
	
	for (int v = 1; v <= 2*N; v++) {
        if (low[v] == 0) {
            makeSCC(v);
        }
    }
	int answer = 1;
	
    for (int v = 1; v <= N; v++) {
        if (group[v] == group[neg(v)]) {
            answer = 0; break;
        }
    }
	cout << answer << '\n';
	if(answer == 1){
    for (int v = 1; v <= N; v++) {
        cout << (group[v] < group[neg(v)]) << " ";
    }
	}
   
}

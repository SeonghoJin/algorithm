/*#include <vector>
#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

const int N_MAX = 10001;

vector<int> adjlist[2*N_MAX];

int N, M;

int neg(int n){
	return n <= M ? n + M : n - M;
}

int mp(int n){
	return n > 0 ? n : abs(n) + M;
}

stack<int> s;
int cur, gcur;
int pos[2*N_MAX];
int here[2*N_MAX];
int makeSCC(int n){
	int c = here[n] = ++cur;
	s.push(n);
	
	for(auto next : adjlist[n]){
		
		if(here[next] == 0){
			here[n] = min(here[n], makeSCC(next));
		}
		else if(pos[next] == 0){
			here[n] = min(here[n], here[next]);
		}
		
	}
	
	if(here[n] == c){
		gcur++;
		while(1){
			
			int t = s.top(); s.pop();
			pos[t] = gcur;
			if(t == n)break;
		}
	}
	
	return here[n];
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N >>  M;
	
	for(int i = 1; i <= N; i++){
		int a, b;
		cin >> a >> b;
		a = mp(a);
		b = mp(b);
		if(a == b)adjlist[neg(a)].push_back(a);
		else{
			adjlist[neg(a)].push_back(b);
			adjlist[neg(b)].push_back(a);
		}
	}
	
	for(int i = 1; i <= 2*M; i++){
		if(pos[i] == 0){
			makeSCC(i);
		}
	}
	bool flag = true;
	for(int i = 1; i <= M; i++){
		if(pos[i] == pos[i+M]){
			flag = false;
		}
	}
	
	cout << (flag ? "^_^" : "OTL");
}*/
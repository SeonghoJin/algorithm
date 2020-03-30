#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

bool isPrime[2001];
int N, visit[50], num[50], memo[50];
vector<int> canNum[50];
vector<int> calc;
set<int> s;
int V,T;
		
int dfs(int k){
	if(visit[k])return 0;
	visit[k] = 1;
	for(int i = 0; i < canNum[k].size(); i++){
		int next = canNum[k][i];
		if(next == T)continue;
		if((memo[next] == -1) || dfs(memo[next])){
			memo[next] = k;
			return 1;
		}
	}
	
	return 0;
}	

void precalc(){
	fill(isPrime,isPrime+2001,1);
	isPrime[1] = true;
	for(int i = 2; i <= 2000; i++){
		if(isPrime[i]){
			for(int j = i*i; j <= 2000; j+=i){
				isPrime[j] = 0;
			}
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			if(isPrime[num[i]+num[j]]){
				canNum[i].push_back(j);
				canNum[j].push_back(i);
			}
		}
	}
}


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N;
	for(int i = 0; i < N; i++){cin >> num[i];
		if(num[i]%2 == 0){calc.push_back(i);}
	}
	precalc();
	set<int> temp;
	
	for(int j = 0; j < canNum[0].size(); j++){
		if(calc.size() != N/2)break;
		int ans = 1;
		fill(memo,memo+N,-1);
		int n = num[0];
		if(n%2){
			V = canNum[0][j];
			T = 0;
		}
		else{V = 0; T = canNum[0][j];}
		for(int i = 0; i < calc.size(); i++){
			fill(visit,visit+N,0);
			visit[V] = 1;
			if((calc[i] != V)&& dfs(calc[i]))ans++;
		}
		
		if(ans == N/2){temp.push(num[canNum[0][j]]);}
		
	}
	
	if(temp.size() > 0 && calc.size() == N/2){
	for(auto it = temp.begin(); it != temp.end(); it++){
		cout << *it << " ";
	}
	}
	else {cout << -1;}
	
	

}
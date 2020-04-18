/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int N;
	

int ans(int num){
	
	queue<pair<int, int>> q;
	vector<int> visit(N+1,0);
	q.push({num,0});
	
	while(!q.empty()){
		int n = q.front().first; int len = q.front().second;
		if(n == 0)return len;
		q.pop();
		for(int i = 1; i * i <= n; i++){
			if(visit[n-i*i])continue;
			visit[n - i*i] = 1;
			q.push({n - i*i,len+1});
		}
	}
		
	
	return -1;
}

int main(){
	cin >> N;
	cout << ans(N);
}*/
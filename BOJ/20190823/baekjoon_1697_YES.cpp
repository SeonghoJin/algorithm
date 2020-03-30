/*
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int visit[100001] = {0,};

int main(){
	int N, K;
	cin >> N >> K;
	queue<pair<int,int>> q;
	q.push(make_pair(N,0));
	visit[N] = 1;
	int answer = 0;
	while(!q.empty()){
		int temp = q.front().first;
		int t = q.front().second;
		q.pop();
		if(temp == K){answer = t; break;}
		
		if(2*temp <= 100000 && visit[2*temp] == 0 ){
			visit[2*temp] = 1;
			q.push(make_pair(temp*2,t+1));}
		if(temp+1 <= 100000 &&visit[temp+1] == 0 ){visit[temp+1] = 1;
							   q.push(make_pair(temp+1,t+1));}
		if(temp-1>= 0 && visit[temp-1] == 0 ){visit[temp-1] = 1;
							   q.push(make_pair(temp-1,t+1));}
	}
	
	cout << answer << endl;
}*/
/*
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;
using pii = pair<int, int>; 

int dp[100001] = {0,};

int main(){
	memset(dp,-1,sizeof(dp));
	int N, K;
	cin >> N >> K;
	queue<pair<int, int>> q;
	q.push({N,0});
	dp[N] = -2;
	int answer_depth;
	
	while(!q.empty()){
		pii temp= q.front();
		q.pop();
		
		int value = temp.first;
		int depth = temp.second;
		
		if(value == K){
			answer_depth = depth;
			break;
		}
		
		if(value*2 <= 100000 && dp[value*2] == -1){dp[value*2] = value; q.push({value*2, depth+1});}
		if(value-1 >= 0 && dp[value-1] == -1){dp[value-1] = value;q.push({value-1,depth+1});}
		if(value+1 <= 100000 && dp[value+1] == -1){dp[value+1] = value;q.push({value+1,depth+1});}
		
	}
	
	cout << answer_depth << '\n';
	
	stack<int> s;
	int st = K;
	while(st != -2){
		s.push(st);
		st = dp[st];
	}
	
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	
}
*/
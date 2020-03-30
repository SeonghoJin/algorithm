#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
int dp[1000001] = {0,};
int f(int n){
	
	queue<pair<int,int>> q;
	q.push(make_pair(n,0));
	
	int answer = 0;
	
	while(!q.empty()){
		
		pair<int, int> temp = q.front();
		q.pop();
		if(temp.first == 1){answer = temp.second;break;}
		
		if(temp.first-1 > 0 && (!dp[temp.first-1])){q.push(make_pair(temp.first-1,temp.second+1)); dp[temp.first-1] = temp.first;}
		if(!(temp.first%2) && (!dp[temp.first/2])){q.push(make_pair(temp.first/2,temp.second+1)); dp[temp.first/2] = temp.first;}
		if(!(temp.first%3) && (!dp[temp.first/3])){q.push(make_pair(temp.first/3,temp.second+1));dp[temp.first/3] = temp.first;}
		
	}
	
	return answer;
}


int main(){
	
	int N;
	
	cin >> N;
	cout << f(N) << '\n'; 	
	vector<int> v;
	v.push_back(1);
	int pr = dp[1];
	while(pr != 0){
		v.push_back(pr);
		pr = dp[pr];
	}
	
	reverse(v.begin(),v.end());
	
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	
}
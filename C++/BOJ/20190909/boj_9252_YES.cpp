#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

int dp[1001][1001];

int sz1,sz2;

void print(int dp[1001][1001]){
	for(int i = 0; i < sz2; i++){
		for(int j = 0; j < sz1; j++){
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
}


int main(){
	string s1,s2;
	cin >> s1 >> s2;
	memset(dp,0,sizeof(dp));
	
	s1 = "0"+s1;
	s2 = "0"+s2;
	
	sz1 = s1.size();
	sz2 = s2.size();
	
	for(int i = 1; i < sz2; i++){
		for(int j = 1; j < sz1; j++){
			
			if(s2[i] == s1[j]){
				dp[i][j] = dp[i-1][j-1]+1;
			}	
			else{
				dp[i][j] = max({dp[i-1][j],dp[i][j-1]});
			}
			
		}
	}
	
		
	int arr[1001] = {0,};
	int st = dp[sz2-1][sz1-1];
	stack<int> s;
	
	int i = sz2-1;
	int j = sz1-1;
	
	while(st != 0){
				
		if(dp[i-1][j] == st){
			i--;
		}
		else if(dp[i][j-1] == st){
			j--;
		}
		else{
			s.push(i);
			i--; j--;
			st = dp[i][j];
		}
		
	}
	
	cout << dp[sz2-1][sz1-1] << '\n';
	while(!s.empty()){
		cout << s2[s.top()];
		s.pop();
	}
	
	
	
}
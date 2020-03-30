/*
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

char arr[5] = {'D','S','L','R','D'};
int dp[10000]; // 0 : D //1 : S //2 : L // 3: R

int ch(int N, int op){
	int t;
	switch(op){
		case 0:
			return (N*2)%10000;
			break;
		case 1
			return N == 0 ? 9999 : N-1;
			break;
		case 2:
			t = N/1000;
			return (N%1000)*10+t;
			break;
		case 3:
			t = N%10;
			return (N/10+t*1000);
			break;
	}
	
}

int trace(int N, int op){
	int t;
	switch(op){
		case 0:
			return N/2;
			break;
		case 1:
			return N == 9999 ? 0 : N+1;
			break;
		case 2:
			t = N%10;
			return (N/10+t*1000);
			break;
		case 3:
			t = N/1000;
			return (N%1000)*10+t;
			break;
		case 4:
			return (N+10000)/2;
			break;
			
	}
}


int main(){
	
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		memset(dp,-1,sizeof(dp));
		int A, B;
		cin >> A >> B;
		
		int front = 0;
		int rear = 0;
		int q[10010];
		dp[A] = -2;
		q[rear++] = A;
		
		
		while(front < rear){
			
			int temp = q[front++];
			if(temp == B)break;
			
			for(int i = 0; i < 4; i++){
				int new_v = ch(temp,i);
				if(dp[new_v] == -1){
					dp[new_v] = ((i == 0) && (2*temp >= 10000)) ? 4 : i; 
					q[rear++] = new_v;
				}
			}
			
		}
		
		stack<int> s;
			int start = B;
			while(1){
				if(dp[start] == -2)break;
				s.push(dp[start]);
				start = trace(start,dp[start]);
			}
		
			while(!s.empty()){
				cout << arr[s.top()];
				s.pop();
			}
		
			cout << '\n';
		
	}
	
}
*/
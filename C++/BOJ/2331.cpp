#include <bits/stdc++.h>

using namespace std;

map<int, int> m;
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	int N, P;
	cin >> N >> P;
	int cur = 1;
	int answer = 0;
	while(1){
		if(m[N] > 0){
			answer = m[N]-1;
			break;	
		}
		answer++;
		m[N] = cur++;
		
		int next = 0;
		while(N){
			int temp = 1;
			int tar = N%10;
			for(int i = 0; i < P; i++){
				temp *= tar;
			}
			next += temp;
			N/=10;
		}
		
		N = next;
	}
	cout << answer;
}
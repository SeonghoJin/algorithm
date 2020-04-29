#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
 
	int T;
	cin >> T;
	char Arr[100][100];
	while(T--){
		int N, M;
		cin >> N >> M;
		
 
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(i < N/2){
					Arr[i][j] = 'W';
				}
				else{
					Arr[i][j] = 'B';
				}
			}
		}
		
		for(int i = 0; i < N; i++){
			Arr[i][0] = 'B';
		}
 
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				cout << Arr[i][j];
			}
			cout << '\n';
		}
 
		
 
		
	}
 
}
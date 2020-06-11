#include <bits/stdc++.h>
 
using namespace std;
int m[51][51];
int a, b;
void print(){
	for(int i = 0; i < a; i++){
		for(int j = 0; j < b; j++){
			cout << m[i][j] << " ";
		}
		cout << '\n';
	}
	
}
 
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
 
	int T;
	cin >> T;
	while(T--){
		cin >> a >> b;
		queue<pair<int,int>> q;
		for(int i = 0; i < a; i++){
			for(int j = 0; j < b; j++){
				cin >> m[i][j];
				if(m[i][j]){
					q.push({i,j});
				}
			}
		}
		
		while(!q.empty()){
			pair<int,int> temp = q.front(); q.pop();
			int ny = temp.first;
			int nx = temp.second;
			for(int k = 0; k < b; k++){
				m[ny][k] = 1;
			}
			for(int k = 0; k < a; k++){
				m[k][nx] = 1;
			}
		}
		
		int cur = 1	;
 
		while(1){
			//print();
		//	cout << '\n';
			int flag = true;
			for(int i = 0; i < a; i++){
				for(int j = 0; j < b; j++){
					if(m[i][j] == 0){
						flag = false;
						m[i][j] = 1;
						for(int k = 0; k < b; k++){
							m[i][k] = 1;
						}
						for(int k = 0; k < a; k++){
							m[k][j] = 1;
						}
						i = a;
						break;
					}
				}
			}
			if(flag){
				cout << (cur ? "Vivek" : "Ashish") << '\n';
				break;
			}
			cur = 1 - cur;
		}
	}
}

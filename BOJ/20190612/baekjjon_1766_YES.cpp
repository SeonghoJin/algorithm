/*#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> NUM(32001,vector<int>());
int Arr[32001];
int N, M;

int main(){
	cin >> N >> M;
	
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		NUM[a].push_back(b);
		Arr[b]++;
	}
	int n = N;
	while(N){
	
		for(int i = 1; i <= n; i++){
			
			if(Arr[i]==0){
				N--; Arr[i]--;
				cout << i << " ";
				
				for(int j = 0; j < NUM[i].size(); j++){
				Arr[NUM[i][j]]--;
				}	
				break;
			}
				
			
			}
			
		}
		
		
	}
*/

#include <bits/stdc++.h>

using namespace std;

int adj[20][20];
int m[20][20];
int ans[20][20];
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> adj[i][j];
			m[i][j] = i;
		}
	}
	for (int k = 0; k < N; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (k == i || k == j || i == j) continue;

				if (adj[i][j] > adj[i][k] + adj[k][j])
				{
					cout << -1 << endl;

					return 0;
				}
			}
		}
	}
	for(int k = 0; k < N; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(adj[i][k] + adj[k][j] <= adj[i][j]){
					if(i != k && k != j){
						m[i][j] = m[k][j];
						adj[i][j] = 987654321;
					}
				}
				
			}
		}
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(m[i][j] == i){
				ans[i][j] = 1;
			}
		}
	}
	int ret = 0;
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			if(ans[i][j])ret += adj[i][j];
		}
	}
	cout << ret;
	
	


	
}
	



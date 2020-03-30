#include <iostream>
#include <cmath>

using namespace std;

int N, weight[17][17];

int memo[17][1 << 16] = {0,};

int dfs(int s, int b){
	if( b == (1 << N)-1 ){
		return weight[s][0] == 0 ? 987654321 : weight[s][0];
	}
	
	int& ret = memo[s][b];
	if(ret != 0)return ret;
	
	ret = 987654321;
	
	for(int i = 0; i < N; i++){
		if( !(b & (1 << i) ) && weight[s][i]){
			int bit = b | (1 << i);
			ret = min(ret,dfs( i, bit)+weight[s][i]);
		}
	}
	
	return ret;
}



int main(){
	cin >> N;
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			cin >> weight[i][j];
		}
	
	int answer = 987654321; 
		answer = min(answer, dfs(0,1));
	
	
	cout << answer;
	
	
	
}
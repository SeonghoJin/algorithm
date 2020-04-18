/*
#include <iostream>

using namespace std;
int M, N, K;
int p = 0;
void dfs(int arr[51][51], int y, int x){
	arr[y][x] = 0;
	if(x-1 >= 0 &&  arr[y][x-1] == 1)dfs(arr,y,x-1);
	if(x+1 <= M &&  arr[y][x+1] == 1)dfs(arr,y,x+1);
	if(y + 1 <= N && arr[y+1][x] == 1)dfs(arr,y+1,x);
	if(y - 1 >= 0 && arr[y-1][x] == 1)dfs(arr,y-1,x); 
	
}


int main(){
	int T;
	cin >> T;
	
	while(T--){
		int arr[51][51];
		int answer = 0;
		cin >> M >> N >> K;
		
		for(int i = 0; i < K; i++){
			
				int X,Y;
				cin >> X >> Y;
				arr[Y][X] = 1;
			
		}
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				
				if(arr[i][j] == 1){ dfs(arr,i,j); answer++;}
			}
		}
		
		cout << answer << endl;
		
	}
	
	
	
}*/
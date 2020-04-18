#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int M,N,H; //상자의 가로 = M, 상자의 세로 = N, 상자의 높이 =H,  2<=M<=100, 2<=N<=100, 1<=H<=100
int boxes[100][100][100];
int visitboxes[100][100][100]; //visitboxes[x][y][z] x층, y,z좌표에 있는 토마토칸에 대한 방문여부
queue<vector<int>> ripetomatoes;

//int currentboxes[100][100][100];

int answer=0;

// x = boxes[i][j][k]라 할때 x는 상자안에있는 토마토를 의미하며, x의 상태는 1,0,-1 세가지 상태로 존재한다. 
// x=1일때는 익은토마토칸, x=0일때는 익지않은 토마토칸, x=-1은 토마토가 없는 칸을 의미한다.
/*
상자안에 있는 토마토가 모두 익을 때까지 걸리는 시간은 며칠인지 계산하여 출력한다. 
저장될때부터 모든 토마토가 익어있는 상태면 0을 출력 
		   모두 익지 못하는 상태일때는 1을 출력
*/

//토마토

static void inputripetomatoes(int x, int y, int z){
	vector<int> temp;
	temp.push_back(x);
	temp.push_back(y);
	temp.push_back(z);
	ripetomatoes.push(temp);
}

static void input(){
	cin >> M >> N >> H;
	
	for(int i=0; i < H; i++){
		for(int j=0; j < N; j++){
			for(int k=0; k < M; k++){
				cin >> boxes[i][j][k];
				visitboxes[i][j][k] = 0;
				if(boxes[i][j][k]==1)inputripetomatoes(i,j,k);
			}
		}
	}

}



static bool ripetomato(){
	
	for(int i=0; i < H; i++){
		for(int j=0; j < N; j++){
			for(int k=0; k < M; k++){
				answer = max(answer, boxes[i][j][k]);		
				if(boxes[i][j][k]==0){
					return false;
				}
			}
		}
	}
	answer--;
	return true;
	
}

static void bfs(){
	
	
	
	while(!ripetomatoes.empty()){
		
		
		vector<int> currentlocation = ripetomatoes.front();
		ripetomatoes.pop();
		
		int i = currentlocation[0];
		int j = currentlocation[1];
		int k = currentlocation[2];
		
		visitboxes[i][j][k]=true;
		
		if(i+1 < H && boxes[i+1][j][k]==0 && visitboxes[i+1][j][k] == 0){
			boxes[i+1][j][k]=boxes[i][j][k]+1;
			inputripetomatoes(i+1,j,k);
		}
		if(i-1 >= 0 && boxes[i-1][j][k]==0 && visitboxes[i-1][j][k] == 0){
			boxes[i-1][j][k]=boxes[i][j][k]+1;
			inputripetomatoes(i-1,j,k);
		}
		if(j+1 < N && boxes[i][j+1][k]==0 && visitboxes[i][j+1][k] == 0){
			boxes[i][j+1][k]=boxes[i][j][k]+1;
			inputripetomatoes(i,j+1,k);
		}
		if(j-1 >= 0 && boxes[i][j-1][k]==0 && visitboxes[i][j-1][k] == 0){
			boxes[i][j-1][k]=boxes[i][j][k]+1;
			inputripetomatoes(i,j-1,k);
		}
		if(k+1 < M && boxes[i][j][k+1]==0 && visitboxes[i][j][k+1] == 0){
			boxes[i][j][k+1]=boxes[i][j][k]+1;
			inputripetomatoes(i,j,k+1);
		}
		if(k-1 >= 0 && boxes[i][j][k-1]==0 && visitboxes[i][j][k-1] == 0){
			boxes[i][j][k-1]=boxes[i][j][k]+1;
			inputripetomatoes(i,j,k-1);
		}
	}
	
	
		
}
	





int main(){
	input();
	bfs();
	
	if(!ripetomato()){
		cout << -1;
	}
	else cout << answer;
}


//시간초과된 알고리즘.
/*static void input(){
	cin >> M >> N >> H;
	
	for(int i=0; i < H; i++){
		for(int j=0; j < N; j++){
			for(int k=0; k < M; k++){
				cin >> boxes[i][j][k];
				currentboxes[i][j][k]=boxes[i][j][k];
			}
		}
	}

}

// 하루가 지나서 익은 토마토주변에 있는 익지않는 토마토들이 익음
static void goesoneday(){
	
	vector<vector<int>> ripetomatoes;
	ripetomatoes.size();
	for(int i=0; i < H; i++){
		for(int j=0; j < N; j++){
			for(int k=0; k < M; k++){
				if(boxes[i][j][k]==1){
					vector<int> temp;
					temp.push_back(i);
					temp.push_back(j);
					temp.push_back(k);
					ripetomatoes.push_back(temp);
				}
			}
		}
	}
	
	for(int t =0; t < ripetomatoes.size(); t++){
		
		int i = ripetomatoes[t][0];
		int j = ripetomatoes[t][1];
		int k = ripetomatoes[t][2];
		
		if(i+1 < H && boxes[i+1][j][k]==0)boxes[i+1][j][k]=1;
		if(i-1 >= 0 && boxes[i-1][j][k]==0)boxes[i-1][j][k]=1;
		if(j+1 < N && boxes[i][j+1][k]==0)boxes[i][j+1][k]=1;
		if(j-1 >= 0 && boxes[i][j-1][k]==0)boxes[i][j-1][k]=1;
		if(k+1 < M && boxes[i][j][k+1]==0)boxes[i][j][k+1]=1;
		if(k-1 >= 0 && boxes[i][j][k-1]==0)boxes[i][j][k-1]=1;
	}
					
	
}

// 상자안의 토마토가 다 익었는지 판단. 다 익었으면 true, 다 안익었으면 false
static bool ripetomato(){
	
	for(int i=0; i < H; i++){
		for(int j=0; j < N; j++){
			for(int k=0; k < M; k++){
				if(boxes[i][j][k]==0){
					return false;
				}
			}
		}
	}
	
	return true;
	
}

// 상자안의 토마토들의 상황이 어제와 같은지 판단. 어제와 다르면 false, 같으면 true
static bool isSame(){
	
	for(int i=0; i < H; i++){
		for(int j=0; j < N; j++){
			for(int k=0; k < M; k++){
				if(boxes[i][j][k]!=currentboxes[i][j][k]){
					return false;
				}
			}
		}
	}
	
	return true;
}

static void print(){
	
	for(int i=0; i < H; i++){
		for(int j=0; j < N; j++){
			for(int k=0; k < M; k++){
				cout << boxes[i][j][k];
			}
			cout << '\n';
		}
		
	}
	cout << '\n';
	
}

static void fastalgorithm(){
	
}


int main(){
	input();
	while(1){
		
		goesoneday();

		if(isSame()){
			if(ripetomato()){
				cout << answer;
			}
			else cout << -1;
			
			break;
		}
		else{
			
			for(int i=0; i < H; i++){
				for(int j=0; j < N; j++){
					for(int k=0; k < M; k++){
						currentboxes[i][j][k]=boxes[i][j][k];
					}
				}
			}
			answer++;
		}

	}
	
	
}*/
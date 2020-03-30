#include <iostream>
#include <vector> 

using namespace std;

static int N, M, K;
vector<vector<int>> Matrix1(100, vector<int>(100, 0)); 
vector<vector<int>> Matrix2(100, vector<int>(100, 0));
vector<vector<int>> Matrix3(100, vector<int>(100, 0));

 void print(vector<vector<int>>& source){
		
		for(int i = 0; i < N; i++){
			
			for(int j = 0; j < K; j++){
				
				cout << source[i][j] << " ";
				
			}
			cout << endl;
		}
		
	}

void Multiply(vector<vector<int>>& Matrix1, vector<vector<int>>& Matrix2, vector<vector<int>>& Matrix3){
	
	for(int k = 0; k < K; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
			
			Matrix3[i][k] += Matrix1[i][j] * Matrix2[j][k]; 
			
			}
		}
	}
}

static void input(){
	
	cin >> N >> M; 
	
	for(int i = 0; i < N; i++){
		
		for(int j = 0; j < M; j++){
			
			cin >> Matrix1[i][j];
			
		}
		
	}
	
	cin >> M >> K; 
	
	for(int i = 0; i < M; i++){
		
		for(int j = 0; j < K; j++){
			
			cin >> Matrix2[i][j];
			
		}
		
	}
	
}


/*int main(){
	
	input();
	
	Multiply(Matrix1, Matrix2, Matrix3);
	
	print(Matrix3);
	
}
*/

/*#include <cstdio>
using namespace std;

int main(){

	int A[100][100], B[100][100], C[100][100]={0};
	int N, M, K;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%d", &A[i][j]);
	scanf("%d %d", &M, &K);
	for(int i=0; i<M; i++){
		for(int j=0; j<K; j++){
			scanf("%d", &B[i][j]);
			for(int k=0; k<N; k++)
				C[k][j] += A[k][i]*B[i][j];
		}
	}
	for(int i=0; i<N; i++)
		for(int j=0; j<K; j++)
			printf("%d%c", C[i][j], (j==K-1)?'\n':' ');

	return 0;
}*/
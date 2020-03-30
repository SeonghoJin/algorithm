#include <iostream>
#include <cmath>

using namespace std;
const int MAX = 20;
int sptle[200001][MAX];

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> sptle[i][0];
	}
	
	for(int i = 1; i < MAX; i++){
		for(int j = 1; j <= N; j++){
			sptle[j][i] = sptle[sptle[j][i-1]][i-1];
		}
	}
	
	int M;
	cin >> M;
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		int c = 0;
		for(int i = 0; i < MAX; i++){
			if(a & ( 1 << i)){b = sptle[b][i];}
		}
		cout << b << '\n';
	}
}
	

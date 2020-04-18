#include <iostream>
using namespace std;

int map[201][201];
int main(){
    
	for(int i = 0; i < 4; i++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		for(int j = b; j < d; j++)
			for(int k = a; k < c; k++){
				map[j][k] = 1;
			}
	}
	
	int ans = 0;
	
	for(int i = 0; i < 101; i++){
		for(int j = 0; j < 101; j++){
			ans += map[i][j];
		}
	}
	cout << ans;
}
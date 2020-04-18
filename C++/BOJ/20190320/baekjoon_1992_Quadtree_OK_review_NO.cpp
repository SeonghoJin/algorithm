#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

vector<vector<int>> Map(65, vector<int>(65, 0));  
int N;

static void input(){
	
	cin >> N;
	
	string s;
	
	for(int i = 0; i < N; i++){
		
		cin >> s; 
		
		for(int j = 0; j < N; j++){
			
			
			Map[i][j] = s.at(j)-48;
			
		}
	}
	
}

void doCompression(int FirstHeigth, int FirstWidth, int Length){
	
	int FirstValue = Map[FirstHeigth][FirstWidth];
	bool flag = false;
	
	for(int i = 0; i < Length; i++){
		
		for(int j = 0; j < Length; j++){
			
			if(FirstValue != Map[FirstHeigth+i][FirstWidth+j]){
				flag = true;
				break;
			}
			
		}
		
		if(flag){
			break;
		}
		
	}
	
	if(!flag){
		cout << FirstValue;
	}
	else{
		cout << "(";
		doCompression(FirstHeigth, FirstWidth, Length/2);
		doCompression(FirstHeigth, FirstWidth+Length/2, Length/2);
		doCompression(FirstHeigth+Length/2, FirstWidth, Length/2);
		doCompression(FirstHeigth+Length/2, FirstWidth+Length/2, Length/2);
		cout << ")";
	}
	
	
	
}

/* main(){
	
	input();
	
	doCompression(0,0,N);
	
}
*/

////////////////////


/*nclude <stdio.h>

int N;
char S[64][64 + 1];

void check(int y, int x, int s){
	int i, u;

	for (i = 0; i < s; i++){
		for (u = 0; u < s; u++){
			if (S[y][x] - S[y + i][x + u]) break;
		}
		if (u < s) break;
	}

	if (i == s){
		printf("%c", S[y][x]);
		return;
	}

	printf("(");
	check(y, x, s / 2);
	check(y, x + s / 2, s / 2);
	check(y + s / 2, x, s / 2);
	check(y + s / 2, x + s / 2, s / 2);
	printf(")");
}

int main(){
	int i;

	scanf( "%d", &N);
	for (i = 0; i < N; i++) scanf( "%s", S[i]);

	check(0, 0, N);

	return 0;
}
*/
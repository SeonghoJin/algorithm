#include <iostream>
#include <cmath>

using namespace std;
/*
int map[50][50];
int x,y;
	
int mapcheck(int i, int j){
	
	if(!(i >= 3 && i < x-4 && j >= 3 && j < y-4)){return 987654321;}
		//start_black
		int start = 0;
		int ret_b = 0;
		int ret_w = 0;
		for(int t = -3; t <= 4; t++){
			for(int k = -3; k <= 4; k++){
				if(start == map[i+t][j+k]){ret_w++;}
				else{ret_b++;}
				start = (start+1)%2;
			}
			start = (start+1)%2;
		}
		
	return min(ret_w,ret_b);
}

int main(){
	
	cin >> x >> y;
	
	int ret = 987654321;
	
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			char c;
			cin >> c;
			if(c =='B')map[i][j] = 0;
			else{map[i][j]=1;}
		}
	}
	
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			ret = min(ret, mapcheck(i,j));
		}
	}
	
	cout << ret;
	
}*/
/*
#include <iostream>

using namespace std;

int Map[128][128];
int blue = 0, white = 0;

bool check(int length, int x, int y){
	int start_color = Map[y][x];
	
	for(int i = y; i < y + length; i++){
		for(int j = x; j < x + length; j++){
			if(Map[i][j] != start_color)return false;
		}
	}
	return true;
}

void MakeQuadtree(int length, int x, int y){
	int start_color = Map[y][x];
	
	if(length == 1 || check(length,x,y)){
		if(start_color == 0)white++;
		else blue++;
		return ;
	}
	else{
		MakeQuadtree(length/2,x,y);
		MakeQuadtree(length/2,x+length/2,y);
		MakeQuadtree(length/2,x,y+length/2);
		MakeQuadtree(length/2,x+length/2,y+length/2);
	}
}



int main(){
	int N;
	cin >> N;
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> Map[i][j];
		}
	}
	MakeQuadtree(N,0,0);
	cout << white << '\n' << blue;
	
	
}*/
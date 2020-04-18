#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M, n;
int map[14][14] = {0,};
int sha[2][2][2] = {{{0,0},{0,1}},{{0,0},{1,0}}};
vector<vector<long long>> cache(14*14, vector<long long>(1 << 14, -1));

void printbit(int i){
	
	int bit = 0;
	int t = 0;
	for(int j = 0; i ; j++){
		if(i & 1){bit+=(pow(10,j));}
		i /=2;
	}
	
	cout << bit << '\n';
}

void print(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << map[i][j] << ' ';
		} 
		cout << '\n';
	}
}

bool change_block(int y, int x, int shape, int flag){ //flag = 0 지우기, flag = 1 생성
	
	if((y+sha[shape][0][0] < N && x+sha[shape][0][1] < M)  && (y+sha[shape][1][0] < N && x+sha[shape][1][1] < M)){
		if(flag == 1 && (map[y+sha[shape][0][0]][x+sha[shape][0][1]] == 1 || map[y+sha[shape][1][0]][x+sha[shape][1][1]] == 1
	)){return false;}
		
	map[y+sha[shape][0][0]][x+sha[shape][0][1]] = flag;
	map[y+sha[shape][1][0]][x+sha[shape][1][1]] = flag;
	return true;
	}
	else return false;
}

long long f(int k){
	
	if(n == k)return 1;
	
	int startx = -1;
	int starty = -1;
	
	for(int i = 0; i < N; i++){
		if(startx != -1)break;
		for(int j = 0; j < M; j++){
			if(map[i][j] == 0){startx = j; starty = i; break;}
		}
	}
	
	int bit = 0;
	int bi = 0;
	for(int i = startx; i < M; i++,bi++){
		if(map[starty][i] == 1){bit |= (1 << bi);}
	}
	if(starty+1 < N)
		for(int i = 0; bi < M; bi++,i++){
			if(map[starty+1][i] == 1){bit |= (1 << bi);}
	}
	
	
	int new_v = starty*M+startx;
	long long &ret = cache[new_v][bit];
	if(ret != -1)return ret;
	ret = 0;
	

	for(int i = 0; i < 2; i++){
		if(change_block(starty,startx,i,1)){
		ret+=(f(k+1)%9901);
		change_block(starty,startx,i,0);
		}
	}
	
	return ret%9901;
	
}



int main(){
	
	
	cin >> N >> M;
	
	n = N*M/2;
	
	if(N*M%2){
		cout << 0 << '\n';
	}
	else{
		cout << f(0) << '\n';
	}	
	
	
}
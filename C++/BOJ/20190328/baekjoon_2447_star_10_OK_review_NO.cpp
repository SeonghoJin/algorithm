#include <iostream>
#include <cmath>

using namespace std;

int N;

int arr[2187][2187];

static void input(){

	cin >> N ;
	
}

void makeTri(int x, int y, int length){
	
	if(length == 1){
		arr[x][y]=1;
	}
	else{
		length/=3;
		
		makeTri(x,y,length);
		makeTri(x+length,y,length);
		makeTri(x+2*length,y,length);
		makeTri(x,y+length,length);
		makeTri(x,y+2*length,length);
		makeTri(x+2*length,y+length,length);
		makeTri(x+length,y+2*length,length);
		makeTri(x+2*length,y+2*length,length);
		
	}
	
}

int main(void){

	input();
	
	makeTri(0, 0, N);
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(arr[i][j] == 1){
				cout << '*';
			}
			else cout << ' ';
		}
		cout << endl;
			
	}
	
}


/*
#include<cstdio>

const int BUF_SIZE = 1 << 20;
char buffer[BUF_SIZE];
char * idx = buffer;

void flush() {
	fwrite(buffer, sizeof(char), idx - buffer, stdout);
}
void printc(const char c) {
	if (idx == buffer + BUF_SIZE) {
		flush();
		idx = buffer;
	}
	*idx++ = c;
}

int N;
void star(int y, int n) {
	if (n == 1) {
		printc('*');
		return;
	}
	if (y < n / 3 * 2 && y >= n / 3) {
		star(y % (n / 3), n / 3);
		for (int i = 0; i < n / 3; ++i) printc(' ');
		star(y % (n / 3), n / 3);
	}
	else {
		for (int i = 0; i < 3; ++i) {
			star(y % (n / 3), n / 3);
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		star(i, N);
		printc('\n');
	}
	flush();
}*/
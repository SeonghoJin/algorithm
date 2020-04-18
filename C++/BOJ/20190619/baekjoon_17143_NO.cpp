/*
첫째 줄에 격자판의 크기 R, C와 상어의 수 M이 주어진다. (2 ≤ R, C ≤ 100, 0 ≤ M ≤ R×C)

둘째 줄부터 M개의 줄에 상어의 정보가 주어진다. 상어의 정보는 다섯 정수 r, c, s, d, z (1 ≤ r ≤ R, 1 ≤ c ≤ C, 0 ≤ s ≤ 1000, 1 ≤ d ≤ 4, 1 ≤ z ≤ 10000) 로 이루어져 있다. (r, c)는 상어의 위치, s는 속력, d는 이동 방향, z는 크기이다. d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.

두 상어가 같은 크기를 갖는 경우는 없고, 하나의 칸에 둘 이상의 상어가 있는 경우는 없다.
*/
/*
#include <iostream>
#include <vector>

using namespace std;
using point = pair<int, int>;

struct data{
	int r,c,s,d,z;
};

int R,C,M, player_r;

vector<vector<data>> map(101,vector<data>(101));

void move(data t){
	int d = t.d;
	int s = t.s;
	int r =t.r;
	int c =t.c;
	int ml = d <= 2 ? (s+R)%R : (s+c)%C;
	int md = d <= 2 ? (s+R)/R : (s+c)/C;
	int nextd = md & 1 ? d <= 2 ? d%2+1 : d%2+3 : d;
	int k = 1;
	if(md & 1)k=-1;
	switch(nextd){
			
		case 1:
			t.r-=k*ml;
			break;
		case 2:
			t.r+=k*ml;
			break;
		case 3:
			t.c+=k*ml;
			break;
		case 4:
			t.c-=k*ml;
			break;
	}
	
	cout << "r = " << t.r << "c =" << t.c  << "d =" << nextd<<endl;
}

int main(){
	int ret = 0;
	player_r = 0;
	
	cin >> R >> C >> M;
	/*
	for(int i = 0; i < M; i++){
		int r,c,s,d,z;
		cin >> r >> c >> s >> d >> z;
		data temp={r,c,s,d,z};
		map[r][c]=temp;
	}
	
	while(player_r <= C){
		
		for(int i = 1; i <= R; i++){
			data t = map[i][player_r];
			ret+=t.z;
			map[i][player_r] = {-1,-1,-1,-1,-1};
			break;
		}
		
		for(int i = 1; i <= R; i++){
			for(int j = 1; j <= C; j++){
				data t = map[i][j];
				
			}
		}
		
	}
	
	while(1){
		int a,b,c,d,e;
		cin >> a >> b >> c >> d >> e;
		data t = {a,b,c,d,e};
		move(t);
	}
	
}

*/


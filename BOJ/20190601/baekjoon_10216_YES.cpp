#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
struct enemylocal{
	int x;
	int y;
	int r;
	int visit;
};

vector<vector<vector<enemylocal>>> enemy(5001,vector<vector<enemylocal>>(5001,vector<enemylocal>()));  //enemy[y][x]는 x,y에 있는 적과 통신가능한 적들을 반환한다.
vector<enemylocal> allenemy; // 적들의 위치 정보를 순서대로 저장.

//적들의 위치 정보를 저장하기 위한 방법의 조건으로는  1.좌표를 이용해 다른 적군의 좌표를 알수 있어야한다.  동적배열? 
//										     2. 좌표를 이용해 다른 적군의 좌표를 추가할 수 있어야한다. 


static int T;

static bool cancomunicate(enemylocal& a1, enemylocal& a2){
	int dx = abs(a1.x-a2.x);
	int dy = abs(a1.y-a2.y);
	int dr = a1.r+a2.r;
	if(dx*dx + dy*dy <= dr*dr)return true;
	return false;
}

static void push(enemylocal& a1, enemylocal& a2){
	enemy[a1.y][a1.x].push_back(a2);
	enemy[a2.y][a2.x].push_back(a1);
}

static void reset(){
	
		for(int i = 0; i < allenemy.size(); i++){
			enemy[allenemy[i].y][allenemy[i].x].clear();
		}
	
		allenemy.clear();
}

static void dfs(enemylocal& start){

	int dx = start.x;
	int dy = start.y;
	int dr = start.r;
	
	enemy[dy][dx][0].visit=1;
	
	for(int i = 0; i < enemy[dy][dx].size(); i++){
		if(enemy[enemy[dy][dx][i].y][enemy[dy][dx][i].x][0].visit == 0)dfs(enemy[dy][dx][i]);
	}

}

static void algorithm(){
	cin >> T;
	
	for(int p = 0; p < T; p++){
		
		int N;
		cin >> N; //  적군 진영의 숫자 N (1 ≤ N ≤ 3,000), 적군 진영의 좌표 x, y (0 ≤ x, y ≤ 5,000), 그리고 해당 진영의 R (0 ≤ R ≤ 5,000)
		
		for(int j = 0; j < N; j++){
			enemylocal k;
			cin >> k.x >> k.y >> k.r;
			k.visit == 0;
			allenemy.push_back(k);
			enemy[k.y][k.x].push_back(k);
			for(int t = 0; t < allenemy.size()-1; t++){
				if(cancomunicate(allenemy[t],allenemy[allenemy.size()-1])){
					push(allenemy[t],allenemy[allenemy.size()-1]);
				}
			}
			
		}
		
		int ret=0;
		
		for(int i =0; i < allenemy.size(); i++){
			if(enemy[allenemy[i].y][allenemy[i].x][0].visit == 0)dfs(allenemy[i]),ret++;
		}
		
		
		cout << ret << endl;
		
		reset();
		
		
	}
}



int main(){
	
	algorithm();
	
}*/




struct enemylocal{
	int x;
	int y;
	int r;
	int visit=0;
};

vector<enemylocal> allenemy;

static bool cancomunicate(enemylocal& a1, enemylocal& a2){
	int dx = abs(a1.x-a2.x);
	int dy = abs(a1.y-a2.y);
	int dr = a1.r+a2.r;
	if(dx*dx + dy*dy <= dr*dr)return true;
	return false;
}

static void reset(){
	
		allenemy.clear();
}

static void dfs(enemylocal& start){
	int x=start.x, y=start.y, r=start.r;
	start.visit = 1;
	
	for(int i = 0; i < allenemy.size(); i++){
		enemylocal& temp = allenemy[i];
		if(temp.visit == 0 && cancomunicate(temp,start))dfs(temp);
	}
}

static void algorithm(){
	int T;
	cin >> T;
	
	for(int p = 0; p < T; p++){
		
		int N;
		cin >> N; //  적군 진영의 숫자 N (1 ≤ N ≤ 3,000), 적군 진영의 좌표 x, y (0 ≤ x, y ≤ 5,000), 그리고 해당 진영의 R (0 ≤ R ≤ 5,000)
		
		for(int j = 0; j < N; j++){
			enemylocal k;
			cin >> k.x >> k.y >> k.r;
			allenemy.push_back(k);
		}
		
		int ret = 0;
		
		for(int i =0; i < allenemy.size(); i++){
			if(allenemy[i].visit == 0)dfs(allenemy[i]),ret++;
		}
		
		
		cout << ret << endl;
		
		reset();
		
		
	}
}


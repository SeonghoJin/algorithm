/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int N;  // 5 <= N <= 25
static int map[25][25];
static int answer1;
static vector<int> answer2;
static int tempanswer;


static void input(){
	cin >> N;
	for(int i = 0; i < N; i++){
		string str;
		cin >> str;
		
		for(int j = 0; j < N; j++){
			map[i][j] = str.at(j)-48;
		}
	}
	
	
}

static void dfs(int startx, int starty){
	map[starty][startx]=0;
	tempanswer++;
	
	if(startx-1 >= 0 && map[starty][startx-1]==1)dfs(startx-1,starty);
	if(startx+1 < N && map[starty][startx+1]==1)dfs(startx+1,starty);
	if(starty-1 >= 0 && map[starty-1][startx]==1)dfs(startx,starty-1);
	if(starty+1 < N && map[starty+1][startx]==1)dfs(startx,starty+1);
	
}

int main(){
	input();
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(map[i][j]==1)answer1++,tempanswer=0,dfs(j,i),answer2.push_back(tempanswer);
		}
	}
	
	cout << answer1 << endl;
	
	sort(answer2.begin(),answer2.end());
	
	for(int i = 0; i < answer2.size(); i++){
		cout << answer2[i] << endl;
		
	}

}


#include<stdio.h>
#include<algorithm>

char map[25][25] = { 0, };
int t, n, k;

bool cmp(int a, int b){ return a > b; }
int dfs(int y, int x){
	if (y >= 0 && y < n&&x >= 0 && x < n&&map[y][x]=='1'){
		map[y][x] = '0';
		return 1+dfs(y - 1, x)+dfs(y + 1, x)+dfs(y, x - 1)+dfs(y, x + 1);
	}
	else return 0;
}

int main(){
	int cnt = 0;
	int arr[625] = { 0, };
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s", map[i]);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1') {
				arr[cnt++]=dfs(i, j);
			}
		}
	}
	printf("%d\n", cnt);
	std::sort(arr, arr + cnt,cmp);
	while (cnt--) printf("%d\n", arr[cnt]);
}*/

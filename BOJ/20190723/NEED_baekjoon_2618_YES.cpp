#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int N,W;

pair<int, int> event[1002];
int answer[1001];
vector<vector<int>> cache(1002,vector<int>(1002,987654321));

int cal(int i, int j){
	return abs(event[i].first-event[j].first)+abs(event[i].second-event[j].second);
}

int f(int n, int x, int y, int _x, int _y){
	if(W == _x || W == _y){
		cache[_x][_y] = 0;
		return 0;
	}
	
	int& ret = cache[_x][_y];
	if(ret != 987654321){return ret;}
	int a = f(n+1,_x,_y,n+1,_y)+cal(_x,n+1);
	int b = f(n+1,_x,_y,_x,n+1)+cal(_y,n+1);
	return ret = min(a,b);
}

void find(int n, int x, int y){
	if(n == W) return;
	int idx_y = y == 0 ? 1001 : y;  
	int a = cal(n+1,x);
	int b = cal(n+1,y == 0 ? 1001 : y); 
	int aa = cache[n+1][idx_y];
	int bb = cache[x][n+1];
	 
	if(cache[x][idx_y]-aa == a){
		cout << 1 << endl;
		find(n+1,n+1,idx_y);
	}
	else{
		cout << 2 << endl;
		find(n+1,x,n+1);
	}
	
}

int main(){
	cin >> N >> W;
	
	event[0] = make_pair(1,1);
	event[1001] = make_pair(N,N);
	
	for(int i = 1; i <= W; i++){
		int a,b;
		cin >> a >> b;
		event[i] = make_pair(a,b);
	}
	
	int a = f(1,0,1001,1,1001)+cal(1,0);
	int b = f(1,0,1001,0,1)+cal(1,1001);
	cache[0][1001] = min(a,b);
	cout << min(a,b) << endl;
	
	
	
	find(0,0,0);
	
}
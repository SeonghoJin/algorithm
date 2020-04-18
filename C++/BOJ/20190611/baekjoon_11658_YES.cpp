/*
#include <iostream>
using namespace std;

long long tArr[1025][1025]; 
long long Arr[1025][1025];
int N, M;

void update(int x, int y, long long diff){
	
	while(y <N){
		Arr[x][y]+=diff;
		y += (y & -y);
	}
	
}

long long sum(int x1, int y1, int x2, int y2){
	long long ret = 0;
	
	
	for(int i = x1; i <= x2; i++){
		int t = y2;
		
		while(t > 0){
			ret+=Arr[i][t];
			t -= (t & -t);
		}
		
		int k = y1-1;
		
		while(k > 0){
			ret-=Arr[i][k];
			k -= (k & -k);
		}
		
	}
	
	return ret;
	
}

int main(){
	cin.tie(NULL);
	ios_base :: sync_with_stdio(false);
	cin >> N >> M;
	
	for(int i = 1; i <= N; i ++){
		for(int j = 1; j <= N; j++){
			cin >> tArr[i][j];
			update(i,j,tArr[i][j]);
		}
	}
	
	while(M--){
		int w;
		cin >> w;
		if(w){
			int x1,y1,x2,y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << sum(x1,y1,x2,y2)<< '\n';
		}
		else{
			int x,y,v;
			cin >> x >> y >> v;
			update(x,y,v-tArr[x][y]);
			tArr[x][y]=v;
		}
	}
}
*/

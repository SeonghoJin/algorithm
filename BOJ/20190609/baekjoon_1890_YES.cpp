#include <iostream>
#include <vector>
using namespace std;
int Arr[100][100];
vector<vector<long long>> cache(100,vector<long long>(100,-1));
int N;
	

long long jump(int i = 0, int j = 0){
	
	long long& ret = cache[i][j];
	
	if(ret!=-1)return ret;
	if(!Arr[i][j])return (i == N-1 && j == N-1) ? 1 : 0;
	
	int num  = Arr[i][j];
	
	ret = 0;
	
	ret+=jump(i+num,j);
	ret+=jump(i,j+num);
	return ret;
	
}
/*
int main(){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> Arr[i][j];
		}
	}
	
	cout << jump();
	
}
*/

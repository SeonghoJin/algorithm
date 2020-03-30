/*
#include <iostream>

using namespace std;

int ret = 0;
int Arr[1001]={0,};
		
int visit(int root,int i){
	if(!Arr[i]){
		Arr[root] = 0;
		return 1;
	}
	Arr[root]=0;
	return visit(i,Arr[i]);
}

int main(){
	ios_base :: sync_with_stdio(false);
	int T,N;
	cin >> T;
	while(T--){
		cin >> N;
		int ret = 0;
		for(int i = 1; i <= N; i++){
			cin >> Arr[i];
		}
		
		for(int i = 1; i <= N; i++){
			if(Arr[i])ret+=visit(i,Arr[i]);
		}
		
		cout << ret << '\n';
	
	}
}
*/
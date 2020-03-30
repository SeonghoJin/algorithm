/*
#include <iostream>
#include <map>
using namespace std;
int T,N,M;

int main(){
	cin >> T;
	while(T--){
		cin >> N;
		
		int Arr[501];
		int TArr[501]={0,};
		for(int i = 1; i <= N; i++){
			int T;
			cin >> T;
			Arr[T]=i;
		}
		cin >> M;
		for(int i = 0; i < M; i++){
			int a, b;
			cin >> a >> b;
			if(Arr[a] > Arr[b]){
				TArr[a]--; TArr[b]++;
			}
			else{
				TArr[a]++; TArr[b]--;
			}
		}
		for(int i = 1; i <= N; i++){
			Arr[i]+=TArr[i];
		}
		

		bool flag = true;
		int order[501]={0,};
		for(int i = 1; i <= N; i++){
			if(order[Arr[i]]){cout <<"IMPOSSIBLE"<<endl;
						flag=false;
						break;
						}
			order[Arr[i]]=i;
			}
		
		if(!flag){
			continue;
		}
		for(int i = 1; i <= N; i++){
			cout << order[i] << " ";
		}
		cout << endl;
	}
}*/
/*
#include <iostream>

using namespace std;

int main(){
	
	int N, K;
	cin >> N >> K;
	
	int Arr[10];
	
	for(int i = 0; i < N; i++){
		cin >> Arr[i];
	}
	
	int ans = 0;
	for(int i = N-1; K != 0; i--){
		
		if(K >= Arr[i]){
			ans+=K/Arr[i];
			K=K%Arr[i];
		}
		
	}
	
	cout << ans;
}*/
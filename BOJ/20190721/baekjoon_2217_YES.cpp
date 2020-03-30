/*
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int Arr[10000];
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> Arr[i];
		Arr[i] = -Arr[i];
	}
	
	sort(Arr,Arr+N);
	
	int ma = 0;

	for(int i = 0 ; i < N; i++){
		ma = max(ma, (i+1)*-Arr[i]);
	}
	cout << ma;
}*/
/*
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int N;
	cin >> N;
	int Arr[1001];
	for(int i = 0; i < N; i++){
		cin >> Arr[i];
	}
	sort(Arr,Arr+N);
	
	int sum = 0;
	
	for(int i = 0; i < N-1; i++){
		sum += Arr[i];
		Arr[i+1]+=Arr[i];
	}
	
	cout << sum+Arr[N-1];
}*/
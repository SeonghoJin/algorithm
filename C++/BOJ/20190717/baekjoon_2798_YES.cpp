/*
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int TEMP = -1;
int N,M;

int main(){
	
	cin >> N >> M;
	vector<int> Arr(N);
	
	for(int i = 0; i < N; i++){
		cin >> Arr[i];
	}
	
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			for(int k = j+1; k < N; k++){
				
				TEMP = Arr[i]+Arr[j]+Arr[k] <= M ? max(TEMP,Arr[i]+Arr[j]+Arr[k]) : TEMP;
				
			}
		}
	}
	cout << TEMP;
	
}*/
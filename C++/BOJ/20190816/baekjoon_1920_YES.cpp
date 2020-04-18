/*
#include <iostream>
#include <algorithm>
using namespace std;

bool find(int* array, int N, int value){
	
	int start = 0, end = N-1;
	int mid = (start+end) >> 1;
	while(end - start >= 0){
		if(array[mid] == value)return true;
		if(array[mid] < value)start = mid+1;
		else{end = mid-1;}
		mid = (start+end) >> 1;
	}
	
	return false;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int Array[100001];
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> Array[i];
	}
	
	sort(Array,Array+N);
	
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		if(find(Array,N,v))cout << "1" << '\n';
		else{ cout << "0" << '\n';}
	}
	
	
	
}*/
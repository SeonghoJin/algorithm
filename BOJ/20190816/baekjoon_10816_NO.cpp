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

int find1(int* array, int N, int value){
	
	if(!find(array,N,value))return 0;
	
	int start = 0, end = N-1;
	int mid = (start+end) >> 1;
	
	while(end - start >= 0){
		if(mid == 0 || (array[mid] == value && array[mid-1] != value))break;
		if((array[mid] == value && array[mid-1] == value) || array[mid] > value)end = mid-1;
		else{start = mid+1;}
		mid = (start+end) >> 1;
	}
	
	start = 0;
	end = N-1;
	int t_mid = (start+end) >> 1;
	
	while(end - start >= 0){
		if(t_mid == N-1 || (array[t_mid] == value && array[t_mid+1] != value))break;
		if( ( array[t_mid] == value && array[t_mid+1] == value) || array[t_mid] < value)start = t_mid+1;
		else{end = t_mid-1;}
		t_mid = (start+end) >> 1;
	}
	
	return t_mid - mid + 1;
}





int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int Array[400001];
	
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
		cout << find1(Array,N,v) << " ";
	}
	
	
	
}
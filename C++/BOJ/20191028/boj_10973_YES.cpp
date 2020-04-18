#include <iostream>
#include <algorithm>

using namespace std;
int N;
int Arr[10001];

bool cmp(int i, int j){
	return i > j ? true : false;
}

bool func(){
	
	int i = 0;
	for(i = N; i > 0; i--){
		if(i == 1)return false;
		if(Arr[i-1] > Arr[i]){break;}
	}
	
	int ma = 0;
	int idx = 0;
	int j = 0;
	for(j = i; j <= N; j++){
		if(Arr[j] < Arr[i-1] && ma < Arr[j]){
			ma = Arr[j];
			idx = j;
		}
	}

	swap(Arr[i-1],Arr[idx]);
	sort(Arr+i,Arr+N+1,cmp);
	
	return true;
}

int main(){
	
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		cin >> Arr[i];
	}
	
	if(func()){
		for(int i = 1; i <= N; i++)cout << Arr[i] << " ";
	}
	else{
		cout << -1;
	}
	
}

/*
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> cache(1000001,1);



int main(){
	cin >> N;
	
	cache[1] = 1;
	cache[2] = 2;
	for(int i = 3; i <= N; i++){
		cache[i] = (cache[i-1]+cache[i-2])%15746;
	}
	
	cout << cache[N]%15746;
	
}*/
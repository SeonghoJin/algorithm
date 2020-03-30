#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	long long N,K;
	cin >> N >> K;
	
	long long mi = 1;
	long long ma = N*N;
	long long mid = (mi+ma)/2;
	long long result;
	while(mi < ma){
		long long sum = 0;
		for(long long j = 1; j <= N; j++)sum+=min(N,(mid)/j);
		if(sum >= K)ma = mid;
		else {mi = mid+1;}
		mid = (mi+ma)/2;
	}
	
	cout << mid << endl;
	
}

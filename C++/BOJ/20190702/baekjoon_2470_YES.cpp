#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

long long N;

bool cmp(long long i, long long j){
	return abs(i) < abs(j);
}

int main(){
	cin >> N;
	vector<long long> Arr(N);
	
	for(long long i = 0; i < N; i++){
		cin >> Arr[i];
	}
	
	sort(Arr.begin(),Arr.end());
	
	long long a,b,c;
	long long ret = 3000000001;
	
	for(int i = 0; i < N-2; i++){
		int start = i+1, end = N-1;
		
		while(start<end){
			long long k = Arr[i]+Arr[start]+Arr[end];
			if(abs(k) < ret){ret = abs(k); a = Arr[i]; b = Arr[start]; c=Arr[end];}
			if(k < 0)start++;
			else{end--;}
		}
		
	}
	
	cout << a << " " << b << " " << c;
}
	

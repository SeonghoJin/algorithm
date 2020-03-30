#include <iostream>
#include <cmath>
using namespace std;

long long K, N;
long double arr[10000];

bool cut_satisfy(long double length){
	
	long long count = 0;
	
	for(long long i = 0; i < K; i++){
		count += arr[i]/length;
	}
	
	if(count < N)return false;
	return true;
}


int main(){
	cin >> K >> N;
	long double maxlength = 0;  
	
	for(long long i = 0; i < K; i++){
		cin >> arr[i];
		maxlength = max(maxlength,arr[i]); 
	}
	
	
	long double minlength = 0;
	long double midlength = (minlength+maxlength)/2;
	for(long long i = 0; i < 1000; i++){
		if(cut_satisfy(midlength)){
			minlength = midlength;
		}
		else{
			maxlength = midlength;
		}
		midlength = (minlength+maxlength)/2;
	}
	
	
	cout << (long long)midlength << endl;
}
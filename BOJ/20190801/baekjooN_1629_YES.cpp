#include <iostream>

using namespace std;

int main(){
	long long A, B, C;
	cin >> A >> B >> C;
	
	long long ans = 1;
	
	while(B){
		if(B&1)ans*=(A%C);
		A = ((A%C)*(A%C))%C;
		ans=ans%C;
		B/=2;
	}
	cout << ans%C;
	
	
}

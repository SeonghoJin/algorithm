
#include <iostream>
using namespace std;
using LL = long long int;
const LL p =  1'000'000'007;




LL factorial(LL N){
	
	LL ret = 1;
	for(LL i = 2; i <= N; i++){
		ret*=i;
		ret%=p;
	}
	return ret;
	
}

int main(){
	int N,K;
	cin >> N >> K;
	LL a = factorial(N);
	LL b = (factorial(N-K)*factorial(K))%p;
	LL ans = 1;
	
	LL k = p-2;
	
	while(k){
		if(k&1)ans=(ans*b)%p;
		b = (b*b)%p;
		k/=2;
	}
	
	cout << (a*ans)%p;
	
}
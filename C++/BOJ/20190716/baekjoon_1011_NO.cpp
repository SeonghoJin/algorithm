#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int T;
	
	cin >> T;
	
	while(T--){
		int a,b;
		cin >> a >> b;
		int length = b-a;
		double t = ceil(sqrt(length));
		long long p = t*(t-1);
		long long q = 2*t-1;
		long long ans = length > p ? q : q-1;
		cout << ans << '\n';
	}
	
	
}
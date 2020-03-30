#include <iostream>
#include <vector>

using namespace std;
using ull = unsigned long long;
 
vector<ull> alist;
 
// calculate x^y % m
ull powmod(ull x, ull y, ull m) {
    x %= m;
    ull r = 1ULL;
    while (y > 0) {
        if (y % 2 == 1)
            r = (r * x) % m;
        x = (x * x) % m;
        y /= 2;
    }
    return r;
}
 
// true for probable prime, false for composite
inline bool miller_rabin(ull n, ull a) {
    ull d = n - 1;
    while (d % 2 == 0) {
        if (powmod(a, d, n) == n-1)
            return true;
        d /= 2;
    }
    ull tmp = powmod(a, d, n);
    return tmp == n-1 || tmp == 1;
}
 
bool is_prime(ull n) {
    if (n <= 1)
        return false;
   
    for (ull a : alist)
        if (!miller_rabin(n, a))
            return false;
    return true;
}
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	for(int i = 2; i < 101; i++)alist.push_back(i);
	int T;
	int ans = 0;
	cin >> T;
	while(T--){
		unsigned long long t;
		cin >> t;
		if(is_prime(1LL*2*t+1))ans++;
	}
	
	cout << ans;
}
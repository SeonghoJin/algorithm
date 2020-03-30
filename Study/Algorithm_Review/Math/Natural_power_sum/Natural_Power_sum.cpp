#include <iostream>

using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	cout << n*(n+1)/2 << '\n'; // sigma n
	cout << n*(n+1)*(2*n+1)/6 << '\n'; //sigma n^2
	cout << n*(n+1)/2  * n*(n+1)/2<< '\n'; //sigma n^3
	
}


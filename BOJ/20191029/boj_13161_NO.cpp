#include <iostream>

using namespace std;

int t[4] = {25,10,5,1};

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		
		for(int i = 0; i < 4; i++){
			cout << n/t[i] << " ";
			n%=t[i];
		}
		cout << '\n';
	}
}

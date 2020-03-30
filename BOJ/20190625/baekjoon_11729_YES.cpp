#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n,int a, int b){
	if(n==1){
		cout << a << " " << b << '\n';
		return;
	}
	if(a==1 && b == 3){
		hanoi(n-1,1,2);
		cout << 1 << " " << 3 << '\n';
		hanoi(n-1,2,3);
		return;
	}
	if(a==2 && b == 3){
		hanoi(n-1,2,1);
		cout << 2 << " " << 3 << '\n';
		hanoi(n-1,1,3);
		return;
	}
	if(a==3 && b == 2){
		hanoi(n-1,3,1);
		cout << 3 << " " << 2 << '\n';
		hanoi(n-1,1,2);
		return;
	}
	if(a==3 && b == 1){
		hanoi(n-1,3,2);
		cout << 3 << " " << 1 << '\n';
		hanoi(n-1,2,1);
		return;
	}
	if(a==2 && b == 1){
		hanoi(n-1,2,3);
		cout << 2 << " " << 1 << '\n';
		hanoi(n-1,3,1);
		return;
	}
	if(a==1 && b == 2){
		hanoi(n-1,1,3);
		cout << 1 << " " << 2 << '\n';
		hanoi(n-1,3,2);
		return;
	}
	
}


int main(){
	int n;
	cin >> n;
	ios_base :: sync_with_stdio(0);
	cout << (int)pow(2,n)-1 << '\n';
	hanoi(n,1,3);
}
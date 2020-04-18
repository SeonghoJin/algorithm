#include <iostream>
#include <cmath>

using namespace std;

int Min;
int Max;


void input(){
	
	cin >> Min;
	cin >> Max;
	
}


int a(){
	
	double a1 = ceil(sqrt(Min));
	double b1 = sqrt(Max);
	
	
	int sum = 0;
	
	for(int i = a1; i <= b1; i++){
		sum+= pow(i,2);
	}
	
	if(sum){
		cout << sum << endl;
		cout << pow(a1,2) << endl;
	
		
	}else{
		cout << -1;
	}
	
	
}



int main(){
	
	input();
	
	a();
}
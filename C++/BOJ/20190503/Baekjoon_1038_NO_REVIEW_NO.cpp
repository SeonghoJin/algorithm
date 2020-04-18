#include <iostream>

using namespace std;

int N;
void input(){
	cin >> N;
}

bool isDownNumber(long long A){
	
	bool ret = true;
	
	while((A/10)>=1){
		
		long long CurrentNumber = A%10;
		long long NextNumber = (A/10)%10;
	
		if(CurrentNumber>=NextNumber){
			ret = false;
			break;
		}
		A/=10;
	}
	return ret;

}


int main(){
	
	int num = 0;
	long long i = 0;
	bool flag = false;
	input();

	
	while(N>=num){
		if(isDownNumber(i++)){
			num++;
		cout << i-1 << " num=" << num-1 << endl;	
		}
		
		
	}
	
	
	cout << i-1 << " num=" << num-1 << endl;	
		
	
}
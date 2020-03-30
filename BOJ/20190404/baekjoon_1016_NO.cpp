#include <iostream>
#include <cmath>

using namespace std;
long long MIN, MAX;

int Arr[1000001];  
int count=0;
void input(){
	
	cin >> MIN >> MAX;
	
}


/*int main(){
	
	input();
	int N = MAX - MIN + 1; 
	
	int maxsqrt = sqrt(MAX);
	
		
		for(long long j = MIN; j <= MAX; j++){
			
			
			if(Arr[j-MIN]==0){
			for(int i = 2; i <=maxsqrt; i++){
				
				long long divisor = i*i;
				if(j%divisor == 0){
					
					long long k = j;
					
					while(k<=MAX){
						
						Arr[k-MIN]=1;
						k+=divisor;
						count ++;
					}
					
					
					}
	
				}
			}
		
		}	
	
	
	
	cout << N-count;
	
	

}
*/	
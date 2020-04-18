/*#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void EratosthenesFilter(vector<bool>& Prime){
	Prime[1]=false;
	
	if(Prime.size() == 2){return;}
	if(Prime.size() == 3){Prime[2]=true; return;}
	
	int T = sqrt(Prime.size());
	
	for(int i = 2; i < T; i++){
		if(!Prime[i])continue;
		
		for(int j = i*i; j < Prime.size(); j+=i){
			Prime[j]=false;
		}
		
	}

}




int main(){
	int N;
	cin >> N;
	
	vector<bool> Prime(N+1,1);
	EratosthenesFilter(Prime);
	
	for(int i = 1; i < Prime.size(); i++){
		if(Prime[i])cout <<i<< endl;
	}
	
}*/
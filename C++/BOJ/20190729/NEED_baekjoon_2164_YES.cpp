#include <iostream>
#include <list>
#include <queue>
using namespace std;

int main(){
	
	int N;
	cin >> N;
	vector<int> q;
	
	for(int i = 1; i <= N/2; i++){
		q.push_back(i*2);
	}
	int start = N;
	
	while(q.size()!=1){
		vector<int> temp;
		if(start & 1){
			start = q.size();
			for(int i = 1; i <= q.size(); i++){
				if(i & 1)temp.push_back(q[i-1]);			
			}
		}
		else{
			start = q.size();
			for(int i = 1; i <= q.size(); i++){
				if(i % 2 == 0)temp.push_back(q[i-1]);			
			}	
		}
		q = temp;
		
	}
	cout << q[0];
}
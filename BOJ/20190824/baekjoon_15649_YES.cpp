/*
#include <iostream>
#include <vector>
using namespace std;



int main(){
	int N;
	cin >> N;
	vector<int> t;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		t.push_back(a);
	}
	
	int sum = 0;
	int p = 1;
	for(int i = 0; i <= N; i++){
		if(t[i] == 0)p = 1;
		else if(i > 0 && t[i-1]){sum+=++p;}
		else{sum+=p;}
		
	}
	cout << sum << endl;
}
*/
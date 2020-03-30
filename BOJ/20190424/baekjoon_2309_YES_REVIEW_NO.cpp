#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> littlemans(9);
vector<int> ret;
bool flag = false;

void Find_true_littleMan(vector<int>& littlemans, int N, int Sum){
	
	if(flag) return;
	if(Sum == 100 && ret.size() == 7){
		
		sort(ret.begin(), ret.end());
		
		for(auto it = ret.begin(); it != ret.end(); it++){
			cout << *it << endl;
		}
		
		flag = true;
		return;
	}
	
	if(N == 9 || Sum > 100){
		return;
	}
	
	ret.push_back(littlemans[N]);
	Find_true_littleMan(littlemans, N+1, Sum+littlemans[N]);
	ret.pop_back();
	
	Find_true_littleMan(littlemans, N+1, Sum);
} 

/*int main(){
	
	for(int i = 0; i < 9; i++){
		
		cin >> littlemans[i];
		
	}

	Find_true_littleMan(littlemans, 0, 0);
	
	
	
	
}*/
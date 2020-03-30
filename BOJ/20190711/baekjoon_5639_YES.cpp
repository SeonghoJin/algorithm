/*
#include <iostream>
#include <vector>
using namespace std;

vector<int> tree;
	
void print(int start, int end){
	if(start == end){cout << tree[start] << endl; return;}
	
	int bound_index = -1;

	for(int i = start + 1; bound_index <= end; i++){
		if(tree[start] < tree[i]){ bound_index = i; break;}
	}
	
	if(bound_index == -1 || start +1 == bound_index){
		print(start+1,end);
	}
	else{
		print(start+1, bound_index-1);
		print(bound_index, end);
	}
	cout << tree[start] << endl;
	
}

int main(){
	int t;
	
	while(cin >> t){
		tree.push_back(t);
	}
	
	print(0,tree.size()-1);
	
	
}*/
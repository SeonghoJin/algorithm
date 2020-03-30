#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, long long> Map;

long long C = 0;
void push(int val){
	
	map<int, long long> :: iterator leftNode, rightNode;
	rightNode = Map.upper_bound(val);
	leftNode = --Map.upper_bound(val);
	long long NextDeep = (max(leftNode->second,rightNode->second))+1;
	C+=NextDeep;
	cout << C << "\n";
	Map.push(make_pair(val,NextDeep));
}	




int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int N;
	cin >> N;
	
	Map.push(make_pair(0,-1));
	Map.push(make_pair(N+1,-1));
	
	while(N--){
		int k;
		cin >> k;
		push(k);
	}
	
}
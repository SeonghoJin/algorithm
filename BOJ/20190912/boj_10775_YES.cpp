/*
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int parent[100001] = {0,};
int coun = 0;
int isParent(int i){return i == parent[i] ? i : parent[i] = isParent(parent[i]);}

bool isUnion(int i, int j){
	
	return isParent(i) == isParent(j);
	
}
void Union(int i, int j){
	
	if(!isUnion(i,j))
	parent[isParent(i)] = isParent(j);
	
}
	
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int G,P;
	cin >> G >> P;
	
	for(int i = 0; i <= G; i++)parent[i] = i;
	
	while(P--){
		int num;
		cin >> num;
		if(!isParent(num)){break;}
			coun++;
		Union(num,isParent(num)-1);
	}
	
	while(P > 0){int t; cin >> t; P--;}
	cout << coun;
	
}*/
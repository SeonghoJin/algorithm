/*
#include <map>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int parent[10001] = {0,};
int networkmember[10001];
int coun = 0;
map<string, int> m;

int isParent(int i){return i == parent[i] ? i : parent[i] = isParent(parent[i]);}

void Union(int i, int j){
	
	networkmember[parent[isParent(i)]] = networkmember[isParent(j)]+= networkmember[parent[isParent(i)]];
	parent[isParent(i)] = isParent(j);
	
}

bool isUnion(int i, int j){
	
	return isParent(i) == isParent(j);
	
}


		
int mapping(string& s){
	auto it = m.find(s);
	if(it != m.end())return it->second;
	else{
		m.push({s,coun++});
		return coun-1;
	}
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--){
		
		for(int i = 0; i < 10001; i++){parent[i] = i; networkmember[i] = 1;}
		int N;
		coun = 0;
		m.clear();
		cin >> N;
		
		while(N--){
			string s1, s2;
			cin >> s1 >> s2;
			
			int a = mapping(s1),b = mapping(s2);
			if(!isUnion(a,b))Union(a,b);
			cout << networkmember[isParent(a)] << '\n';
		}
		
		
	}
	
	
	
}*/
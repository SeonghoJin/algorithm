/*
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using iii = pair<int,pair<int,int>>;
using viii = vector<iii>;

iii make_three(int i, int j, int k){
	return make_pair(i,make_pair(j,k));
}

viii edge;

vector<int> Parent(10001);

int parent(int i){
	return Parent[i] == i ? i : Parent[i] = parent(Parent[i]);
}

void Union(int i, int j){
	Parent[parent(i)]=j;
}

bool isSameSet(int i, int j){
	return parent(i) == parent(j);
}

int main(){
	int V, E;
	int sum = 0;
	cin >> V >> E;
	for(int i = 0; i < E; i++){
		int a,b,c;
		cin >> a >> b >> c;
		edge.push_back(make_three(c,a,b));
	}
	
	for(int i = 1; i <= V; i++){
		Parent[i] = i;
	}
	
	sort(edge.begin(),edge.end());
	
	int i = 0;
	
	for(int j = 0; j < E; j++){
			
		if(!isSameSet(edge[j].second.first,edge[j].second.second)){
			sum+=edge[j].first;
			i++;
			Union(edge[j].second.first,edge[j].second.second);
		}
		if(i == V-1)break;	
	}
	
	cout << sum;
	
}*/
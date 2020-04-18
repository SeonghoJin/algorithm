/*
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

int parent[100001];
int find(int i){return i == parent[i] ? i : parent[i] = find(parent[i]);}
bool isUnion(int i, int j){return find(i) == find(j);}
void Union(int i, int j){
	parent[find(i)] = find(j);
}


int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int N;
	cin >> N;
	
	vector<pair<int,int>> vx;
	vector<pair<int,int>> vy;
	vector<pair<int,int>> vz;
	
	priority_queue<pair<int, pair<int,int>>> pq;
	ll cost = 0;
	for(int i = 0; i < N; i++)parent[i] = i;
	for(int i = 0; i < N; i++){
		int a,b,c;
		cin >> a >> b >> c;
		vx.push_back({a,i});	
		vy.push_back({b,i});	
		vz.push_back({c,i});	
	}
	
	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());
	sort(vz.begin(),vz.end());
	
	for(int i = 1; i < N; i++){
		pq.push({-abs(vx[i].first-vx[i-1].first),{vx[i].second,vx[i-1].second}});
		pq.push({-abs(vy[i].first-vy[i-1].first),{vy[i].second,vy[i-1].second}});
		pq.push({-abs(vz[i].first-vz[i-1].first),{vz[i].second,vz[i-1].second}});
	}
	
	int c = 0 ;
	while(!pq.empty() && c != N-1){
		pair<int, pair<int, int>> temp = pq.top(); pq.pop();
		int num1 = temp.second.first, num2 = temp.second.second;
		int co = -temp.first;
		
		if(isUnion(num1, num2))continue;
		c++;
		Union(num1,num2);
		cost+=co; 
	}
	
	cout << cost << '\n';
	
}*/
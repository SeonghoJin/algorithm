/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;


int c = 0;
int parent[100];

int find(int i){return i == parent[i] ? i : find(parent[i]);}
bool isUnion(int i, int j){return find(i) == find(j);}
void Union(int i, int j){parent[find(i)] = find(j);}

priority_queue<pair<double,pair<int,int>>> pq;
vector<pair<double, double>> v;
int main(){
	
	int N;
	cin >> N;
	for(int i = 0 ; i < N; i++)parent[i] = i;
	for(int i = 0; i < N; i++){
		double x,y;
		cin >> x >> y;
		v.push_back({x,y});
		for(int j = 0; j < i; j++){
			double length = sqrt((x-v[j].first)*(x-v[j].first)+(y-v[j].second)*(y-v[j].second));
			pq.push({-length,{i,j}});
		}
			
	}
	cout << fixed;
	cout.precision(2);
	double answer = 0;
	while(c != N-1){
		pair<double,pair<int, int>> temp = pq.top();
		pq.pop();
		int num1 = temp.second.first;
		int num2 = temp.second.second;
		double cost = -temp.first;
		if(isUnion(num1,num2))continue;
		c++;
		answer += cost;
		Union(num1,num2);
	}
	
	cout << answer;
}
*/

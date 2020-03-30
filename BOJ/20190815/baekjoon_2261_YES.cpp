#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
using pii = pair<int, int>;

bool compare1(pii x, pii y){
	return x.first < y.first;
}

bool compare2(pii x, pii y){
	return x.second < y.second;
}

int dist(pii x, pii y){
	return (x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second);
}

int closet_pair(vector<pii> :: iterator points, int N){
	if(N == 2)return dist(points[0],points[1]);
	if(N == 3)return min({dist(points[0],points[1]),dist(points[1],points[2]),dist(points[2],points[0])});
	
	int line = (points[N/2 - 1].first + points[N/2].first) / 2;
	int d = min(closet_pair(points,N/2),closet_pair(points+N/2,N-N/2));
	vector<pii> mid;
	mid.reserve(N);
	
	for(int i = 0; i < N; i++){
		int t = line - points[i].first;
		if(t*t < d){
			mid.push_back(points[i]);
		}
	}
	
	sort(mid.begin(),mid.end(),compare2);
		
	
	int md_size = mid.size();
	
	for(int i = 0; i < md_size - 1; i++){
		for(int j = i+1; j < md_size && (mid[j].second - mid[i].second)*(mid[j].second - mid[i].second) < d; j++){
			d = min(d,dist(mid[i],mid[j]));
		}
	}
	
	
	return d;
}

int main(){
	int n;
	cin >> n;
	vector<pii> points(n);
	
	for(int i = 0; i < n; i++){
		cin >> points[i].first >> points[i].second; 
	}
	
	sort(points.begin(),points.end(),compare1);
	cout << closet_pair(points.begin(), n);
}

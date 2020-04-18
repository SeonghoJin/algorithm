#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

using ppiis =pair<pair<int,int>,string>; 

vector<ppiis> vii;

bool cmp(ppiis i, ppiis j){
	
	return i.first.first < j.first.first ? true : i.first.second < j.first.second;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int N;
	cin >> N;
	vii.resize(N);
	
	for(int i = 0; i < N; i++){
		int x;
		string y;
		cin >> x >> y;
		vii[i]=make_pair(make_pair(x,i),y);
	}
	
	sort(vii.begin(),vii.end());
	
	for(int i = 0; i < vii.size(); i++){
		cout << vii[i].first.first << " " << vii[i].second << "\n";
	}
	
}
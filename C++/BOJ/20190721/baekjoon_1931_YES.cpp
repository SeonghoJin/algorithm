#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vii = vector<pair<int,int>>;
/*
첫째 줄에 회의의 수 N(1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N+1 줄까지 각 회의의 정보가 주어지는데 이것은 공백을 사이에 두고 회의의 시작시간과 끝나는 시간이 주어진다. 시작 시간과 끝나는 시간은 231-1보다 작거나 같은 자연수 또는 0이다.
*/
/*
int main(){
	int N;
	vii v;
	cin >> N;
	for(int i = 0; i < N; i++){
		int a,b;
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}
	
	sort(v.begin(),v.end());
	
	vector<int> answer;
	answer.push_back(0);
	
	for(int i = 0; i < N; i++){
		int idx = answer.size()-1;
		if(answer[idx] > v[i].second){answer.pop_back(); answer.push_back(v[i].second);}
		else if(answer[idx] <= v[i].first){answer.push_back(v[i].second); }
	}
	
	cout << answer.size()-1;
}*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	
	vector<int> t,s;
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		t.push_back(a);
	}
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		s.push_back(a);
	
	}
	sort(t.begin(),t.end());
	sort(s.begin(),s.end(),greater<int>());
	
	int ret = 0;
	for(int i = 0; i < t.size(); i++){
		ret += t[i]*s[i];
	}
	cout << ret;
	
	
	
}
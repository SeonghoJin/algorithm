/*#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	map<string, int> m;
	int N, M;
	cin >> N >> M;
	vector<string> v;
	for(int i = 0; i < N; i++){
		string str;
		cin >> str;
		m[str] = 1;
	}
	
	for(int j = 0; j < M; j++){
		string str;
		cin >> str;
		if(m[str] == 1)v.push_back(str);
	}
	cout << v.size() << '\n';
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++)cout << v[i] << '\n';
	
}*/
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
 
	int T;
	cin >> T;
	
	while(T--){
		int N;
		cin >> N;
 
		vector<int> v1(N);
		vector<int> v2(N);
 
		for(int i = 0; i < N; i++){
			cin >> v1[i];
		}
		for(int j = 0; j < N; j++){
			cin >> v2[j];
		}
 
		bool plus = false;
		bool minus = false;
		bool flag = true;
		for(int i = 0; i < N; i++){
			
			if(v1[i] < v2[i] && plus == false){flag = false;cout << "NO"<<'\n'; break;}
			if(v1[i] > v2[i] && minus == false){flag = false;cout << "NO"<<'\n'; break;}
			if(v1[i] == 1)plus = true;
			if(v1[i] == -1)minus = true;
 
		}
		if(flag){
			cout << "YES"<<'\n';
		}
	}
 
}

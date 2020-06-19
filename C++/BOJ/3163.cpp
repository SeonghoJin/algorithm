#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int T;
	cin >> T;
	while(T--){
		vector<int> minus;
		vector<int> plus;
		vector<pair<int,int>> t;
		list<int> li;

		int N, L, k;
		cin >> N >> L >> k;
		
		for(int i = 0; i < N; i++){
			int a, b;
			cin >> a >> b;
			li.push_back(b);
			if(b > 0)t.push_back({L-a,1});
			else{t.push_back({a,-1});}
		}
		sort(t.begin(), t.end());
		vector<pair<int,int>> answer;
		for(int i = 0; i < N; i++){
			if(t[i].second == -1){
			answer.push_back({t[i].first,li.front()});
			li.pop_front();
			}
			else{
			answer.push_back({t[i].first,li.back()});
			li.pop_back();	
			}
		}
		sort(answer.begin(), answer.end());
		
		cout << answer[k-1].second << '\n';
	}
}
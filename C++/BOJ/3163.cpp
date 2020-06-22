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
		list<int> li;
		int N, L, k;
		cin >> N >> L >> k;
		for(int i = 0; i < N; i++){
			int a, b;
			cin >> a >> b;
			li.push_back(b);
			if(b > 0)plus.push_back(L-a);
			else if(b < 0)minus.push_back(a);
		}
		sort(plus.begin(), plus.end());
		/*
		for(int i = 0; i < plus.size(); i++){
			cout << plus[i] << " ";
		}
		for(int i = 0; i < minus.size(); i++){
			cout << minus[i] << " ";
		}*/
		int pcur = 0;
		int mcur = 0;
		int answer = 0;

		while(k-- && (pcur < plus.size() || mcur < minus.size())){
			if((mcur == minus.size()) || pcur < plus.size()) && plus[pcur] < minus[mcur])){
				answer = li.back();
				li.pop_back();
				pcur++;
			}
			else if((pcur == plus.size()) || plus[pcur] > minus[mcur]){
				answer = li.front();
				li.pop_front();
				mcur++;
			}
			else{
				if(li.back() < li.front()){
					answer = li.back();
					li.pop_back();
					pcur++;
				}
				else{
					answer = li.front();
					li.pop_front();
					mcur++;
				}
			}
		}
		cout << answer << '\n';
	}
}
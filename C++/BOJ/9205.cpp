#include <bits/stdc++.h>

using namespace std;




int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;

		pair<int,int> start, end;
		cin >> start.first >> start.second;

		vector<pair<int,int>> st;
		st.push_back(start);
		for(int i = 0; i < N; i++){
			int a, b;
			cin >> a >> b;
			st.push_back({a,b});
		}

		cin >> end.first >> end.second;
		st.push_back(end);
		
		int sz = st.size();
		vector<int> visit(sz,-1);
		
		queue<int> q;
		q.push(0);
		visit[0] = 0;
		bool flag = true;
		while(!q.empty()){
			int here = q.front(); q.pop();
			if(here == sz-1){
				cout << "happy" << '\n';
				flag = false;
				break;
			}

			for(int i = 0; i < sz; i++){
				
				int l = abs(st[here].first -st[i].first) + abs(st[here].second - st[i].second);
				if(visit[i] == -1 && (l <= 1000)){
					visit[i] = 0;
					q.push(i);
				}
			}
		}
		if(flag){
			cout << "sad" << '\n';
		}
	}
	
}
	
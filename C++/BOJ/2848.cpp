#include<bits/stdc++.h>

using namespace std;


int main()
{
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	
	int N;
	cin >> N;
	vector<string> s;
	vector<int> visit(26);
	int count = 0;
	for(int i = 0; i < N; i++){
		string str;
		cin >> str;
		s.push_back(str);
		for(int j = 0; j < str.size(); j++){
			visit[str[j]-'a'] = 1;
		}
	}
	
	for(int i = 0; i < 26; i++){if(visit[i])count++;}
	
	vector<int> adj[26];
	vector<int> ind(26);
	vector<int> ans;

	for(int i = 0; i < N-1; i++){
		string s1 = s[i];
		string s2 = s[i+1];

		int len = min(s1.size(), s2.size());
		for(int j = 0; j <= len; j++){
			if(j == len && s1.size() <= s2.size())continue;
			else if(j == len && s1.size() > s2.size()){
				cout << "!";
				return 0;
			}
			if(s1[j] != s2[j]){
				adj[s1[j]-'a'].push_back(s2[j]-'a');
				ind[s2[j]-'a']++;
				break;
			}
		}
	}
	if(count == 1){
		cout << s[0][0];
		return 0;
	}
	queue<int> q;

	for(int i = 0; i < 26; i++){
		if(visit[i] == 1 & ind[i] == 0){
			q.push(i);
		}
	}
	int check = 0;
	while(!q.empty()){
		int here = q.front(); q.pop();

		ans.push_back(here);
		for(int next : adj[here]){
			ind[next]--;
			if(ind[next] == 0){
				visit[next] = visit[here] + 1;
				check = max(check, visit[next]);
				q.push(next);
			}
		}
	}

	//cout << count << " " << ans.size() << " " << check;
	if(ans.size() < count){
		cout << "!";
	}
	else if(ans.size() == count && check != count){
		cout << "?";
	}
	else{
		for(int i = 0; i < ans.size(); i++){
			cout << char(ans[i]+'a') << "";
		}
	}
	

}
#include <bits/stdc++.h>

using namespace std;
int N, M;
map<string,int> m;
string name[501];
int cur = 0;
int parent[501];
int present[501];
int find(int i){return i == parent[i] ? i : parent[i] = find(parent[i]);}

bool Union(int i, int j){
	int pi = find(i);
	int pj = find(j);
	if(pi == pj)return false;
	parent[pi] = pj;
	return true;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		parent[i] = i;
		present[i] = i;
	}
	
	for(int i = 0; i < N; i++){
		string temp;
		cin >> temp;
		cin >> temp;
		cin >> temp;
		m[temp] = cur;
		name[cur++] = temp;
	}

	for(int i = 0; i < M; i++){
		string a, b;
		int t;
		string temp;
		cin >> temp;
		cin >> temp;
		cin >> temp;
		for(int i = 0; i < temp.size(); i++){
			if(temp[i] == ','){
				a = temp.substr(0,i);
				break;
			}
		}
		cin >> temp;
		cin >> temp;
		for(int i = 0; i < temp.size(); i++){
			if(temp[i] == ','){
				t = temp[i+1]-'0';
				b = temp.substr(0,i);
				break;
			}
		}

		int aa = m[a];
		int bb = m[b];
		int aaa = present[find(aa)];
		int bbb = present[find(bb)];

		if(Union(aa,bb)){
			if(t == 1){
				present[find(aa)] = aaa; 
			}
			else{
				present[find(aa)] = bbb;
			}
		}else{
			if(t == 1){
				present[find(aa)] = aa; 
			}
			else{
				present[find(aa)] = bb;
			}
		}

	}

	set<int> s;

	for(int i = 0; i < N; i++){
		s.insert(find(i));

	}
	cout << s.size() << '\n';
	vector<string> answer;
	for(auto it = s.begin(); it != s.end(); it++){
		answer.push_back(name[present[*it]]);
	}
	sort(answer.begin(), answer.end());
	for(int i = 0; i < answer.size(); i++){
		cout << "Kingdom of " << answer[i] << '\n';
	}
}
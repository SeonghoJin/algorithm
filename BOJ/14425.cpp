#include <bits/stdc++.h>

using namespace std;

int N, M;

class Trie{
	Trie* tr[26];

	bool check = false;
	public:
	void insert(const char *t){
		int c = (*t) - 'a';
		if(*t == '\0'){check = true; return;}
		
		if(tr[c] == nullptr)tr[c] = new Trie();
		tr[c]->insert(t+1);
	}

	bool che(const char *t){
		int c = (*t) - 'a';
		if(*t == '\0'){return check;}
		if(tr[c] == nullptr)return false;
		return tr[c]->che(t+1);
	}
};


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	Trie* ttt = new Trie();
	for(int i = 0; i < N; i++){
		string s;
		cin >> s;
		ttt->insert(s.c_str());
	}
	int ans = 0;
	for(int i = 0; i < M; i++){
		string s;
		cin >> s;
		if(ttt->che(s.c_str())){ans++;}
	}
	cout << ans;
	
}
	



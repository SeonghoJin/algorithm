/*#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Trie{
	
	Trie* go[26];
	Trie* fail;
	bool check;
	Trie(){
		fill(go, go+26, nullptr);
		check = false;
	}
	
	~Trie(){
		for(int i = 0; i < 26; i++){
			if(go[i])delete go[i];
		}
	}
	
	void insert(const char* c){
		int next = *c - 'a';
		
		if(*c == '\0'){
			check = true;
			return ;
		}
		
		if(!go[next])go[next] = new Trie();
		
		go[next]->insert(c+1);
	}
	
};

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	
	int N;
	cin >> N;
	
	Trie* root = new Trie();
	
	while(N--){
		string s;
		cin >> s;
		root->insert(s.c_str());
	}
	
	
	queue<Trie*> q;
	root->fail = root;
	q.push(root);
	
	while(!q.empty()){
		Trie* here = q.front(); q.pop();
		
		for(int i = 0; i < 26; i++){
			Trie* there = here->go[i];
			if(!there)continue;
			
			if(here == root){
				there->fail = root;	
			}
			else{
				
				Trie* new_fail = here->fail;
				
				while(new_fail != root && !new_fail->go[i])new_fail = new_fail->fail;
				
				if(new_fail->go[i])new_fail = new_fail->go[i];
				
				there->fail = new_fail;
			}
			
			if(there->fail->check)there->check = true;
			q.push(there);
		}
		
		
	}
	
	
	cin >> N;
	
	while(N--){
		
		string s;
		cin >> s;
		int sz = s.size();
		Trie* search = root;
		bool flag = false;
		for(int i = 0; i < sz; i++){
			int next = s[i]-'a';
			
			while(search != root && !search->go[next])search = search->fail;
			
			if(search->go[next])search = search->go[next];
			if(search->check){
				flag = true;
				break;
			}
		}
		
		cout << (flag ? "YES" : "NO") << '\n';
	}
	
	delete root;
}
*/
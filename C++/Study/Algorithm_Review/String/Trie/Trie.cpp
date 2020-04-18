#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Trie{
	
	Trie *go[26];
	Trie *fail;
	
	bool output; 
	
	
	void insert(const char* c){
		if(*c == '\0'){
			output = true;
				return;
		}
		int next = *c - 'a';
		if(!go[next]){
			go[next] = new Trie();
		}
		go[next]->insert(c+1);
	}
	
	
};

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	Trie* root = new Trie();
	
	int N;
	cin >> N;
	char c[10001];
	
	for(int i = 0; i < N; i++){
		string s;
		cin >> s;
		root->insert(s.c_str());
	}
	
	
}
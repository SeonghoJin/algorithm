#include <bits/stdc++.h>

using namespace std;
int ans = 0;
class Trie{

	Trie* go[26];
	bool check = false;
	int sz = 0;
	public :
		~Trie(){
			for(int i = 0; i < 26; i++){
				if(go[i])delete go[i];
			}
		}
		void insert(char *c){
			if(*c == '\0'){
				check = true;
				return;
			}
			int next = *c - 'a';
			if(go[next] == nullptr){sz++; go[next] = new Trie();}
			go[next]->insert(c+1); 
		}

		void search(int k){
			if(check){ans+=k;}
			if(sz > 1 || k == 0 || (check && sz == 1))k++;
			for(int i = 0; i < 26; i++){
				if(go[i] != nullptr){
					go[i]->search(k);
				}
			}

		}

};


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	int N;
	while(scanf("%d", &N) != EOF){
		ans = 0;
		Trie* tt = new Trie();
		char c[81];
		for(int i = 0; i < N; i++){
			scanf("%s",c);
			tt->insert(c);
		}
		tt->search(0);
		
		printf("%.2f\n", 1.0*ans/N);
		delete tt;
	}
}
	



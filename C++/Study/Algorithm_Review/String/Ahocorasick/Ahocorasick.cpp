
#include <queue>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
 
// 트라이 구조체
char str1[1000001], str2[101], temp[101];
char m[128];

	
struct Trie{
    // 현재 노드에서 해당 문자를 받으면 가는 노드
    Trie *go[4];
    // 현재 노드에서 해당 문자의 go 목적지가 없을 때 가는 노드
    Trie *fail;
    // 현재 노드에 도달하면 찾는 문자열 집합: 이 문제에서는 존재성만 따지면 됨
    bool output;
    
    Trie(){
        fill(go, go+4, nullptr);
        output = false;
    }
	 ~Trie(){
        for(int i=0; i<4; i++)
            if(go[i]) delete go[i];
    }
   
    void insert(const char* key){
		  if(*key == '\0'){
		   output = true;
        return;
        }
        int next = m[*key];
        if(!go[next]){
            go[next] = new Trie;
        }
        go[next]->insert(key+1);
    }
};


int main(){
	m['A'] = 0;
m['C'] = 1;
m['T'] = 2;
m['G'] = 3;
	int T;
	cin >> T;
	Trie* root;
    
	while(T--){
    int N, M;
	root = new Trie();
    // 트라이에 S의 원소들을 모두 집어넣는다.
    cin >> N >> M >> str1 >> str2;
	root->insert(str2);
		
   for(int i = 0; i < M; i++){
		for(int j = i+1; j < M; j++){
			strcpy(temp,str2);
			reverse(temp+i, temp+j+1);
			root->insert(temp);
		}
   }
		// BFS를 통해 트라이 노드를 방문하며 fail 함수를 만든다.
    
	queue<Trie*> Q;
    root->fail = root;
    Q.push(root);
    while(!Q.empty()){
        Trie *current = Q.front();
        Q.pop();
 
        // 26개의 input 각각에 대해 처리한다.
        for(int i=0; i<4; i++){
            Trie *next = current->go[i];
            if(!next) continue;
 
            // 루트의 fail은 루트다.
            if(current == root)next->fail = root;
            else{
                Trie *dest = current->fail;
                // fail을 참조할 가장 가까운 조상을 찾아간다.
                while(dest != root && !dest->go[i])
                    dest = dest->fail;
                // fail(px) = go(fail(p), x)
                if(dest->go[i]) dest = dest->go[i];
                next->fail = dest;
            }
            
			// fail(x) = y일 때, output(y) ⊂ output(x)
            if(next->fail->output) next->output = true;
 
            // 큐에 다음 노드 push
            Q.push(next);
        
		}
    }
 
    // 각 문자열을 받아 문제를 푼다.
	int ans = 0;
    // 루트부터 시작
    Trie* current = root;
		
	for(int c=0; c < N; c++){
        int next = m[str1[c]];
		// 현재 노드에서 갈 수 없으면 fail을 계속 따라감
        while(current != root && !current->go[next])
               current = current->fail;
           // go 함수가 존재하면 이동. 루트면 이게 false일 수도 있다
            if(current->go[next])
                current = current->go[next];
            // 현재 노드에 output이 있으면 찾은 것이다.
            if(current->output){
                ans++;
            }
        }
		
     cout << ans << '\n';
	
	// 내 힙은 소중하기에 꼭 동적할당을 해제한다.
    delete root;
	}
}

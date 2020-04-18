#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> adjlist[100000];
vector<int> son[100000];
int visited[100000];
int N;
int ans;
void maketree(int n){
    visited[n] = 1;
    for(int i = 0; i < adjlist[n].size(); i++){
        if(visited[adjlist[n][i]] != 0)continue;
        son[n].push_back(adjlist[n][i]);
        maketree(adjlist[n][i]);
    }
}

bool check = true;

void dfs(int n, int k){
    if(son[n].size() == 0)ans--;
    if(son[n].size() == 0 && (k & 1)){
        check = false;
        return;
    }
    
    for(int i = 0; i < son[n].size(); i++){
        int next = son[n][i];
        dfs(next, k+1);
    }
}

int main(){

    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    
    cin >> N;
    ans = N - 1;
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        adjlist[a-1].push_back(b-1);
        adjlist[b-1].push_back(a-1);
    }

    int root;
    for(int i = 0; i < N; i++){
        if(adjlist[i].size() == 1){
            root = i; break;
        }
    }
    maketree(root);
    
    int ch[100001];
    fill(ch, ch+100001, 0);
    for(int i=0;i<N;i++) {
        for(int j=0;j<adjlist[i].size();j++) {
            int next = adjlist[i][j];
            if(adjlist[next].size() == 1){
                ch[i] = 1;
            }
        }
    }
     for(int i = 0; i < N; i++){
        if(ch[i])ans++;
    }
    dfs(root, 0);
    cout << (check ? 1 : 3) << " " << ans-1 << '\n';



}
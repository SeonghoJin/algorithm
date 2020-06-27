#include<bits/stdc++.h>

using namespace std;

int N, M, H;

int adj[12][12][51];
int pre[12][51];
int c[12][51];
int l[12];
void precalc(){

    for(int i = 1; i <= N; i++){
        int start = i;
        int line = start;
        int height = 1;
        while(height != H+1){
            if(adj[line][line+1][height]){
                line++;
            }
            else if(adj[line][line-1][height]){
                line--;
            }
            pre[line][height] = i;
            height++;
        }
    }
    for(int i = 1; i <= N; i++){
        l[pre[i][H]] = i;
    }
}

int answer = 987654321;

bool check(){
    for(int i = 1; i <= N; i++){
        if(l[i] != i)return false;
    }
    return true;
}
void f(int depth){
    if(check()){
       answer = min(answer, depth);
    }
    if(depth == 3){
        return;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= H; j++){
                int here = i;
                int next = here + 1;
                if(next <= 0 || next > N || c[next][j] || c[here][j])continue;
                int a = pre[here][j];
                int b = pre[next][j];
                c[here][j] = 1;
                c[next][j] = 1;
                swap(l[a],l[b]);
                f(depth+1);
                swap(l[a],l[b]);
                c[next][j] = 0;
                c[here][j] = 0;
                while(i <= H){
                    if(!c[next][j] && !c[next][j+1])break;
                    j++;
                }
        }
    }
}

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N >> M >> H;

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        adj[b][b+1][a] = 1;
        adj[b+1][b][a] = 1;
        c[b][a] = 1;
        c[b+1][a] = 1;
    }
    precalc();

    
    f(0);
    cout << (answer == 987654321 ? -1 : answer);
}
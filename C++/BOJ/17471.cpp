#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[11];
vector<int> component[11];
int color;
int visit[11];
int cur = 0;
int sz[11];

void bfs1(int n){
    vector<int> temp;
    queue<int> q;
    q.push(n);
    visit[n]=1;
    while(!q.empty()){
        int here = q.front(); q.pop();
        //cout << here << '\n';
        temp.push_back(here);
        for(int next : adj[here]){
            if(visit[next] == 0){
            visit[next] = 1;
            q.push(next);
            }
        }
    }
   
    component[cur++] = temp;
}

bool bfs2(int s){
    vector<int> v(11,0);
    int r = -1;
    int b = -1;
    for(int i = 1; i <= N; i++){
        if((1 << (i-1)) & color){
            r = i;
        }
        else{
            b = i;
        }
    }             

    if(r != -1){
        queue<int> q;
        q.push(r);
        v[r] = 1;
        while(!q.empty()){
            int here = q.front(); q.pop();
            for(int next : adj[here]){

                if(v[next] == 0 && ((1 << (next - 1) & color))){
                    v[next] = 1;
                    q.push(next);
                }
            }
        }
    }
    if(b != -1){
        queue<int> q;
        q.push(b);
        v[b] = 1;
        while(!q.empty()){
            int here = q.front(); q.pop();
            for(int next : adj[here]){
                if(v[next] == 0 && ((1 << (next - 1) & color) == 0)){
                    v[next] = 1;
                    q.push(next);
                }
            }
        }
    }

    
    for(int i = 0; i < component[s].size(); i++){
        if(v[component[s][i]] == 0){
            return false;
        }
    }
    return true;
}
int check(){
    int sum1 = 0;
    int sum2 = 0;

    bool flag = bfs2(0);

    if(flag){
        for(int i = 1; i <= N; i++){
            if((1 << (i-1)) & color){
                sum1 += sz[i];
            }
            else{
                sum2 += sz[i];
            }
        }
        return abs(sum1 - sum2);
    }
    else return INT_MAX;
}


int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> sz[i];
    }   

    for(int i = 1; i <= N; i++){
        int K;
        cin >> K;
        for(int j = 0; j < K; j++){
            int t;
            cin >> t;
            adj[i].push_back(t);
        }
    }

    for(int i = 1; i <= N; i++){
        if(visit[i] == 0){
            bfs1(i);
        }
    }
    int answer = INT_MAX;    

    if(cur > 2){
        cout << -1;
    }    
    else if(cur == 2){
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < cur; i++){
            for(int j = 0; j < component[i].size(); j++){
                if(i == 0){
                    sum1 += sz[component[i][j]];
                }
                else{
                    sum2 += sz[component[i][j]];
                }
            }
        }
        cout << abs(sum1 - sum2);   
    }
    else{
        for(int i = 0; i < (1 << N); i++){
            color = i;
            answer = min(answer, check());
        }
        cout << answer;
    }
}
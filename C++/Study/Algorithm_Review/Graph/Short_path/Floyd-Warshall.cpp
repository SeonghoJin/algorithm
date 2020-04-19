#include <bits/stdc++.h>

using namespace std;
int arr[101][101];

vector<int> adjlist[101];

int bfs(int start, vector<int>& v){
    queue<int> q;
    q.push(start);
    int ret = 0;
    vector<int> visit(101,-1);
    visit[start] = 0;
    while(!q.empty()){
        int here = q.front(); q.pop();
        ret = max(ret,visit[here]);
        for(int i = 0; i < adjlist[here].size(); i++){
            int next = adjlist[here][i];
            if(visit[next] == -1){
                visit[next] = visit[here] + 1;
                q.push(next);
            }
        }
        
    }
    return ret;
}

int check(vector<int>& v){
    int ans = 987654321;
    int ret;
    for(int i = 0; i < v.size(); i++){
        int start = v[i];
        if(bfs(start,v) < ans){
            ans = bfs(start,v);
            ret = v[i];
        }
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio;


    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a ,b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
        arr[a][b] = arr[b][a] = 1;
    }
    
    vector<int> visit(101,0);

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                if(arr[j][i] && arr[i][k]){
                    arr[j][k] = 1;
                }
            }
        }
    }
    int ans = 0;
    vector<int> tt;


    for(int i = 1; i <= N; i++){
        if(visit[i])continue;
        visit[i] = 1;
        vector<int> temp;
        temp.push_back(i);
        for(int j = i+1; j <= N; j++){
            if(arr[i][j]){
                visit[j] = 1;
                temp.push_back(j);
            }
        }
        tt.push_back(check(temp));
    }



    cout << tt.size() << '\n';
    sort(tt.begin(), tt.end());
    for(int i = 0; i < tt.size(); i++){
        cout << tt[i] << '\n';
    }
}
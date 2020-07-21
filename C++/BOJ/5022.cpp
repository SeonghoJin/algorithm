#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
int visit[101][101][4];
int visitd[101][101];
int N, M;
pii arr[4];
int dp[101][101];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,-1,0,1};

bool check(int y, int x){
    return !(y < 0 || y > M || x < 0 || x > N);
}

void print(){
    for(int i = 0; i <= M; i++){
        for(int j = 0; j <= N; j++){
            cout << dp[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

int bfs(pii a, pii b, int f){
    int sy = a.first;
    int sx = a.second;
    int ey = b.first;
    int ex = b.second;
    for(int i = 0; i < 101; i++){
        fill(dp[i], dp[i]+101, 0);
    }
    
    dp[sy][sx] = 1;
    queue<pii> q;
    q.push({sy,sx});
    while(!q.empty()){
        pii t = q.front(); q.pop();

        int y = t.first;
        int x = t.second;

        if(y == ey && x == ex){
            break;
        }

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(!check(ny,nx))continue;
            bool ff = false;
            if(f == 0){
                for(int j = 0; j < 2; j++)
                if(ny == arr[2+j].first && nx == arr[2+j].second){
                    ff=true;
                }
            }
            else{
                for(int j = 0; j < 2; j++)
                if(ny == arr[0+j].first && nx == arr[0+j].second){
                    ff=true;
                }
            }
            if(ff)continue;
            if(dp[ny][nx] == 0 && visitd[ny][nx] == 0){
                dp[ny][nx] = dp[y][x]+1;
                q.push({ny,nx});
            }
        }
    }

    int my = ey;
    int mx = ex;
    int count = 0;
    visitd[my][mx] = 1;
    if(dp[ey][ex] == 0)return 987654321;
    while(!(my == sy && mx == sx)){
        for(int i = 0; i < 4; i++){
            int ny = my + dy[i];
            int nx = mx + dx[i];
            if(check(ny,nx) && dp[ny][nx] - dp[my][mx] == -1){
                my = ny;
                mx = nx;
                visitd[my][mx] = 1;
                break;
            }
        }
    }

    return dp[ey][ex] - 1;   
}

int main(){
    
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N >> M;

    for(int i = 0; i < 4; i++){
        cin >> arr[i].second >> arr[i].first;
    }

    int answer = (bfs(arr[0],arr[1], 0) + bfs(arr[2],arr[3], 1));

    for(int i = 0; i < 101; i++){
        fill(visitd[i], visitd[i]+101, 0);
    }
    
    answer = min(answer, bfs(arr[2],arr[3], 1) + bfs(arr[0],arr[1], 0));
    if(answer >= 200000){
        cout << "IMPOSSIBLE";
    }
    else{
        cout << answer;
    }
}
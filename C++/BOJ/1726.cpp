#include <bits/stdc++.h>

using namespace std;

int N, M;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int m[101][101];
int dp[101][101][4];
int sy, sx, sdir;
int ey, ex, edir;
struct dot{
    int y;
    int x;
    int dir;
    dot(int _y, int _x, int _dir) : y(_y), x(_x), dir(_dir){

    }
};
bool check(int y, int x){
    return !(y < 0 || y >= N || x < 0 || x >= M);
}

struct cmp{
bool operator()(const dot& a, const dot& b){
    return dp[a.y][a.x][a.dir] > dp[b.y][b.x][b.dir];
}
};

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> m[i][j];
            fill(dp[i][j], dp[i][j]+4, 987654321);
        }
    }

    cin >> sy >> sx >> sdir;
    cin >> ey >> ex >> edir;
    sy--;
    sx--;
    ey--;
    ex--;
    sdir--;
    edir--;

    sdir = ( (sdir == 1 || sdir == 2) ? 3 - sdir : sdir);
    edir = ( (edir == 1 || edir == 2) ? 3 - edir : edir);

    priority_queue<dot,vector<dot>, cmp> q;
    q.push({sy, sx, sdir});
    dp[sy][sx][sdir] = 0;
    while(!q.empty()){
        dot temp = q.top(); q.pop();
        int hy = temp.y;
        int hx = temp.x;
        int hdir = temp.dir;
        for(int i = 0; i < 4; i++){
            if(i == 2)continue;
            int count = (i == 3 ? 1 : i);
            int ndir = (hdir + i)%4;
            int ddy = dy[ndir];
            int ddx = dx[ndir];
            int ny = hy;
            int nx = hx;
            int ccount = 0;
            while(check(ny, nx) && ccount <= 3)
            {   if(m[ny][nx])break;
                if(m[ny][nx] == 0 && dp[ny][nx][ndir] > count + ccount + dp[hy][hx][hdir]){
                    dp[ny][nx][ndir] = count + (ccount > 0) + dp[hy][hx][hdir];
                    q.push({ny,nx,ndir});
                }  
                ccount++;
                ny += ddy;
                nx += ddx;
            }
        }
    }

    cout << dp[ey][ex][edir];
}
#include <bits/stdc++.h>

using namespace std;

int L, R, C;
int ez, ey, ex;
int sz,sy,sx;
string arr[31][31];
int dp[31][31][31];
int dz[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dx[6] = {0,0,0,0,-1,1};

struct trip{
    int x;
    int y;
    int z;

    trip(int _z, int _y, int _x){
        x = _x;
        y = _y;
        z = _z;
    }
};

int main(){
    

    while(1){
    scanf("%d %d %d", &L, &R, &C);
    if(L == 0 && R == 0 && C == 0)break;
    for(int i = 0; i < L; i++){
        for(int j = 0; j < R; j++){
            cin >> arr[i][j];
        }
        string str;
        getline(cin,str);
        cin.ignore();
    }
    for(int i = 0; i < L; i++){
        for(int j = 0; j < R; j++){
            for(int k = 0; k < C; k++){
                dp[i][j][k] = 0;
            }
        }
    }
    for(int i = 0; i < L; i++){
        for(int j = 0; j < R; j++){
            for(int k = 0; k < C; k++){
                if(arr[i][j][k] == 'S'){
                    sz = i;
                    sy = j;
                    sx = k;
                }
                if(arr[i][j][k] == 'E'){
                    ez = i;
                    ey = j;
                    ex = k;
                }
            }       
        }
    }
    queue<trip> q;
    q.push({sz,sy,sx});
    int answer = -1;
    while(!q.empty()){
        trip here = q.front(); q.pop();
        int z = here.z;
        int y = here.y;
        int x = here.x;
        if(z == ez && y == ey && x == ex){
            answer = dp[z][y][x];
            break;
        }
        for(int i = 0; i < 6; i++){
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nz >= 0 && nz < L && ny >= 0 && ny < R && nx >= 0 && nx < C && dp[nz][ny][nx] == 0 && arr[nz][ny][nx] != '#'){
                dp[nz][ny][nx] = dp[z][y][x] + 1;
                q.push({nz,ny,nx});
            }
        }
    }
    if(answer != -1){
        cout << "Escaped in " << answer <<" minute(s)." << '\n';
    }
    else{
        cout << "Trapped!" << '\n';
    }
    }
}
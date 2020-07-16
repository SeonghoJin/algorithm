#include <bits/stdc++.h>

using namespace std;
int ans = 0;
int arr[101][101];
int K;
int dy[2][3] = {{-1,0,0}, {1,0,0}};
int dx[2][3] = {{0,-1,1}, {0,-1,1}};

void dfs(int sy, int sx, int py, int px, int n){
    if(n == K+1){
        ans += arr[sy][sx];
        return;
    }
    else{
        if(arr[sy][sx])return;
    }

    if(n == 0){
        arr[sy][sx] = 1;
        dfs(sy-1, sx,sy,sx, n+1);
        arr[sy][sx] = 0;
        return;
    }

    int t = n%2;
    arr[sy][sx] = 1;
    for(int i = 0; i < 3; i++){
        int ny = sy + dy[t][i];
        int nx = sx + dx[t][i];
        if(ny == py && nx == px)continue;
        dfs(ny,nx, sy, sx,n+1);
    }    

    arr[sy][sx] = 0;
}
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> K;
    dfs(50,50,-1,-1,0);
    cout << ans;
}
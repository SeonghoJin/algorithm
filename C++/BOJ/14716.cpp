#include <iostream>
#include <vector>
using namespace std;

int map[251][251];

iadad
void dfs(int y, int x){
    map[y][x] = 0;
   
    for(int i = 0; i < 8; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(check(ny, nx)){
            dfs(ny, nx);
        }
    }
}

int main(){

    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)cin >> map[i][j];
    int ans = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            if(check(i,j)){
                ans++;
                dfs(i,j);
             
                
            }
        }

        cout << ans;
}

#include <iostream>
#include <vector>
using namespace std;

int map[251][251];

int dy[8] = {0,0,1,-1,1,-1,1,-1};
int dx[8] = {1,-1,1,-1,-1,1,0,0};
int N, M;  
    
bool check(int y, int x){
    return (y >=0 && y < N && x >= 0 && x < M && (map[y][x] == 1));
}

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

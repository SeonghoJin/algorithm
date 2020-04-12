#include <iostream>

using namespace std;

int map[301][301];
int N, M;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int check[301][301];
int dep[301][301];
int dfs(int y, int x){
    if(check[y][x] == 1)return 0;
    check[y][x] = 1;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny >= 0 && ny < N && nx >= 0 && nx < M && map[ny][nx] != 0){
            dfs(ny, nx);
        }
    }
    return 1;
}

int dfs(){
    for(int i = 0; i < 301; i++)fill(check[i], check[i]+300, 0);
    int c = 0;
    for(int i = 0; i < 301; i++){
        for(int j = 0; j < 301; j++){
            if(check[i][j] == 0 && map[i][j] > 0){
                dfs(i,j);
                c++;
            }
        }
    }
    return c;
}


int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)cin >> map[i][j];
    }
    int ans = 0;
    int temp = 0;
    int f;
    while(1){
        f = dfs();
        if(f == 0 || f >= 2)break;
        temp++;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(map[i][j] == 0)continue;
                dep[i][j] = 0;
                for(int k = 0; k < 4; k++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(ny >= 0 && ny < N && nx >= 0 && nx < M && map[ny][nx] == 0){
                        dep[i][j]++;
                    }
                }
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                map[i][j] -= dep[i][j];
                map[i][j] = max(map[i][j], 0);
            }
        }
      
     }
    cout << (f == 0 ? f : temp) << '\n';

}
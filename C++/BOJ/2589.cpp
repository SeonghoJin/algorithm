    #include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

string map[51];
int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};
int N, M;
  
int bfs(int y, int x){

   vector<vector<int>> visit(51,vector<int>(51,0));
   queue<pair<int,int>> q;

    q.push({y,x});
    visit[y][x] = 1;
    int dep = 1;
    
    while(!q.empty()){
        pair<int, int> here = q.front(); q.pop();

        for(int i = 0; i < 4; i++){
            int next_y = here.first + dy[i];
            int next_x = here.second + dx[i];
            if(next_y >= 0 && next_y < N && next_x >= 0 && next_x < M && map[next_y][next_x] == 'L' && visit[next_y][next_x] == 0){
                visit[next_y][next_x] = visit[here.first][here.second] + 1;
                dep = max(dep, visit[next_y][next_x]);
                q.push({next_y, next_x});
            }
        }
    }

    return dep - 1;
}

int main(){

    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    
    cin >> N >> M;

    for(int i = 0; i < N; i++)
        cin >> map[i];

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 'L')
            ans = max(ans, bfs(i,j));
        }
    }
   cout << ans;
}

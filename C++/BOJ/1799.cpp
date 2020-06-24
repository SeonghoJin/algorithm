#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

vector<pii> vpii;
int m[11][11];
int N;
int answer1 = 0;
int answer2 = 0;
bool check(int y, int x){

    if(m[y][x] == 0)return false;

    for(pii temp : vpii){
        int ny = temp.first;
        int nx = temp.second;

        if(abs(y-ny) == abs(x-nx))return false;
    }

    return true;
}
void dfs(int k, int cur, int flag){
    if(flag)answer1 = max(answer1,cur);
    else{answer2 = max(answer2,cur);}
    if(k >= N*N){
        return;
    }
    int y = k/N;
    int x = k%N;
    

    if(check(y,x)){
        vpii.push_back({y,x});
        if(N%2 == 0 && (k+2)/N != y){
            if(!flag){
                if(y%2 == 0){
                    dfs(k+3,cur+1,flag);
                }
                else{
                    dfs(k+1,cur+1,flag);
                }
            }
            else{
                if(y%2 == 0){
                    dfs(k+1,cur+1,flag);
                }
                else{
                    dfs(k+3,cur+1,flag);
                }
            }
        }
        else{
            dfs(k+2,cur+1, flag);
        }
        vpii.pop_back();
    }
    if(N%2 == 0 && (k+2)/N != y){
        if(!flag){
            if(y%2 == 0){
                dfs(k+3,cur,flag);
            }
            else{
                dfs(k+1,cur,flag);
            }
        }
        else{
            if(y%2 == 0){
                dfs(k+1,cur,flag);
            }
            else{
                dfs(k+3,cur,flag);
            }
        }
    }
    else{
        dfs(k+2,cur, flag);
    }
  

}

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio;

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> m[i][j];
        }
    }

    dfs(0,0,0);
    vpii.clear();
    dfs(1,0,1);
    cout << answer1 + answer2;
}
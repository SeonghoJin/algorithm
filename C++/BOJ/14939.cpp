#include <bits/stdc++.h>

using namespace std;
using pvvii = pair<vector<vector<int>>, int>;
int N, M;

int dy[5] = {0,1,1,1,2};
int dx[5] = {0,-1,0,1,0};
int ky[5] = {-1,0,0,0,1};
int kx[5] = {0,-1,0,1,0};
const int MAX_INT = 987654321;
vector<vector<int>> matrix(10, vector<int>(10,0));
vector<vector<int>> target(10, vector<int>(10,0));
vector<vector<int>> raw(10, vector<int>(10,0));
void push(vector<vector<int>>& v, int y, int x){
    for(int i = 0; i < 5; i++){
       int ny = y + ky[i];
       int nx = x + kx[i];
       if(ny >= 0 && ny < 10 && nx >= 0 && nx < 10){
          v[ny][nx] = 1 - v[ny][nx];
       }
    }
}

void rev(vector<vector<int>>& v, int y, int x){
    for(int i = 0; i < 5; i++){
       int ny = y + dy[i];
       int nx = x + dx[i];
       if(ny >= 0 && ny < 10 && nx >= 0 && nx < 10){
          v[ny][nx] = 1 - v[ny][nx];
       }
    }
}

bool check(vector<vector<int>>& v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j])return false;
        }
    }
    return true;
}

void print(){
   for(int i = 0; i < matrix.size(); i++){
      for(int j = 0; j < matrix[i].size(); j++){
         cout << matrix[i][j];
      }
      cout << '\n';
   }
   cout << '\n';
}

int f(vector<vector<int>>& v){

    int ret = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < M; j++){
            if(v[i][j] == 1){
                rev(v,i,j);
                ret++;
            }
        }
    }

    if(check(v)){
        return ret;
    }
    else{
        return MAX_INT;
    }
}

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    N = M = 10;
   
    for(int i = 0; i < N; i++){
            string str;
            cin >> str;
        for(int j = 0; j < M; j++){
           matrix[i][j] = (str[j] == '#' ? 0 : 1);
           raw[i][j] = matrix[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
           target[i][j] = 0;
        }
    }

    int answer = MAX_INT;
    
    for(int i = 0; i < (1 << 10); i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                matrix[j][k] = raw[j][k];
            }
        }
        int cnt = 0;
        for(int j = 0; j < 10; j++){
            if((1 << j) & i){
                cnt++;
                push(matrix,0,j);
            }
        }
        answer = min(answer,f(matrix)+cnt);
    }

    if(answer == MAX_INT){
        cout << -1;
    }

    else cout << answer;
}
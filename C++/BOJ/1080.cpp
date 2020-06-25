#include <bits/stdc++.h>

using namespace std;
using pvvii = pair<vector<vector<int>>, int>;
int N, M;

vector<vector<int>> matrix(51, vector<int>(51,0));
vector<vector<int>> target(51, vector<int>(51,0));
vector<vector<int>> rev(vector<vector<int>>& v, int y, int x){
    for(int i = y; i < y+3; i++){
        for(int j = x; j < x+3; j++){
            v[i][j] = 1 - v[i][j];
        }
    }
    return v;
}

bool check(vector<vector<int>>& v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j] != target[i][j])return false;
        }
    }
    return true;
}

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
            string str;
            cin >> str;
        for(int j = 0; j < M; j++){
           matrix[i][j] = str[j] - '0';
        }
    }
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        for(int j = 0; j < M; j++){
           target[i][j] = str[j] - '0';
        }
    }

    int answer = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(i + 3 <= N && j + 3 <= M && matrix[i][j] != target[i][j]){
                rev(matrix,i,j);
                answer++;
            }
        }
    }

    if(check(matrix)){
        cout << answer;
    }
    else{
        cout << -1;
    }

}
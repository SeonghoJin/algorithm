#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 4000;

int arr[4][N_MAX];
int N;
vector<int> v[2];

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 4; j++){
            cin >> arr[j][i];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            v[0].push_back(arr[0][i] + arr[1][j]);
            v[1].push_back(arr[2][i] + arr[3][j]);
        }
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    long long answer = 0;
    
    for(int i = 0; i < v[0].size(); i++){
        int here = v[0][i];
        answer += upper_bound(v[1].begin(),v[1].end(),-here) - lower_bound(v[1].begin(),v[1].end(), -here);
    }
    cout << answer;
}

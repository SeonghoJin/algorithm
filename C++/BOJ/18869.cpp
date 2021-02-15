#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    int M, N;
    cin >> M >> N;
    vector<vector<pair<int,int>>> vpii(M,vector<pair<int,int>>(N,pair<int,int>()));
    vector<int> v[100];
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> vpii[i][j].first;
            vpii[i][j].second = j;
        }
    
        sort(vpii[i].begin(), vpii[i].end());

        v[i].push_back(0);
        for(int j = 1; j < N; j++){
            v[i].push_back(v[i].back() + (vpii[i][j-1].first != vpii[i][j].first));
        }
    }
    
    int ans = 0;
    for(int i = 0; i < M; i++){
        for(int j = i+1; j < M; j++){
            bool f = true;
            for(int k = 0; k < N; k++){
                if(vpii[i][k].second != vpii[j][k].second || v[i][k] != v[j][k]){
                    f = false;
                }
            }
            if(f){
                ans++;
            }
        }
            
        
    }

    cout << ans;

}
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
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> vpii[i][j].first;
            vpii[i][j].second = j;
        }
    
        stable_sort(vpii[i].begin(), vpii[i].end());
        for(int j = 0; j < N-1; j++){
            if(vpii[i][j].first == vpii[i][j+1].first)vpii[i][j-1].second = vpii[i][j].second;
        }
    
    }

    int ans = 0;

    for(int i = 0; i < M; i++){
         
        for(int j = i+1; j < M; j++){
            bool f = true;
            for(int k = 0; k < N; k++){
                if(vpii[i][k].second != vpii[j][k].second){
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
#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> adjlist[101];
const int INF = 987654321;

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adjlist[a].push_back({b,c});
        adjlist[b].push_back({a,c});
    }


    vector<int> sp(N, INF);
    bool Infinityroof = false;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(sp[j] == INF)continue;
            
            for(pair<int,int> next : adjlist[j]){
                int n = next.first;
                int c = next.second;

                if(sp[n] > sp[j] + c){
                    sp[n] = sp[j] + c;
                    if(i == N - 1){
                        Infinityroof = true;
                    }
                }
            }

        }
    }

    

}
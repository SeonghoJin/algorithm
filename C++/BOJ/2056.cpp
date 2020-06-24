#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[10001];

int ttime[10001];
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N;

    int answer = 0;
    for(int i = 1; i <= N; i++){
        cin >> ttime[i];
        int k;
        cin >> k;
        
        for(int j = 0; j < k; j++){
            int a;
            cin >> a;
            adj[i].push_back(a);
        }
        int t = 0;
        for(int next : adj[i]){
            t = max(t, ttime[next]);
        }
        ttime[i] += t;
        answer = max(answer, ttime[i]);

    }
    cout << answer;
}
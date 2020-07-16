#include <bits/stdc++.h>

using namespace std;

int parent[10001];
int s[10001];
int N, M, K;
int find(int i){return i == parent[i] ? i : parent[i] = find(parent[i]);}

void Union(int i, int j){
    int pi = find(i);
    int pj = find(j);
    parent[pi] = pj;
    s[pj] = min(s[pi], s[pj]);
}

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N >> M >> K;

    for(int i = 1; i <= N; i++){
        cin >> s[i];
        parent[i] = i;
    }   

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        Union(a,b);
    }

    long long sum = 0;

    vector<bool> f(10001,0);

    for(int i = 1; i <= N; i++){
        int pi = find(i);
        if(f[pi])continue;
        f[pi] = 1;
        sum += s[pi];
    }
    
    if(sum <= K){
        cout << sum;
    }
    else{
        cout << "Oh no";
    }
}
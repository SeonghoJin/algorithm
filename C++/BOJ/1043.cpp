#include <bits/stdc++.h>

using namespace std;
bool check[51];
set<int> s[51];
queue<int> q;
vector<int> partymember[51];
vector<int> v[51];
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    
    int N, M;
    
    cin >> N >> M;

    int K;
    cin >> K;
    for(int i = 0; i < K; i++){
        int t;
        cin >> t;
        check[t] = 1;
        q.push(t);
    }
    
    for(int i = 0; i < M; i++){
        int sz;
        cin >> sz;
        for(int j = 0; j < sz; j++){
            int t;
            cin >> t;
            partymember[i].push_back(t);
            v[t].push_back(i);
        }
    }

    while(!q.empty()){
        int here = q.front(); q.pop();

        for(int nextparty : v[here]){
            for(int people : partymember[nextparty]){
                if(check[people])continue;
                check[people] = 1;
                q.push(people);
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < M; i++){
        bool flag = true;
        for(int next : partymember[i]){
            if(check[next]){
                flag = false;
                break;
            }
        }
        if(flag)answer++;
    }
    cout << answer;
}
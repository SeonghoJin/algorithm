#include <bits/stdc++.h>

using namespace std;
const int MAX = 100'001;
int depth[MAX];
int cnt[MAX];
bool check(int a){
    return a >= 0 && a < MAX;
}
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    if(N > K){
        cout << N-K << "\n";
        cout << 1 << '\n';
        return 0;
    }

    queue<int> q;
    q.push(N);
    depth[N] = 1;
    cnt[N] = 1;
    while(!q.empty()){
        int here = q.front();
        q.pop();
        int next = here-1;
        if(check(next)){
            if(depth[next] == 0){
                depth[next] = depth[here]+1;
                cnt[next] += cnt[here];
                q.push(next);
            }
            else if(depth[next] - 1 == depth[here]){
                cnt[next] += cnt[here];
            }
        }
        next = here + 1;
        if(check(next)){
            if(depth[next] == 0){
                depth[next] = depth[here]+1;
                cnt[next] += cnt[here];q.push(next);
            }
            else if(depth[next] - 1 == depth[here]){
                cnt[next] += cnt[here];
            }
        }
        next = 2*here;
        if(check(next)){
            if(depth[next] == 0){
                depth[next] = depth[here]+1;
                cnt[next] += cnt[here];q.push(next);
            }
            else if(depth[next] - 1 == depth[here]){
                cnt[next] += cnt[here];
            }
        }
        
    }
   cout << depth[K]-1 << '\n' << cnt[K];
}a#include <bits/stdc++.h>

using namespace std;
const int MAX = 100'001;
int depth[MAX];
int cnt[MAX];
bool check(int a){
    return a >= 0 && a < MAX;
}
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    if(N > K){
        cout << N-K << "\n";
        cout << 1 << '\n';
        return 0;
    }

    queue<int> q;
    q.push(N);
    depth[N] = 1;
    cnt[N] = 1;
    while(!q.empty()){
        int here = q.front();
        q.pop();
        int next = here-1;
        if(check(next)){
            if(depth[next] == 0){
                depth[next] = depth[here]+1;
                cnt[next] += cnt[here];
                q.push(next);
            }
            else if(depth[next] - 1 == depth[here]){
                cnt[next] += cnt[here];
            }
        }
        next = here + 1;
        if(check(next)){
            if(depth[next] == 0){
                depth[next] = depth[here]+1;
                cnt[next] += cnt[here];q.push(next);
            }
            else if(depth[next] - 1 == depth[here]){
                cnt[next] += cnt[here];
            }
        }
        next = 2*here;
        if(check(next)){
            if(depth[next] == 0){
                depth[next] = depth[here]+1;
                cnt[next] += cnt[here];q.push(next);
            }
            else if(depth[next] - 1 == depth[here]){
                cnt[next] += cnt[here];
            }
        }
        
    }
   cout << depth[K]-1 << '\n' << cnt[K];
}
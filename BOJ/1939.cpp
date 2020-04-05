#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int N,M;
set<int> s[10001];
map<int ,int> m[10001];

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int A, B, C;
        cin >> A >> B >> C;

        s[A].insert(B);
        s[B].insert(A);
        
        m[A][B] = max(m[A][B], C);
        m[B][A] = max(m[B][A], C);

    }

    int start, end;
    cin >> start >> end;
    priority_queue<pair<int, int>> pq;
    pq.push({1987654321,start});

    vector<int> sp(10001,-1);

    while(!pq.empty()){
        pair<int ,int> temp = pq.top(); pq.pop();

        int path = temp.first;
        int here = temp.second;
       
        if(sp[here] >= path)continue;

        sp[here] = path;

        for(auto it = s[here].begin(); it != s[here].end(); it++){
            int next = *it;
            int d = m[here][next];
            
            pq.push({min(d,sp[here]), next});
        }

    }

    cout << sp[end];
    
}

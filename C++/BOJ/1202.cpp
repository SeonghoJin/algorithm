#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> v;
vector<int> w;
vector<int> vv;
list<int> li;
void print(){
    cout << '\n';
    for(auto it = li.begin(); it != li.end(); it++){
        cout << *it << " ";
    }
    cout << '\n';
}
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({b,a});
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    multiset<int> ms;
    for(int i = 0; i < K; i++){
        int a;
        cin >> a;
        ms.insert(a);
    }

    long long answer = 0;

    for(int i = 0; i < N && K; i++){
        int a = v[i].first;
        int b = v[i].second;
        
        auto it = ms.lower_bound(b);
        if(it != ms.end()){
            K--;
            answer += a;
            ms.erase(it);
        }
    }

    cout << answer;
}
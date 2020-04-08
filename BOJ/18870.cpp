#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    int N;
    cin >> N;
    vector<pair<int,int>> v(N);
    set<int> s;
    for(int i = 0; i < N; i++){
        cin >> v[i].first;
        v[i].second = i;
        s.insert(v[i].first);
    }
    int cur = 0;
    int ans = 0;
    sort(v.begin(), v.end());
    vector<int> vv(N);
    for(auto it = s.begin(); it != s.end(); it++, ans++){
        int here = *it;
        while(cur < N && v[cur].first == here){
            vv[v[cur].second] = ans;
            cur++;
        }
    }
    
    for(int i = 0; i < N; i++){
        cout << vv[i] << ' ';
    }
        

    
}
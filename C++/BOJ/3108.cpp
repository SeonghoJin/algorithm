#include <bits/stdc++.h>

using namespace std;
using box = pair<pair<int,int>, pair<int,int>>;
const int MAX_N = 1001;
int N;
box boxes[MAX_N];
int parent[MAX_N];
int find(int i){return i == parent[i] ? i : parent[i] = find(parent[i]);}
void Union(int i, int j){
    int pi = find(i);
    int pj = find(j);
    if(pi == pj)return;
    parent[pi] = pj;
}

bool check(box a, box b){
    if(a.second.second < b.first.second || a.second.first < b.first.first || a.first.second > b.second.second || a.first.first > b.second.first)return false;
    if(a.second.first < b.second.first && a.second.second < b.second.second && a.first.first > b.first.first && a.first.second > b.first.second)return false;
    if(b.second.first < a.second.first && b.second.second < a.second.second && b.first.first > a.first.first && b.first.second > a.first.second)return false;
    return true;
}
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N;
    boxes[0] = {{0,0},{0,0}};
    for(int i = 1; i <= N; i++){
        parent[i] = i;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        boxes[i] = {{a,b},{c,d}};
    }
    
    for(int i = 0; i <= N; i++){
        for(int j = i + 1; j <= N; j++){
            if(check(boxes[i], boxes[j])){
                Union(i, j);
            }
        }
    }
    set<int> s;
    for(int i = 0; i <= N; i++){
        s.insert(find(i));
    }
    cout << s.size()-1;
}
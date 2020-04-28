#include<bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int& i : p)
        cin >> i;
    vector<int> pos(n);
    for (int i = 0; i < n; ++i)
        pos[--p[i]] = i;
    vector<bool> was(n);
    for (int i = 0; i < n; ++i) {
        if (was[i])
            continue;
        int me = pos[i];
        while (me < n) {
            was[me] = 1;
            if (me + 1 == n) break;
            if (was[me + 1]) break;
            if (p[me + 1] == p[me] + 1) {
                ++me;
                continue;
            }
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
 
int main() {
    int q;
    cin >> q;
    while (q--)
        solve();
}
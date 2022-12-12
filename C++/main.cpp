#include <bits/stdc++.h>

using namespace std;

map<string, int> m;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string temp;

    int count = 0;;

    while(getline(cin, temp)) {
        count++;
        m[temp]++;
    }

    cout << fixed;
    cout.precision(4);

    for(auto it = m.begin(); it != m.end(); it++){
        double percent = ((double)it->second / (double)count) * 100;
        cout << it->first << ' ' <<  percent << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

int dist(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base ::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        vector<pair<int, int> > v;
        int answerDist = 0;
        pair<int, int> p1 = v[0];
        pair<int, int> p2 = v[0];

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (answerDist < dist(v[i], v[j]))
                {
                    p1 = v[i];
                    p2 = v[j];
                    answerDist = dist(v[i], v[j]);
                }
            }
        }

        cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << '\n';
    }
}
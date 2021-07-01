#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int dist(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

bool comp(const pii &a, const pii &b)
{
    return a.first < b.first;
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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        map<int, int> m;
        sort(v.begin(), v.end());
        int start = v[0];
        int end = v[1];
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i + 1] - v[i] < end - start)
            {
                end = v[i + 1];
                start = v[i];
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            m[v[i]]++;
        };
        vector<int> answer;
        answer.push_back(start);
        m[end]--;
        m[start]--;
        if (m[end] == 0)
        {
            m.erase(end);
        }
        if (m[start] == 0)
        {
            m.erase(start);
        }
        auto it = m.upper_bound(start);
        while (m.size() != 0)
        {
            if (it == m.end())
            {
                it = m.begin();
            }
            while ((*it).second)
            {
                (*it).second--;
                answer.push_back((*it).first);
            }
            auto temp = it;
            it++;
            if ((*temp).second == 0)
            {
                m.erase((*temp).first);
            }
        }
        answer.push_back(end);
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << ' ';
        }
        cout << '\n';
    }
}
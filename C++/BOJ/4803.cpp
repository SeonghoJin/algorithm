#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[501];
int visit[501];
int n, m;

bool dfs(int start, int prev)
{
    visit[start] = 1;
    bool ret = false;
    for (int i = 0; i < adj[start].size(); i++)
    {
        int next = adj[start][i];
        if (next == prev)
            continue;
        if (visit[next] == 1)
        {
            ret = true;
            continue;
        }
        ret |= dfs(next, start);
    }
    return ret;
}

int main()
{
    int num = 0;
    while (1)
    {
        num++;
        for (int i = 0; i < 501; i++)
        {
            vector<int>().swap(adj[i]);
            visit[i] = 0;
        }
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            return 0;
        }

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            if (a == b)
                continue;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int answer = 0;
        for (int i = 1; i <= n; i++)
        {
            if (visit[i] == 0)
            {
                answer += !dfs(i, 0);
            }
        }
        cout << "Case " << num << ": ";
        if (answer == 0)
        {
            cout << "No trees." << '\n';
        }
        else if (answer == 1)
        {
            cout << "There is one tree." << '\n';
        }
        else
        {
            cout << "A forest of " << answer << " trees." << '\n';
        }
    }

    return 0;
}
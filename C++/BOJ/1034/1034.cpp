#include <bits/stdc++.h>

using namespace std;

int N, M;
int count(vector<string> m, vector<int> &clickedList)
{
    int ret = 0;

    for (int i = 0; i < clickedList.size(); i++)
    {
        int clickedColumn = clickedList[i];
        for (int j = 0; j < N; j++)
        {
            m[j][clickedColumn] = m[j][clickedColumn] == '0' ? '1' : '0';
        }
    }

    for (int i = 0; i < N; i++)
    {
        bool check = true;
        for (int j = 0; j < M; j++)
        {
            check &= (m[i][j] == '1');
        }
        ret += check;
    }
    return ret;
}

int main()
{
    cin >> N >> M;

    vector<string> m(N);

    for (int i = 0; i < N; i++)
    {
        cin >> m[i];
    }

    int K;
    cin >> K;

    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        int clicked = 0;
        vector<int> clickedList;
        for (int j = 0; j < M; j++)
        {
            if (m[i][j] == '0')
            {
                clicked++;
                clickedList.push_back(j);
            }
        }
        if (K >= clicked && (K - clicked) % 2 == 0)
        {
            answer = max(answer, count(m, clickedList));
        }
    }

    cout << answer << '\n';
}
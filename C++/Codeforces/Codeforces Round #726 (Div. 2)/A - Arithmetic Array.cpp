#include <bits/stdc++.h>
using namespace std;

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
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            cin >> temp;
            sum += temp;
        }

        if (sum == n)
        {
            cout << "0" << '\n';
        }
        else if (sum > n)
        {
            cout << sum - n << '\n';
        }
        else
        {
            cout << 1 << '\n';
        }
    }
}
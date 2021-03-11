#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<long long, long long>;
 
int main()
{
 
    cin.tie(0);
    ios_base ::sync_with_stdio(0);
 
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> v1;
        vector<long long> v2;
        for (int i = 0; i < 2 * n; i++)
        {
            int a, b;
            cin >> a >> b;
            if (a == 0)
            {
                v1.push_back(b);
            }
            else if (b == 0)
            {
                v2.push_back(a);
            }
        }
        
        double answer = 0;
 
        sort(v1.begin(), v1.end(), [](long long a, long long b) -> bool {
            return abs(a) < abs(b);
        });
 
        sort(v2.begin(), v2.end(), [](long long a, long long b) -> bool {
            return abs(a) < abs(b);
        });
        
        cout.precision(18);
        for(int i = 0; i < n; i++){
            answer += sqrt(v1[i]*v1[i] + v2[i]*v2[i]);
        }
        cout << answer << '\n';
    }
}
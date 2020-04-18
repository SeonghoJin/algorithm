/*#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
 
using namespace std;
 
const int MAXN = 2000001 * 2;
 
string tmp, str;
 
int A[MAXN];
long long ans = 0;
void manachers(string S, int N)
{
    int r = 0, p = 0;
    for (int i = 0; i < N; i++)
    {	ans++;
        if (i <= r)
            A[i] = min(A[2 * p - i], r - i);
        else
            A[i] = 0;
 
        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N && S[i - A[i] - 1] == S[i + A[i] + 1]){
			A[i]++;
		}
            
        if (r < i + A[i])
        {
            r = i + A[i];
            p = i;
        }
    }
}
int main()
{
    cin >> tmp;
 
    int len = tmp.size();
 
    for (int i = 0; i < len; i++)
    {
        str += '#';
        str += tmp[i];
    }
    str += '#';
 
    manachers(str, str.size());
 
    len = str.size();
	long long ans = 0;
	for(int i = 0; i < len; i++){
		ans += (i & 1 ? (A[i]+1)/2 : A[i]/2);
	}
	cout << ans;
	
    return 0;
}*/


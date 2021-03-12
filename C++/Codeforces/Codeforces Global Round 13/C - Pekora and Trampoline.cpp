#include <bits/stdc++.h>
 
using namespace std;
 
void f(vector<int>& v, int start){
    int n = start;
    int num = v[start];   
    int sz = v.size();
    v[n]--;
    while(n + num < sz){
        n = n+num;
        num = v[n];
        v[n] = max(1, v[n]-1);
    }
}
 
int main()
{
 
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
 
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        // int answer = 0;
        // for(int i = 0; i < n; i++){
 
        //     while(v[i] != 1){
        //         f(v, i);
        //         for(int j = 0; j < n; j++){
        //             cout << v[j] << " ";
        //         }
        //         cout << '\n';
        //         answer++;
        //     }
        // }
        // cout << answer << '\n';
        vector<int> jumped(n);
        long long answer = 0;
 
        for (int i = 0; i < n; i++)
        {      
            if (jumped[i] > 0)
            {
                int k = v[i] - jumped[i];
                int mi = max(1, k);
                int ma = min(i+v[i]+1, n);
                for (int j = i + mi + 1; j < ma; j++)
                {
                    jumped[j]++;
                }
                if (k < 1)
                {
                    if(i + 1 < n){
                        jumped[i+1] += 1 - k;
                    }
                }
                v[i] = max(1, k);
            }
            int diff = max(0, i + v[i] - n);
            // cout << "current " << v[i] <<  " " << "diff = " << diff << " ";
            answer += diff;
            v[i] -= diff;
            while(v[i] > 1){
                answer++;
                if(i+v[i] < n){
                    jumped[i+v[i]]++;
                }
                v[i]--;
            }
            // cout << answer << '\n';
            // for(int j = 0; j < n; j++)cout << jumped[j] << " ";
            // cout << '\n';
        }
 
        cout << answer << '\n';
        
    }   
}
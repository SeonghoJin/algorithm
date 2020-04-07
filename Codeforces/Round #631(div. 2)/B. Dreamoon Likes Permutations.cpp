#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int SIZE = 200001;
int arr[SIZE];

bool judge(int a[], int n){
    int used[SIZE];
    for(int i = 1; i <= n; i++)used[i] = 0;
    for(int i = 0; i < n; i++){used[a[i]] = 1;}
    for(int i = 1; i <= n; i++)
        if(!used[i])return 0;

    return 1;    
}

bool judge(int len1, int n){
    return judge(arr, len1) && judge(arr+len1, n - len1);
}

int main(){

    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int ma = 0;
        int ans_cnt = 0;
        int ans[2][2];
        for(int i = 0; i < n; i++){
            int t;
            cin >> arr[i];
            ma = max(ma, arr[i]);
        }
        if(judge(n - ma, n)){
            ans[ans_cnt][0] = n-ma;
            ans[ans_cnt++][1] = ma;
        }

        if(ma * 2 != n && judge(ma, n)){
            ans[ans_cnt][0] = ma;
            ans[ans_cnt++][1] = n-ma;
        }

        cout << ans_cnt << '\n';

        for(int i = 0; i < ans_cnt; i++){
            cout << ans[i][0] << " " << ans[i][1] << '\n';
        }
    }
}
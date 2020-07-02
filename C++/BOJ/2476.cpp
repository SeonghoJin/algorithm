#include <bits/stdc++.h>

using namespace std;
int arr[100'001];
int N;
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N;
    for(int i = 0; i < N; i++){cin >> arr[i];}

    int answer = INT_MAX;
    int ans1 = -1;
    int ans2 = -1;

    for(int i = 0; i < N-1; i++){
        if(abs(answer) > abs(arr[i] + arr[i+1])){
            answer = arr[i] + arr[i+1];
            ans1 = i;
            ans2 = i+1;
        }
    }

    for(int i = 0; i < N; i++){
        int here = i;
        int next_target = -arr[i];
        int next = lower_bound(arr,arr+N, next_target) - arr;
        if(next != i && next >=0 && next < N && abs(answer) > abs(arr[i] + arr[next])){
            ans1 = i;
            ans2 = next;
            answer = arr[i] + arr[next];
        }
        
        if(next-1 != i && next-1 >=0 && next-1 < N && abs(answer) > abs(arr[i] + arr[next-1])){
            ans1 = i;
            ans2 = next-1;
            answer = arr[i] + arr[next-1];
        }
        if(next+1 != i && next+1 >=0 && next+1 < N && abs(answer) > abs(arr[i] + arr[next+1])){
            ans1 = i;
            ans2 = next;
            answer = arr[i] + arr[next+1];
        }
    }
    
    cout << min(arr[ans1], arr[ans2]) << " " << max(arr[ans1], arr[ans2]);
}
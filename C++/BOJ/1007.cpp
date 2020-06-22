#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> arr[20];
int N;


int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    int T;
    cin >> T;
    cout.precision(20);
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> arr[i].first >> arr[i].second;
        }
        double answer = __LONG_LONG_MAX__;
        for(int i = 0; i < (1 << N); i++){
            int sum = 0;
            for(int j = 0; j < N; j++){
                if(i & (1 << j)){
                    sum++;
                }
            }
            if(sum == N/2){
                long long a = 0;
                long long b = 0;
                for(int j = 0; j < N; j++){
                    if(i & (1 << j)){
                        a += arr[j].first;
                        b += arr[j].second;
                    }
                    else{
                        a -= arr[j].first;
                        b -= arr[j].second;
                    }
                }
                answer = min(answer, sqrt(a*a+b*b));
            }
        }
        cout << answer << '\n';
    }
}
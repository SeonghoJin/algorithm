#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
const int SIZE = 1'000'001;
pair<int, int> Arr[SIZE];
pair<int, int> Arr1[SIZE];
pair<int, int> Arr2[SIZE];
int main(){

    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> Arr[i].first >> Arr[i].second;
    }
    
    int v_min = 1000000000;
    int v_max = 0;
        
    for(int i = 0; i < N; i++){
        v_min = min(v_min,(Arr[i].first == 0 ? 1000000000 : Arr[i].first));
        v_max = max(v_max,Arr[i].second == 0 ? 0 : Arr[i].second);    
        Arr1[i].first = v_min;
        Arr1[i].second = v_max;
       
    }
    v_min = 0;
    v_max = 1000000000;
    for(int i = N-1; i >= 0; i--){
        v_min = max(v_min,(Arr[i].first == 0 ? 0 : Arr[i].first));
        v_max = min(v_max,Arr[i].second == 0 ? 1000000000 : Arr[i].second);    
        Arr2[i].first = v_min;
        Arr2[i].second = v_max;
     
    }

    int ans = 0;
    for(int i = 1; i < N; i++){
        if(Arr1[i-1].first> Arr2[i].first  && Arr1[i-1].second < Arr2[i].second){
            ans = max(ans, i);
        }    

    }
    if(ans == 0)cout << -1;
    else{cout << ans;}
}
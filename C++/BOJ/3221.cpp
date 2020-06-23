#include <bits/stdc++.h>

using namespace std;

int L, T;
int N;


int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    vector<int> v;

    cin >> L >> T;
    cin >> N;

    for(int i = 0; i < N; i++){
        int a;
        char b;
        cin >> a >> b;
        if(b == 'D'){
            a += T;
        }
        else{
            a = L - a + T;
        }
        a%=2*L;
        if(a > L){
            a = 2*L - a;
        }

        if(b == 'L'){
            a = L-a;            
        }

        v.push_back(a);
    }   
    sort(v.begin(), v.end());

    for(int i : v){
        cout << i << " ";
    }
}
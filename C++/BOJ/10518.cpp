#include <bits/stdc++.h>

using namespace std;

int a[80002];
int b[40002];

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    int w, h;
    int a, b;
    int t;

    cin >> w >> h >> a >> b;
    cin >> t;

    int k = (a+t)%(2*w);
    int kk = (b+t)%(2*h);

    if(k/w >= 1){
        k = w - k%w;
    }
    if(kk/h >= 1){
        kk = h - kk%h;
    }
    cout << k << " " << kk;

}
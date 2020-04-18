#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){

    if(b == 0)return a;
    return gcd(b,a%b);
}

vector<int> primes;
int prime_check[1001];

int main(){

    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    
    for(int i = 2; i <= 1000; i++){
        if(!prime_check[i]){
            primes.push_back(i);
            for(int j = i*i; j <= 1000; j+=i){
                prime_check[j] = 1;
            }
        }
    }

    int T;
    cin >> T;

    while(T--){
        vector<int> v;
        int sz;
        cin >> sz;

        for(int i = 0; i < sz; i++){
            int t; cin >> t;
            v.push_back(t);
        }

        int c = 1;
        vector<int> f(1001);

        for(int i = 0; i < primes.size(); i++){
            int divisor = primes[i];
            bool flag = false;
            for(int j = 0; j < v.size(); j++){
                
                if(f[j] == 0 && (v[j]%divisor == 0)){
                    flag = true;
                    f[j] = c;
                }
            }
            if(flag)c++;
        }
        
        cout << c-1 << '\n';
        for(int i = 0; i < v.size(); i++){
            cout << f[i] << " ";
        }
        cout << '\n';
    }    
    
}
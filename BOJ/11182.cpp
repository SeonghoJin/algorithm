#include <iostream>
#include <vector>
using namespace std;

// 작은 수 노드의 위치는 큰 수 노드의 위치 왼쪽 그리고 위에 있다. 

long long N, K, Q;

vector<long long> Arr;

long long p_node(long long n){return (n+K-2)/K;}
long long depth(long long n){
    long long sum = 0;
    long long temp = 1;
    
    for(int i = 0; ; i++){
        sum += temp;
        if(n <= sum){
            return i;
        }
        temp *= K;
    }
    return -1;
}
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    cin >> N >> K >> Q;

    long long sum = 0;
    long long temp = 1;

    for(long long i = 0; i < Q; i++){
        long long len = 0;

        long long a, b;
        cin >> a >> b;
        
        if(a > b)swap(a,b);
        if(K != 1){
        long long dep_a = depth(a);
        long long dep_b = depth(b);
        while(dep_a != dep_b){
            dep_b--;
            b = p_node(b);
            len++;
        }
        
        while(a != b){
            len+=2;
            a = p_node(a);
            b = p_node(b);
        }
        
        cout << len << '\n';
        }
        else{
            cout << b-a << '\n';
        }
    }



}

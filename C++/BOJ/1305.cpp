#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    int sz;
    cin >> sz;
    string str;
    cin >> str;

    vector<int> PI(sz, 0);
    int j = 0;
    for(int i = 1; i < sz; i++){

        while(j > 0 && str[i] != str[j]){
            j = PI[j-1];
        }

        if(str[i] == str[j]){
            PI[i] = ++j;
        }
     }
    
    cout << sz - PI[sz-1];



}
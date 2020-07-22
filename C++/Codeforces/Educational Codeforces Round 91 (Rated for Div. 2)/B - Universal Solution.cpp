#include <bits/stdc++.h>
 
using namespace std;
vector<int> arr[3];
 
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
 
    int T;
    cin >> T;
    while(T--){
        string str;
        cin >> str;
        for(int i = 0; i < 3; i++){
            arr[i].clear();
        }
        for(int i = 0; i < str.size(); i++){
            if(str[i] == 'R'){
                arr[0].push_back(i);
            }
            else if(str[i] == 'S'){
                arr[1].push_back(i);
            }           
            else{
                arr[2].push_back(i);
            }
        }
       
        int len = max({arr[0].size(), arr[1].size(), arr[2].size()});
 
        for(int i = 0; i < 3; i++){
            if(arr[i].size() == len){
                char c;
                if(i == 0){
                    c = 'P';
                }
                else if(i == 1){
                    c = 'R';
                }
                else{
                    c = 'S';
                }
 
                for(int i = 0; i < str.size(); i++){
                    cout << c;
                }
                cout << '\n';
                break;
            }
 
           
        }
    }
}
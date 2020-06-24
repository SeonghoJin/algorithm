#include <bits/stdc++.h>

using namespace std;
int head = 0;
int st[1000010];
char c[1000010];
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    string str;
    string s;

    cin >> str >> s;
    int j = 0;
    st[0] = 0;
    c[0] = ' ';
    int strsz = str.size();
    int ssz = s.size();
    for(int i = 0; i < strsz; i++){
        int j = st[head];
        if(str[i] == s[j]){
            if(j+1 == ssz){
                head -= ssz-1;
            }
            else{
                st[++head] = j+1;
                c[head] = str[i];
            }
        }
        else{
            st[++head] = str[i] == s[0];
            c[head] = str[i];
        }
    }
  
    if(head == 0){
        cout << "FRULA";
    }
    else{
        for(int i = 1; i <= head; i++){
            cout << c[i];
        }
    }
}


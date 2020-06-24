#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    string str;
    string s;

    cin >> str >> s;
    int j = 0;
    stack<pair<int,int>> st;
    st.push({0,-1});
    for(int i = 0; i < str.size(); i++){
        pair<int,int> next = st.top();
        int j = next.first;
        if(str[i] == s[j]){
            if(j+1 == s.size()){
                for(int i = 0; i < s.size()-1; i++){
                    st.pop();
                }
            }
            else{
                st.push({j+1,str[i]});
            }
        }
        else{
            st.push({str[i] == s[0],str[i]});
        }
    }
    string n = "";
    while(!st.empty()){
        n += (char)st.top().second;
        st.pop();
    }
    n.pop_back();
    reverse(n.begin(), n.end());
    
    cout << (n == "" ? "FRULA" : n);
}
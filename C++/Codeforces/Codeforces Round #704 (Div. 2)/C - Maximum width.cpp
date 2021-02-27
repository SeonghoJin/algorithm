#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> f(string s, string t){
    vector<int> result;
    
    int j = 0;
    for(int i = 0; i < s.size(); i++){
        if(j == t.length())break;
        if(s[i] == t[j]){
            result.push_back(i);
            j++;
        }
    }
    return result;
}
 
int main(){
    int a, b;
    cin >> a >> b;
    string s, t;
    cin >> s >> t;
 
    vector<int> left = f(s,t);
    reverse(s.begin(), s.end()), reverse(t.begin(), t.end());
    vector<int> right = f(s,t);
    for(int i = 0; i < right.size(); i++){
        right[i] = s.size() - right[i] - 1;
    }
    reverse(right.begin(), right.end());
    int result = 1;
    for(int i = 1; i < right.size(); i++){
        result = max(result, right[i] - left[i-1]);
    }
    cout << result;
}
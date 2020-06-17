#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
    string a, b;
    cin >> a >> b;
    
    int a_sz = a.size();
    int b_sz = b.size();
    
    if(a_sz < b_sz){
        swap(a_sz,b_sz);
        swap(a,b);
    }
    int temp = 0;
    string ans = "";
    for(int i = 0; i < b_sz; i++){
        int aa = a[a_sz-1-i] - '0';
        int bb = b[b_sz-1-i] - '0';
        int sum = aa+bb+temp;
        ans += '0'+sum%2;
        temp = sum/2;
    }
    
    for(int i = b_sz; i < a_sz; i++){
        int aa = a[a_sz-1-i]-'0';
		int sum = aa + temp;
        ans += '0'+sum%2;
        temp = sum/2;
    }
    if(temp == 1){
        ans += '0'+temp;
    }
    
    reverse(ans.begin(), ans.end());
    bool flag = true;
	for(int i = 0; i < ans.size(); i++){
		if(ans[i] == '1')flag = false;
		if(!flag)cout << ans[i];
	}
	if(flag){
		cout << '0';
	}
    cout << '\n';
    }
}
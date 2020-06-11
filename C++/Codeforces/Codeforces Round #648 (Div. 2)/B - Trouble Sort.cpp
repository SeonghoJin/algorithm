#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
 
	int T;
	cin >> T;
	while(T--){
		int sz;
		cin >> sz;
 
		int value[501];
		int type[501];
		for(int i = 0; i < sz; i++)cin >> value[i];
		for(int i = 0; i < sz; i++)cin >> type[i];
 
		int a = 0;
		int b = 0;
		for(int i = 0; i < sz; i++){
			if(type[i]){
				a++;
			}
			else {b++;}
		}
		if(a > 0 && b > 0){
			cout << "Yes" << '\n';
		}
		else{
			bool flag = true;
			for(int i = 0; i < sz-1; i++){
				if(value[i] > value[i+1]){
					flag = false;
					break;
				}
			}
			cout << (flag ? "Yes" : "No") << '\n';
		}
	}
}
#include <bits/stdc++.h>

using namespace std;

string str;

bool ch = false;


void check(int a){
	
	if(ch)return;
	if(a == str.size()){
		ch = true;
		return;
	}
	int len = str.size();

	for(int i = a; i < len; i++){
		if(str[i] == '1'){
			if(i+3 >= len)return;
			else if(str[i+1] == '0' && str[i+2] == '0'){
				int start = -1;
				for(int j = i+3; j < len; j++){
				if(str[j] == '1'){start = j; break;}
				}
				if(start == -1)return;
				int j;
				for(j = start+1; j < len; j++){
					if(str[j] == '0'){
						check(j);
						if(str[j-2] == '1')check(j-1);
						return;
					}
				}
				if(j == len)return check(j);
			}
			else return;
		}
		else if(str[i] == '0'){
			if(i+1 < len && str[i+1] == '1'){check(i+2); return;}
			else{return;}			
		}
		else return;
	}

}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	int T;
	cin >> T;
	while(T--){
		cin >> str;
		ch = false;
		check(0);
		cout << (ch ? "YES" : "NO") << '\n';
	}

}
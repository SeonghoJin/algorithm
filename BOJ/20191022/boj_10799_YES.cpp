/*
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
vector<int> lazers;
int T[50000];



int main(){
	
	string s;
	cin >> s;
	int cursor = 0;
	int ans = 0;
	for(int i = 0; i < s.size(); i++){
		if(i < s.size()-1 && s[i] == '(' && s[i+1] == ')'){
			T[cursor]++;
			i+=1;
		}
		else if(s[i] == '('){
			cursor++;
		}
		else{
			ans+=(1+T[cursor]);
			T[cursor-1]+=T[cursor];
			T[cursor] = 0;
			cursor--;
		}
			
	}
	cout << ans;
}*/
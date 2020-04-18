#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
	
	
	int N;
	cin >> N;
	cin.ignore();
	while(N--){
		char str[1001];
		char* token;
		cin.getline(str,1001);
		token = strtok(str," ");
		while(token != NULL){
			string s = token;
			for(int i = s.size()-1; i >= 0 ; i--){
				cout << s[i];
			}
			cout << ' ';
			token = strtok(NULL," ");
		}
		
		
	}
	
}
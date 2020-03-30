/*#include <iostream>
#include <string>
using namespace std;


long long atol(const string& s){
	
	long long temp = 0;
	
	for(int i = 0; i < s.size(); i++){
		temp*=10;
		temp+=s[i]-'0';
	}
	
	return temp;
}


int main(){
	
	string s1, s2;
	long long ans = 0;
	cin >> s1 >> s2;
	s1+=s2;
	ans +=(atol(s1));
	cin >> s1 >> s2;
	s1+=s2;
	ans +=(atol(s1));
	
	cout << ans;
}*/
#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;


string plus_s(string s, string k){
	
	std::string TEMP("");
 
  
	int ma = max(s.size(), k.size());
	int s_sz = s.size()-1;
	int k_sz = k.size()-1;
	
	int temp = 0;
	for(int i = 0; i < ma; i++){
		int new_ = temp + (s_sz-i >=0 ? s[s_sz-i] - '0' : 0) + (k_sz - i >= 0 ? k[k_sz-i] - '0'  : 0);
		temp = new_/10;
		new_ = new_%10;
		TEMP+=(char)(new_+'0');
	}
	
	if(temp > 0)TEMP+=(char)(temp+'0');
	std::reverse(TEMP.begin(), TEMP.end());
	
	return  TEMP;
}



int main(){
	
	string s1,s2;
	cin >> s1 >> s2;
	cout << plus_s(s1,s2);
	
}
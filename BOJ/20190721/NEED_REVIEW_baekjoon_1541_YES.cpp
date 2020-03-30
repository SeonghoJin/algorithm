/*
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int v;

int main(){
	string str;
	cin >> str;
	
	v = str.size();
	for(int i = 0; i < str.size(); i++){
		if(str[i] == '-'){v = i; break;}
	}
	string minus;
	string plus = str.substr(0,v);
	if(v+1 < str.size())
	minus = str.substr(v+1,str.size());
	int sum = 0;
	string temp ="";
	
	for(int i = 0;plus.size() > 0 && i <= plus.size(); i++){
		
		
		if(i == plus.size() || plus[i] == '+'){
			sum+=stoi(temp);
			temp = "";
		}
		else{temp+=plus[i];}
		
	}
	
	temp = "";
	
	for(int i = 0; minus.size() > 0 && i <= minus.size(); i++){
		
		
		if(i == minus.size() || minus[i] == '+' || minus[i] == '-'){
			sum-=stoi(temp);
			temp = "";
		}
		else{temp+=minus[i];}
		
	}
	
	cout << sum;
	
}*/
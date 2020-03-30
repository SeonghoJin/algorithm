/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> getPi(const string& str1){
	
	vector<int> pi(str1.size(), 0);
	int j = 0;
	for(int i = 1; i < str1.size(); i++){
		
		while(j > 0 && str1.at(i) != str1.at(j)){
			j = pi[j-1];
		}
		
		if(str1.at(i) == str1.at(j)){
			pi[i] = ++j;
		}
		
	}
	
	return pi;
}

vector<int> KMP(const string& str1,const string& str2){
	
	vector<int> ans;
	vector<int> pi = getPi(str2);
	int j = 0;
	
	for(int i = 0; i < str1.size(); i++){
		
		while(j > 0 && str1.at(i) != str2.at(j)){
			j = pi[j-1];
		}
		
		if(str1.at(i) == str2.at(j)){
			if(j == str2.size()-1){
				ans.push_back(i-j);
				j = pi[j];
			}
			else{
				j++;
			}
		}

	}
	
	return ans;
}

string slice(const string& str1, int t){
	
	string s;
	for(int i = 0; i < t; i++){
		s+=str1.at(i);
	}
	return s;
	
}

int main(){
	string str1;
	string str2;
	getline(cin,str1);
	vector<int> pi = getPi(str1);
	int ret = 0;
	for(int i = 0; i < str1.size()-1; i++){

		vector<int> temp = getPi(str1.substr(i,str1.size()));
		for(int j = 0; j < temp.size(); j++){
			ret = max(ret, temp[j]);
		}
		
			
	}
	
	cout << ret;
}*/
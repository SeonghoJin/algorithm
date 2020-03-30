#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

bool isPelindrom(string& s){
	stack<char> st;
	bool flag = false;
	for(int i = 0; i < s.size(); i++){
		if(s.at(i) == '[' || s.at(i) == '('){st.push(s.at(i)); flag = true;}
		else if(s.at(i) == ']' ){
			if(st.empty())return false;
			else if(st.top() == '[')st.pop();
			else return false;
		}
		else if(s.at(i) == ')'){
			if(st.empty())return false;
			else if(st.top() == '(')st.pop();
			else return false;
		}
	}
	if(!st.empty())return false;
	return true;
}

int main(){
	
	
	string s;
	
	while(1){
	getline(cin,s);
	if(s.at(0) == '.')break;
	if(isPelindrom(s)){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}
	}
	
	
}
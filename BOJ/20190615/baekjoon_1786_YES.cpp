#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getPi(const string& str){
	vector<int> pi(str.size(),0);
	int j = 0;
	
	for(int i = 1; i < str.size(); i++){
		
		while(j > 0 && str[i] != str[j]){
			j = pi[j-1];
		}
		
		if(str[i] == str[j]){
			pi[i] = ++j; 
		}
		
	}
	
	return pi;
	
}

vector<int> KMP(const string& s, const string& p){
	vector<int> ans;
	vector<int> pi = getPi(p);
	int j = 0;
	
	
	for(int i = 0; i < s.size(); i++){
		while(j > 0 && s[i] != p[j]){
			j=pi[j-1];
		}
		
		if(s[i] == p[j]){
			if(j==p.size()-1){
				ans.push_back(i-p.size()+1);
				j=pi[j];
			}else{
			j++;
		}
		}
		
		
	}
	return ans;

}

int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	string str1,str2;
	
	getline(cin,str1);
	getline(cin,str2);
	
	vector<int> ans = KMP(str1,str2);
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i]+1 << '\n';
	}
	
}

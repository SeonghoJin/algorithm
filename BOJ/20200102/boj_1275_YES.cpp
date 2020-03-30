#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool palin_check(string s){
	int sz = s.size();
	
	for(int i = 0; i < sz/2; i++){
		if(s[i] != s[sz-1-i])return false;
	}
	return true;
}

int main(){
	string s;
	cin >> s;
	
	queue<pair<string, pair<int, int>>> q;
	q.push({s,{0,0}});
	int ans = 0;
	while(!q.empty()){
		pair<string, pair<int,int>> temp = q.front(); q.pop();
		
		string str = temp.first;
		bool check  = temp.second.first;
		int depth = temp.second.second;
		cout << str << " " << check << "  " << depth << '\n';
		if(palin_check(str)){
			ans = depth;
			break;
		}
		
		int sz = str.size();
		
		for(int i = 0; i < sz/2; i++){
			int j = sz - 1 - i;
			
			if(str[i] != str[j]){
				string new_s = str;
				char c = str[j];
				new_s.insert(i,str[j].c_str()[j]);
				cout << new_s << '\n';
				q.push({new_s,{check,depth+1}});
				new_s = str.substr(0,j+1) + str[i];
				if(j != sz-1){
					str.substr(j+1,sz-1-j);
				}
				cout << new_s << '\n';
				
				q.push({new_s,{check,depth+1}});
				
				new_s = str;
				new_s.erase(i);
				cout << new_s << '\n';
				
				q.push({new_s, {check, depth+1}});
				new_s = str;
				new_s.erase(j);
				cout << new_s << '\n';
				
				q.push({new_s, {check, depth+1}});
				
				new_s = str;
				new_s[i] = str[j];
				cout << new_s << '\n';
				
				q.push({new_s, {check, depth+1}});
				new_s = str;
				new_s[j] = str[i];
				cout << new_s << '\n';
				
				q.push({new_s, {check, depth+1}});
				break;
			}
		}
	}
	
}
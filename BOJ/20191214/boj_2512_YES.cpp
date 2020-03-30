#include <list>
#include <iostream>

using namespace std;

int main(){
	
    cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int T;
	cin >> T;
	while(T--){
		string str;
		cin >> str;
		
		list<char> li;
		auto cursor = li.begin();
		
		for(int i = 0; i < str.size(); i++){
			char temp = str[i];
			
			switch(temp){
				case '<' :
					if(cursor != li.begin())--cursor;
					break;
				case '>' :
					if(cursor != li.end())++cursor;
					break;
				case '-' :
					if(cursor != li.begin())li.erase((--cursor)++);
					break;
				default :
					li.insert(cursor,temp);
					break;
			}
		}
		
		for(auto it = li.begin(); it != li.end(); it++)cout << *it;
		cout << '\n';
	}
	
	
}
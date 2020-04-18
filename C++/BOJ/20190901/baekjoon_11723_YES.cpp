/*
#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	int answer =0;
	while(N--){
		cout << N << '\n';
		string s1; 
		int s2;
		cin >> s1;
		
		
		
		if(s1 == "add"){cin >> s2; answer = answer | (1 << s2);}
		else if( s1 == "remove"){
			cin >> s2;answer = answer & ~(1 << s2);
		}
		else if( s1 == "check"){cin >> s2;
			int t = ((1 << s2) & answer);
			if(t)cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if( s1 == "toggle"){
			cin >> s2;
			answer ^= (1 << s2) ;
		}
		else if( s1 == "all"){
			answer = (1 << 21) - 1;
		}
		else if( s1 == "empty"){
			answer = 0;
		}
	
		
	}
}
*/
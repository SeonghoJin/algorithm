#include <iostream>
#include <algorithm>

using namespace std;

int Z[1000003], L, R;
int main() {
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
    string s;
	cin >> s;
	
	int sz = s.size();
	

	for(int i = 1; i < sz; i++){
		if(i > R){
			L = R = i;
			while(R < sz && s[R-L] == s[R])R++;
			Z[i] = R-- -L; 
		}
		else{
			if(i - 1 + Z[i - L] < R){
				Z[i] = Z[i - L];
			}
			else{
				L = i;
				while(R < sz && s[R-L] == s[R])R++;
				Z[i] = R-- -L;
			}
		}
	}
	Z[0] = sz;
	for(int i = 0; i < sz; i++){
		cout << Z[i] << " ";
	}
}



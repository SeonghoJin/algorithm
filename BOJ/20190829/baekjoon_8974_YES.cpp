/*
#include <iostream>

using namespace std;

int main(){
	
	int Arr['z'-'a'+1] = {0,};
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		string s;
		cin >> s;
		Arr[s[0]-'a']++;
	}
	bool flag = false;
	for(int i = 0; i < 'z'-'a'+1; i++){
		if(Arr[i] >= 5){cout << (char)(i+'a'); flag = true;}
	}
	
	if(!flag){
		cout << "PREDAJA";
	}
	
	
	
}*/
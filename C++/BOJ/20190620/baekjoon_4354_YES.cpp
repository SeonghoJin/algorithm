/*
#include <iostream>
#include <vector>
#include <string.h>
#include <cstdio>

using namespace std;

char S[1'000'001];
int f[1'000'001];


int main(){
	
	
	
	while(1){
	scanf("%s", S);
		int len = strlen(S);
		if (len == 1 && S[0] == '.')
			break;
		int j = 0;
		for (int i = 1; i < len; i++) {
			while (j > 0 && S[i] != S[j])
				j = f[j - 1];
			if (S[i] == S[j])
				f[i] = ++j;
			else
				f[i] = 0;
		}
	
	int k = len - f[len - 1];
		
	if(len%k==0){
		printf("%d\n",len/k);
	}
	else{
		cout << 1 <<'\n';
	}
	
	}
	
	

}

#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
using namespace std;

char S[1'000'001];
int f[1'000'001];


int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	while(1){
	scanf("%s", S);
		int len = strlen(S);
		if (len == 1 && S[0] == '.')
			break;
		int j = 0;
		for (int i = 1; i < len; i++) {
			while (j > 0 && S[i] != S[j])
				j = f[j - 1];
			if (S[i] == S[j])
				f[i] = ++j;
			else
				f[i] = 0;
		}
	
	int k = len - f[len - 1];
		
	if(len%k==0){
		printf("%d\n",len/k);
	}
	else{
		cout << 1 <<'\n';
	}
	
	}
	
	

}
*/
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 360000;

int s[2*MAX];
int p[MAX];
int pi[MAX];
void getPi(){
	int j = 0;
	for(int i = 1; i < MAX; i++){
		while(j > 0 && p[i] != p[j]){j = pi[j-1];}
		if(p[i] == p[j])pi[i] = ++j;
	}
	
}

bool KMP(){
	
	getPi();
	int j = 0;
	for(int i = 0; i < MAX; i++){
		
		while(j > 0 && s[i] != p[j])j = pi[j-1];
			
		if(s[i] == p[j]){
			j++;
			if(j == MAX){
				return true;
			}		
		}
		
	}
	return false;
}


int main(){
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		s[a]=s[a+MAX]=1;
	}
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		p[a]=1;
	}
	
	cout << (KMP() ? "possible" : "impossible");
}*/
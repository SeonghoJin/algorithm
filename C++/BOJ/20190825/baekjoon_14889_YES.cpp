/*
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int N;
int Arr[21][21];
vector<int> team1;
vector<int> team2;
int answer = 987654321;
void dfs(int number){
	
	
	if(N/2 == team1.size() && N/2 == team2.size()){
		
	
		int power1 = 0;
		int power2 = 0;
		
		for(int i = 0; i < N/2; i++){
			for(int j = 0; j < N/2; j++){
				power1+=Arr[team1[i]][team1[j]];
				power2+=Arr[team2[i]][team2[j]];
			}
		}
		
		if(answer > abs(power1-power2)){
			answer = abs(power1-power2);
		}
		return;
	}
	
	if(N/2 == team1.size()){team2.push_back(number); dfs(number+1); team2.pop_back();}
	else if(N/2 == team2.size()){team1.push_back(number); dfs(number+1); team1.pop_back();}
	else{
		team1.push_back(number); dfs(number+1); team1.pop_back();
		team2.push_back(number); dfs(number+1); team2.pop_back();
	}
	
	
	
}

int main(){
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> Arr[i][j];
		}
	}
	
	dfs(1);
	cout << answer;
}
*/
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 1000000;

string S;
vector<int> pos, SA; 
int d = 1, N;

bool cmp(int i, int j){
	
	if(pos[i] != pos[j])return pos[i] < pos[j];
	i+=d;
	j+=d;
	return (i < N && j < N) ? (pos[i] < pos[j]) : (i > j);
}

int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	getline(cin,S);
	
	N = S.size();
	
	for(int i = 0; i < N; i++){
		SA.push_back(i);
		pos.push_back(S[i]);
	}
	
	for(;;d*=2){
		sort(SA.begin(),SA.end(),cmp);
		int temp[MAX]={0,};
		
		for(int i = 0; i < N-1; i++){
			temp[i+1] = temp[i]+cmp(SA[i],SA[i+1]);
		}
		
		for(int i = 0; i < N; i++){
			pos[SA[i]] = temp[i];
		}
		
		if(temp[N-1] == N-1)break;
	}
	
	vector<int> lcp(N);
	for(int i = 0; i < N; i++){
		cout << pos[i] << " ";
	}
	cout << '\n';
	for(int i = 0, k = 0; i < N; i++, k=max(k-1,0)){
		if(pos[i] == N-1)continue;
		
		for(int j = SA[pos[i]+1]; S[i+k] == S[j+k]; k++);
		cout << pos[i] << k << '\n';
		lcp[pos[i]]=k;
		
	}
	
	for(int i = 0; i < N; i++){
		cout << SA[i] << " ";
	}
	
	cout <<endl<< "x ";
	for(int i = 0; i < N-1; i++){
		cout << lcp[i] << " ";
	}
	
	
	
}
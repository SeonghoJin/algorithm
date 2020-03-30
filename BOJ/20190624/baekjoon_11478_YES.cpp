#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string str;
int N,d=1;
vector<int> sa,pos;

bool cmp(int i, int j){
	
	if(pos[i]!=pos[j])return pos[i] < pos[j];
	i+=d;
	j+=d;
	return i < N && j < N ? pos[i] < pos[j] : i > j;
	
}


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	getline(cin,str);
	
	N = str.size();
	
	for(int i = 0; i < N; i++){
		sa.push_back(i);
		pos.push_back(str[i]);
	}
	
	while(1){
		
		sort(sa.begin(),sa.end(),cmp);
		
		vector<int> temp(N);
		
		for(int i = 0; i < N-1; i++){
			temp[i+1] = temp[i]+cmp(sa[i],sa[i+1]); 
		}
		
		for(int i = 0; i < N; i++){
			pos[sa[i]] = temp[i]; 
		}
		
		if(temp[N-1] == N-1) break;
		d*=2;
	}
	
	vector<int> lcp(N);
	
	int sum = 0;
	
	for(int i = 1; i <= N; sum+=i,i++);
	
	for(int i = 0, k = 0; i < N; i++,k = max(k-1,0)){
		
		if(pos[i] == N-1) continue;
		
		for(int j = sa[pos[i]+1]; str[i+k] == str[j+k]; k++);
		sum-=k;
	}
	cout << sum;

}
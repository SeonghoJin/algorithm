/*
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <stack> 
#include <ctime>
#include <cstdlib>
using namespace std;

int dp[1'000'001] ={0,};
int n, lis[1000004], len, num;
pair<int, int> ans1[1000004];
stack<int> stk; 

int main(){
	srand(time(0));
	vector<int> v;
	
	int N;
	cin >> N;
	n = N;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	cout << '\n';
	vector<int> temp;
	vector<int> temp_idx;
	temp.push_back(-987654321);
	temp_idx.push_back(-1);
	for(int i = 0; i < v.size(); i++){
		
		auto idx = lower_bound(temp.begin(),temp.end(),v[i]);
		
		if(idx == temp.end()){
			dp[i] = temp_idx.back();
			temp.push_back(v[i]);
			temp_idx.push_back(i);
		}
		else{
			dp[i] = temp_idx[idx-temp.begin()-1];
			*idx = v[i];
			temp_idx[idx-temp.begin()] = i;
		}
		
	}
	
	vector<int> ans;
	ans.push_back(temp.back());
	int start = dp[temp_idx.back()];
	
	while(start != -1){
		ans.push_back(v[start]);
		start = dp[start];
	}
	reverse(ans.begin(),ans.end());
	
	for (int i = 0; i < n; i++){
        num = v[i];
		auto lowerPos = lower_bound(lis, lis + len, num);
        int _pos = (int)(lower_bound(lis, lis + len, num) - lis);
        if(*lowerPos == 0) len++;
        *lowerPos = num;  
        ans1[i].first = _pos;
        ans1[i].second = num; 
    }
	printf("%d %d %d \n", len, ans.size(), len == (int)ans.size()); 
    
	for(int i = n - 1; i >= 0; i--){
        if(ans1[i].first == len - 1){
            stk.push(ans1[i].second); len--;
        }
    }
	int k = 0;
    while(stk.size()){
        printf("%d %d %d\n", stk.top(),ans[k++],stk.top()==ans[k]);stk.pop();
    
	} 
	cout << '\n';
	for(int i = 0; i < N; i++){
		cout << i << " " << dp[i] << " " << v[i] << '\n';
	}
	
	
	
	
}


*/



#include <set>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
	
	
	int N;
	scanf("%d", &N);
	
	memset(ans)
	int ans[1001] =;
	
	ans.push_back(0);
	
	for(int i = 0; i < N; i++){
		int k;
		scanf("%d",&k);
		if(k > ans.back()){
			ans.push_back(k);
		}
		else{
			auto it = lower_bound(ans.begin(),ans.end(),k);
			*it = k;
		}
		
	}
	
	int p = 0;
	
	printf("%d",ans.size()-1);
	
	
}
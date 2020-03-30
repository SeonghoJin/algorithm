/*
#include <iostream>
#include <vector>


using namespace std;

int dp[2500];
vector<int> pre[2500];
int sz;

int dfs(int n){
	if(n == sz)return 0;
	
	int& ret = dp[n];
	if(ret != -1)return ret;
	ret = 987654321;
	for(int i = 0; i < pre[n].size(); i++){
		int next = pre[n][i];
		if(pre[n][i]){
			ret = min(ret, 1+dfs(next+1));
		}
	}
	ret = min(ret, 1+dfs(n+1));
	
	return ret;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	string str;
	cin >> str;
	
	sz = str.size();
	
	for(int i = 0; i < sz; i++){
		
		int le = i-1;
		int ri = i+1;
		
		while(le >= 0 && ri <= sz){
			if(str[le] != str[ri])break;
			pre[le--].push_back(ri++);
		}
		
		le = i;
		ri = i+1;
		
		while(le >= 0 && ri <= sz){
			if(str[le] != str[ri])break;
			pre[le--].push_back(ri++);
		}
	}
	
	
	fill(dp, dp+2500, -1);
	
	cout << dfs(0);
	
	
}


#include <cstdio>
#include <cstring>

int main()
{
	char str[2502];
	
	scanf("%s", str+1);
	int len = strlen(str+1);

	int dp[2501] = { 0, };
	int palin[2501] = { 0, };

	for (int i = 1; i <= len; i++)
	{
		dp[i] = 2500;
		for (int j = 1; j <= i ;j++)
		{
			if (str[j] == str[i] && (i - j <= 1 || palin[j + 1]))
			{
				palin[j] = 1;
				if (dp[i] > dp[j - 1] + 1)
					dp[i] = dp[j - 1] + 1;
			}
			else
				palin[j] = 0;
		}
	}
	printf("%d\n", dp[len]);

	return 0;
}
*/
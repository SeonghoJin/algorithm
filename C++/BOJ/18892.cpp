#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
vector<long long> can[502];
vector<long long> incan[502];
vector<vector<long long>> ans;
long long maxlen = 0;
long long dp[502];
long long N;
long long K;
long long sum[502];
vector<long long> tt;

bool compare(long long a,long long b){
	return v[a] < v[b];
}
void f(long long start){
	long long visit[501];
	fill(visit,visit+501, 0);

	queue<long long> q;
	q.push(start);
	
	while(!q.empty()){
		long long here = q.front(); q.pop();
		for(long long next : can[here])
		{
			incan[next].push_back(here);
			//cout << next << " " << here << '\n';
			if(!visit[next])
			{
				visit[next] = 1;
				q.push(next);
			}
		}	
	}

}
void ff(long long start, long long K){
	//cout << start << " " << K << '\n';
	if(start == 501){
		tt.pop_back();
		for(long long i = 0; i < tt.size(); i++){
			cout << tt[i] << " ";
		}
		return;
	}
	
	for(long long i = 0; i < incan[start].size(); i++){
		long long cnt = sum[incan[start][i]];
		if(cnt < K)
		{
			K-=cnt;
		}	
		else{
			
			tt.push_back(v[incan[start][i]]);
			ff(incan[start][i],K);
			return;
		}
	}

}

long long fff(long long start){

	if(start == 501){
		return 1;
	}

	long long& ret = sum[start];

	if(ret != -1)return ret;

	ret = 0;

	for(long long next : incan[start]){
		ret += fff(next);
	}
	return ret;
}
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	cin >> N >> K;
	v.push_back(0);
	for(long long i = 0; i < N; i++){
		long long t; cin >> t;
		v.push_back(t);
	}	
	fill(sum, sum+502, -1);
	for(long long i = 1; i <= N; i++)
	{	
		long long ma = 0;
		for(long long j = 0; j < i; j++) 
		{
			if(v[i] > v[j])
			{
				ma = max(ma, dp[j]);
			}
		}
		dp[i] = ma + 1;
		maxlen = max(maxlen, dp[i]);
		for(long long j = 0; j < i; j++)
		{
			if((dp[i] - 1) == dp[j] && v[i] > v[j])
			{
				can[i].push_back(j);
			}
		}
		
	}
	/*
	for(long long i = 1; i <= N; i++)
	{
		cout << dp[i] << " ";
	}
	cout << '\n';
	
	for(long long i = 1; i <= N; i++)
	{
		for(long long j = 0; j < can[i].size(); j++)
		{
			cout << can[i][j]<< " ";
		}
		cout << '\n';
	}*/
	sum[501] = 1;

	for(long long i = 1; i <= N; i++)
	{
		if(maxlen == dp[i])
		{	
			can[501].push_back(i);
		}
	}

	f(501);
	
	for(long long i = 0; i <= N; i++){
		sort(incan[i].begin(),incan[i].end(),compare);
		/*for(long long j : incan[i])
		{
			cout << j << " ";
		}
		cout << '\n';*/
	}
	fff(0);
	
	/*for(long long i = 0; i <= N; i++){
		cout << sum[i] << " ";
	}*/
	cout << sum[0] << '\n';
	if(sum[0] < K){
		cout << -1;
	}
	else{
		ff(0,K);
	}
	//cout << '\n';
	/*
	for(long long i = 0; i < ans.size(); i++)
	{
		for(long long j : ans[i])
		{
			cout << j << " ";
		}
		cout << '\n';
	}*/

	
	
}
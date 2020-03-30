/*
#include<bits/stdc++.h>
using namespace std;
#define endl	'\n'

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	const int MX=1e5;
	int n,r,q,P[MX],Q[MX],dp[MX];cin>>n>>r>>q;
	vector<int> g[MX];
	for(int i=1;i<n;++i){
		int u,v;cin>>u>>v;
		--u,--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	--r,P[r]=r,Q[0]=r;
	for(int i=0,m=1;i<n;++i){
		int u=Q[i];
		for(int v:g[u])if(v^P[u]){
			cout << "v = " << v+1 << " " << " u = " << u << '\n';
			P[v]=u,Q[m++]=v;
		
		}
	}
	cout << '\n';
	fill(dp,dp+n,1);
	for(int i=n;--i>0;)
		dp[P[Q[i]]]+=dp[Q[i]];
	while(q--){
		int u;cin>>u;
		cout<<dp[u-1]<<endl;
	}
	
	return 0;
}

*/
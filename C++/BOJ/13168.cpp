#include <bits/stdc++.h>

using namespace std;

long long N, startMoney, M;

map<string,map<string,long long>> adj[2];
map<string,map<string,long long>> check[2];
vector<string> cities;
long long trip[201];

long long discount(string str,long long cost){
	if(str == "Mugunghwa" || str == "ITX-Saemaeul" || str == "ITX-Cheongchun"){
		return 0;
	}
	else if(str == "V-Train" || str == "S-Train"){
		return cost/2;
	}
	else{
		return cost;
	}
}

map<string,long long> mapping;
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	cin >> N >> startMoney;
	for(long long i = 0; i < N; i++){
		string str;
		cin >> str;
		cities.push_back(str);
		mapping[str] = i;
	}
	cin >> M;
	for(long long i = 0; i < M; i++){
		string str;
		cin >> str;
		trip[i] = mapping[str];
	}

	long long K;
	cin >> K;
	for(long long i = 0; i < K; i++){
		string s1, s2, s3;
		long long cost;
		cin >> s1 >> s2 >> s3 >> cost;
		if(check[0][s2][s3]){
			adj[0][s2][s3] = min(adj[0][s2][s3],cost);
			adj[0][s3][s2] = min(adj[0][s3][s2],cost);	
		}
		else{
			check[0][s2][s3] = 1;
			adj[0][s2][s3] = cost;
			check[0][s3][s2] = 1;
			adj[0][s3][s2] = cost;
		}
		
		if(check[1][s2][s3]){
			adj[1][s2][s3] = min(adj[1][s2][s3],discount(s1,cost));
			adj[1][s3][s2] = min(adj[1][s3][s2],discount(s1,cost));
		}
		else{
			check[1][s2][s3] = 1;
			adj[1][s2][s3] = discount(s1,cost);
			check[1][s3][s2] = 1;
			adj[1][s3][s2] = discount(s1,cost);
		}
	}

	long long len = cities.size();

	vector<vector<long long>> dp1(len,vector<long long>(len,987654321));
	vector<vector<long long>> dp2(len,vector<long long>(len,987654321));

	for(long long i = 0; i < len; i++){
		for(long long j = 0; j < len; j++){
			if(i == j){dp1[i][i] = 0; dp2[i][i] = 0;}
			else{
				string here = cities[i];
				string next = cities[j];
				if(check[0][here][next]){ 
					dp1[i][j] = adj[0][here][next];
				}
				if(check[1][here][next]){
					dp2[i][j] = adj[1][here][next];
				}
			}
		}
	}
	
	
	for(long long k = 0; k < len; k++){
		for(long long i = 0; i < len; i++){
			for(long long j = 0; j < len; j++){
				if(dp1[i][k] + dp1[k][j] < dp1[i][j]){
					dp1[i][j] = dp1[i][k] + dp1[k][j];
				}
				if(dp2[i][k] + dp2[k][j] < dp2[i][j]){
					dp2[i][j] = dp2[i][k] + dp2[k][j];
				}
			}
		}
	}
	
	long long ans1 = 0;
	long long ans2 = 0;

	for(long long i = 0; i < M-1; i++){
		long long start = trip[i];
		long long end = trip[i+1];
		ans1 += dp1[start][end];
		ans2 += dp2[start][end];
	}
	ans2+=startMoney;
	cout << (ans1 > ans2 ? "Yes" : "No");
		
}
	



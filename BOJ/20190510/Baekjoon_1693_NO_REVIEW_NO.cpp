/*#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

static int N;

static vector<vector<int>> tree(100001,vector<int>());
vector<int> iscolored(100001,0); //0은 색칠 안됨. 0 초과 색칠된 색깔.
queue<int> remain;

static void input(){
	cin >> N;
	
	for(int i = 1; i < N; i++){
		int x,y;
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
		remain.push(i);
	}
	remain.push(N);
}

static int aroundcolored(int N){
	int ret = 0;
	for(int i = 0; i < tree[N].size(); i++){
		if(!iscolored[tree[N][i]])ret++;
	}
	return ret;
	
}

static int whatColorize(int k){
	
	if(tree[k].size()==1)return 1;
	
	int colorvalue = N;
	vector<int> colorcheck(100001,false);
	
	for(int i = 0; i < tree[k].size(); i++){
		colorcheck[iscolored[tree[k][i]]] = true;
	}
				   
	for(int i = 1; i <= N; i++){
		if(!colorcheck[i]) colorvalue=min(colorvalue,i);  
	}			   
	return colorvalue;
	
}

int main(){
	
	int ans = 0;
	input();
	
	while(!remain.empty()){
		
		int Node = remain.front();
		remain.pop();
		
		if(aroundcolored(Node)<=1){
			
			iscolored[Node] = whatColorize(Node);
			ans+=iscolored[Node];
		}
		else{
			remain.push(Node);
		}
	}
	
	cout << ans;

}*/

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> a[100001];      //연결여부
int dp[100001][30];
int type=1;

int dfs(int node,int now,int prev)
{
    if(dp[node][now]!=-1)
    return dp[node][now];
    
    int ret=987654321;
    int tmp=now;
    
    for(int i=0;i<a[node].size();i++)
    {
        int t=a[node][i];
        int q=987654321;
        if(t==prev)
        continue;
        for(int j=1;j<=type;j++)
        {
            if(j!=now)
            q=min(q,dfs(t,j,node));
        }
        tmp+=q;
    }
    ret=min(ret,tmp);
    return dp[node][now]=ret;
    
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int n;
    cin>>n;
    int cnt=1;
    while(type<n)
    {
        type*=2;
        cnt++;
    }
    memset(dp,-1,sizeof(dp));
    for(int tmp;cin>>tmp;)
    {
        int p;
        cin>>p;
        a[tmp].push_back(p);
        a[p].push_back(tmp);
    }
    int ans=987654321;
    for(int i=1;i<=cnt;i++)
    {
        ans=min(ans,dfs(1,i,0));
    }

    cout<<ans<<'\n';
}
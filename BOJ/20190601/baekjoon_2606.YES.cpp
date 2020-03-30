/*#include <iostream>

using namespace std;

int N, M; // N은 컴퓨터의 갯수, M은 컴퓨터간의 연결쌍 갯수   1 <= N <= 100
int connectcomputer[101][101];  //connectcomputer[a][a]의 값은 존재할 수 없으므로 이 값을 a의 방문여부로 사용한다. 
int answer=0;
static void input(){
	cin >> N >> M;
	
	for(int i = 0; i < 101; i++){
		connectcomputer[i][i]=0;
	}
	
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		connectcomputer[a][b]=connectcomputer[b][a]=1;
	}
}

static void dfs(int start){
	connectcomputer[start][start] = 1;
	
	for(int i = 1;  i <= N; i++){
		if(connectcomputer[start][i] == 1 && connectcomputer[i][i] == 0)answer++, dfs(i);
	}
	
}
	


int main(){
	input();
	dfs(1);
	
	cout << answer;
}
*/

/*#include <cstdio>
#include <iostream>

using namespace std;
int par[101];

int root(int x){ return (x==par[x]) ? x : (par[x] = root(par[x]));}

int main()
{
    int n;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    int i;
    for(i=1;i<=n;++i) par[i]=i;
    int a,b;
    for(int i = m; i > 0; i--){
        scanf("%d%d",&a,&b);
        par[root(a)]=root(b);
	}
    int ans=0;
	for(int i = 1; i <= n; i++){
		cout << par[i];
	}
	cout << endl;
    for(i=2; i<=n;++i){
        if(root(1)==root(i)) ++ans;
    }
    printf("%d\n",ans);
    return 0;
}
*/

#include <iostream>

using namespace std;

int par[101];

int findpresent(int i){return par[i]==i ? i : (par[i] = findpresent(par[i])); }
void makeunion(int i, int j){par[findpresent(i)] = findpresent(j);}

int main(){
	
	for(int i = 0; i < 101; i++){
		par[i]=i;
	}
	
	int N,K,a,b;
	
	cin >> N >> K;
	
	for(int i = 0; i < K; i++){
		cin >> a >> b;
		makeunion(a,b);
	}
	int ret = 0;
	for(int i = 2; i <= N; i++){
		if(findpresent(1) == findpresent(i))ret++;
	}
	cout << ret;
	
	
}


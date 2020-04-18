#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int maxlayerfloor = 1;
static void dfs(int start);
vector<vector<int>> layer(10001, vector<int>());
vector<pair<pair<int,int>,pair<int, int>>> binarytree(10001);  //first.first는 행번호 first.second는 열번호 second.first 는 왼쪽 노드, second.second는 오른쪽 노드
int rootNode;
static int N;

static void input(){    
	
	cin >> N;
	
	vector<bool> hasParent(10001,false);
	
	for(int i = 1; i <= N; i++){
		int a,b,c;
		cin >> a >> b >> c;
		
		binarytree[a].second.first=b;
		binarytree[a].second.second=c;
		
		if(b!=-1){
		layer[binarytree[b].first.first].push_back(b);
		hasParent[b]=true;	
		}
		
		if(c!=-1){
		layer[binarytree[c].first.first].push_back(c);
		hasParent[c]=true;
		}
	}
	
	for(int i = 1; i <= N; i++){
		if(!hasParent[i]){
			rootNode = i; 
			break;
		}
	}
	
	
	binarytree[rootNode].first.first = 1; 
	layer[binarytree[rootNode].first.first].push_back(rootNode);
	dfs(rootNode);
		
}

static void dfs(int start){
	
	if(binarytree[start].second.first!=-1){
		binarytree[binarytree[start].second.first].first.first = binarytree[start].first.first+1;
		layer[binarytree[binarytree[start].second.first].first.first].push_back(binarytree[start].second.first);
		maxlayerfloor=max(maxlayerfloor,binarytree[binarytree[start].second.first].first.first);
		dfs(binarytree[start].second.first);
	}
	if(binarytree[start].second.second!=-1){
		binarytree[binarytree[start].second.second].first.first = binarytree[start].first.first+1;	
		layer[binarytree[binarytree[start].second.second].first.first].push_back(binarytree[start].second.second);
		maxlayerfloor=max(maxlayerfloor,binarytree[binarytree[start].second.second].first.first);	
		dfs(binarytree[start].second.second);
	}
	
}

int Index = 1;

static void inOrder(int start){
	
	if(start == -1) return;
	inOrder(binarytree[start].second.first);
	binarytree[start].first.second = Index++;
	inOrder(binarytree[start].second.second);
	
}

/*int main(){
	input();
	inOrder(rootNode);
	int maxwidth=-987654321;
	int maxa=-987654321;
	

	
	
	for(int i = 1 ; i <= maxlayerfloor; i++){
		
		int minv=987654321,maxv=-987654321;
		
		for(int j = 0; j < layer[i].size(); j++){
			int t=binarytree[layer[i][j]].first.second;
			minv=min(minv,t);
			maxv=max(maxv,t);	
		}
		if(maxv-minv+1 > maxwidth){
			maxa = i;
			maxwidth = maxv-minv+1;
		}
	}	
	cout << maxa  << " " << maxwidth;
	
}

#include <cstdio>
#include <cstring>
#include <vector>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;

pii lr[10001];
vector<pii> node(10001);
int pos = 1;

inline int readInt() {
	int sum = 0;
	bool flg = 1;
	char now = getchar();

	while (now == 10 || now == 32) now = getchar();
	if (now == '-') flg = 0, now = getchar();
	while (now >= 48 && now <= 57) {
		sum = sum * 10 + now - 48;
		now = getchar();
	}

	return flg ? sum : -sum;
}
void go(int x, int lv) {
	if (node[x].X != -1) go(node[x].X, lv + 1);

	if (lr[lv].X == 0) lr[lv].X = lr[lv].Y = pos++;
	else lr[lv].Y = pos++;

	if (node[x].Y != -1) go(node[x].Y, lv + 1);
}
int main() {
	int n = readInt();

	int pa[10001]{};
	for (int i = 0; i < n; ++i) {
		int a = readInt(), b = readInt(), c = readInt();
		node[a] = { b, c };
		
		if (b != -1) pa[b] = a;
		if (c != -1) pa[c] = a;
	}

	int root = -1;
	for (int i = 1; i <= n; ++i)
		if (pa[i] == 0) {
			root = i;
			break;
		}

	go(root, 1);

	int width = 0, lv = -1;
	for (int i = 1; lr[i].X; ++i) {
		int w = lr[i].Y - lr[i].X + 1;

		if (width < w) {
			width = w;
			lv = i;
		}
	}

	printf("%d %d", lv, width);

	return 0;
}*/
/*#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int N,M;

vector<vector<int>> computer(10001,vector<int>(1,0));
vector<int> ans;
int ma = 0;
void Algorithm(int root){
	
	vector<int> isvisit(10001,0);
	
	queue<int> t;
	t.push(root);
	int ret = 0;
	
	while(!t.empty()){
		ret++;
		int k = t.front();
		t.pop();
		isvisit[k] = 1;
		
		for(int i = 1; i < computer[k].size(); i++){
			if(!isvisit[computer[k][i]])t.push(computer[k][i]);
		}
	}
	
	computer[root][0] = ret;
	ma = max(ma,ret);
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	
	for(int i = 0; i < M; i++){
		int a,b;
		cin >> a >> b;
		computer[b].push_back(a);
	}
	
	for(int i = 1; i <= N; i++){
		if(computer[i].size()!=1)Algorithm(i);
	}
	
	for(int i = 1; i < N; i++){
		if(computer[i][0]==ma)ans.push_back(i);
	}
	
	sort(ans.begin(),ans.end());
	
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	
}


#include <cstdio>
#include <list>
#include <bitset>

const int maxN = 10000;

typedef std::list<int> IntList;
typedef std::bitset<maxN+1> IntSet;

IntList truster[maxN+1];
IntSet s[maxN+1];
int level[maxN+1];
int path[maxN+1];
int ancestor[maxN+1];
int res[maxN];

void dfs(int v, int lvl, int &loopLvl) {
    loopLvl = lvl;

    if (level[v] > 0) { // visited
        int a = v;
        while (ancestor[a]) a = ancestor[a];
        if (level[a] < lvl && path[level[a]] == a) loopLvl = level[a];
        return;
    }

    path[lvl] = v;
    level[v] = lvl;
    for (auto it=truster[v].begin(); it!=truster[v].end(); it++) {
        int child = *it, t;
        dfs(child, lvl+1, t);
        if (t < loopLvl) loopLvl = t;
        if (t > lvl) {
            int a = child;
            while (ancestor[a]) a = ancestor[a];
            s[v] |= s[a];
        }
    }

    s[v][v] = true;
    if (loopLvl < lvl) {
        int a = path[loopLvl];
        ancestor[v] = a;
        s[a] |= s[v];
    }
    return;
}

main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i=0; i<M; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        truster[v2].push_back(v1);
    }

    for (int i=1; i<=N; i++) {
        if (level[i]) continue;

        int dummy;
        dfs(i, 1, dummy);
    }

    int max = 0, idx = 0;
    for (int i=1; i<=N; i++) {
        int j = i;
        while (ancestor[j]) j = ancestor[j];
        int cnt = s[j].count();
        if (cnt > max) {
            max = cnt;
            idx = 0;
        }
        if (cnt == max) res[idx++] = i;
    }
    for (int i=0; i<idx; i++) printf("%d ", res[i]);
    putchar('\n');
}
*/

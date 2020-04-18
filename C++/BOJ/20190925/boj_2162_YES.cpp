#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pll = pair<long long , long long>;
using line = pair<pll, pll>;
int parent[3001];
int _count[3001];
int num;
int ans = 1;
int isParent(int i){return i == parent[i] ? i : parent[i] = isParent(parent[i]);}
bool isUnion(int i, int j){return isParent(i) == isParent(j);}
void Union(int i, int j){
	if(isUnion(i,j))return;
	_count[isParent(j)] += _count[isParent(i)];
	parent[isParent(i)] = isParent(j);
	num--;
	ans = max(ans,_count[isParent(j)]);
}

int ccw(pll a, pll b, pll c){
	
	long long p = (b.first - a.first)*(c.second - a.second) - (c.first - a.first)*(b.second - a.second);
	return p == 0 ? 0 : p < 0 ? -1 : 1;
}

bool isintersect(line a, line b){
	pll x1 = a.first;
	pll x2 = a.second;
	pll y1 = b.first;
	pll y2 = b.second;
	
	int d1 = ccw(x1, x2, y1) * ccw(x1, x2, y2);
	int d2 = ccw(y1, y2, x1) * ccw(y1, y2, x2);
	if (!d1 && !d2) {
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		return y1 <= x2 && y2 >= x1;
	}
	else return d1 <= 0 && d2 <= 0;	
	
}

int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	

	int N;
	cin >> N;
	num = N;
	vector<line> lines;
	for(int i = 0; i < N; i++){
		parent[i] = i;
		_count[i] = 1;
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		lines.push_back({{a,b},{c,d}});
	}
	
	for(int i = 0; i < N; i++)
		for(int j = i+1; j < N; j++)
			if(isintersect(lines[i],lines[j]))Union(i,j);
	
	
	
	cout << num << '\n' << ans;
	
}
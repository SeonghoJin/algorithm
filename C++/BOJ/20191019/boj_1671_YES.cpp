#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 105;
struct shark{
	int h;
	int s;
	int it;
};


bool operator <(const shark& a, const shark& b){
		if(a.h <= b.h && a.s <= b.s && a.it <= b.it)return true;
		return false;
	}


bool cmp(const shark& a, const shark& b){
	return a.h != b.h ? a.h <= b.h : a.s != b.s ? a.s <= b.s : a.it <= b.it;
}

int N, visit[MAX], matched[MAX];
shark sharks[MAX];
vector<int> canEat[102];

int dfs(int n){
	if(visit[n])return 0;
	visit[n] = 1;
	
	for(int i = 0; i < canEat[n].size(); i++){
		int next = canEat[n][i];
		if(matched[next] == 0 || dfs(matched[next])){
			matched[next] = n;
			return 1;
		}
	}
	
	return 0;
}

void precalc(){ // 정렬된 상태에서만 가능.
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j < i; j++){
			if(sharks[j] < sharks[i]){
				canEat[i].push_back(j);
			}
		}
	}
	
}


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> sharks[i].h >> sharks[i].s >> sharks[i].it;
	}
	
	sort(sharks, sharks+N+1, cmp);
	precalc();
	int ans = 0;
	
	
	/*for(int i = 1; i < 2*N; i++){
		cout << i << "는 ";
		for(int j = 0; j < canEat[i].size(); j++)
			cout << canEat[i][j]<< " ";
		
		cout << "먹을 수 있다." << '\n';
	}*/
	for(int i = 1; i <= 2*N; i++){
		fill(visit, visit+MAX, 0);
		if(dfs(i))ans++;
	}

	cout << N - ans;
}


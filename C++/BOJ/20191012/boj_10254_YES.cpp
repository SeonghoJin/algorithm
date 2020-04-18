
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using pii = pair<int, int>;

int N;

pii dots[200000];
int s[200000];
int cnt = 0;
int ccw(pii A, pii B, pii C){
	pii new_A = {B.first-A.first, B.second-A.second};
	pii new_B = {C.first-A.first, C.second-A.second};
	
	long long k = 1LL * new_A.first * new_B.second - 1LL * new_B.first * new_A.second;
	return k < 0 ? -1 : k > 0;
}

bool cmp(pii& A, pii& B){
	int k = ccw(dots[0],A,B);
	return k != 0 ? k > 0 : A.first != B.first ? A.first < B.first : A.second < B.second;
}

long long Dist(pii x, pii y){
	return pow(x.first-y.first,2)+pow(x.second-y.second,2);
}


int main(){
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--){
	cin >> N;	
	cnt = 0;
	for(int i = 0; i < N; i++){
		int a,b;
		cin >> a >> b;
		dots[i] = {a,b};
	}
	
	swap(dots[0], *min_element(dots,dots+N));
	sort(dots+1,dots+N,cmp);
	
	for(int i = 0; i < N; i++){
		while(cnt >= 2 && ccw(dots[s[cnt-2]],dots[s[cnt-1]],dots[i]) <= 0)cnt--;
		s[cnt++] = i;
	}
	
	long long maxDist = 0; 
	int  a1=0, a2=0, a3=0, a4=0; 
	int j = 1; 
	
	for(int i=0; i < cnt; i++) {
		int i_next = (i+1) % cnt;
		for(;;) {
			int j_next = (j+1) % cnt; 
			long bx = dots[s[i_next]].first - dots[s[i]].first; 
			long by = dots[s[i_next]].second - dots[s[i]].second; 
			long cx = dots[s[j_next]].first - dots[s[j]].first;
			long cy = dots[s[j_next]].second -dots[s[j]].second; 
			if(ccw({0, 0}, {bx, by}, {cx, cy}) > 0) j = j_next; else break; 
		} 
		long long dist = Dist(dots[s[i]], dots[s[j]]); 
		if(dist > maxDist) {
			maxDist = dist;
			a1 = dots[s[i]].first;
			a2 = dots[s[i]].second;
			a3 = dots[s[j]].first;
			a4 = dots[s[j]].second; 
		} 
	}
	cout << a1 << " " << a2 << " " << a3 << " " << a4 << '\n';
	}
}

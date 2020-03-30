
#include <iostream>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int N;

pii dots[100000];
int s[100000];
int cnt = 0;
int ccw(pii& A, pii& B, pii& C){
	pii new_A = {B.first-A.first, B.second-A.second};
	pii new_B = {C.first-A.first, C.second-A.second};
	
	long long k = 1LL * new_A.first * new_B.second - 1LL * new_B.first * new_A.second;
	return k < 0 ? -1 : k > 0;
}

bool cmp(pii& A, pii& B){
	int k = ccw(dots[0],A,B);
	return k != 0 ? k > 0 : A.first != B.first ? A.first < B.first : A.second < B.second;
}


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> N;
	
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
	
	cout << cnt;
	
}

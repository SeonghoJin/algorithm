#include <iostream>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

pii dots[20000];
int idx[20000];
int ccw(pii a, pii b, pii c){
	long long k = 1LL * (b.first - a.first) * (c.second - a.second) - 1LL * (b.second - a.second) * (c.first - a.first);
	return k < 0 ? -1 : k > 0;
}

long long lccw(pii a, pii b, pii c){
	return 1LL * (b.first - a.first) * (c.second - a.second) - 1LL * (b.second - a.second) * (c.first - a.first);
}

bool ncmp(int i, int j){
	return dots[i].first != dots[j].first ? dots[i].first < dots[j].first : dots[i].second < dots[j].second;
}

bool cmp(int i, int j){
	pii a = dots[i];
	pii b = dots[j];
	int k = ccw(dots[idx[0]],a,b);
	return k != 0 ? k > 0 : a.first != b.first ? a.first < b.first : a.second < b.second;  
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int T;
	cin >> T;
	
	while(T--){
		int N;
		cin >> N;
		for(int i = 0; i < N; i++){
			cin >> dots[i].first >> dots[i].second;
			idx[i] = i;
		}
		
		sort(idx,idx+N,ncmp);
		sort(idx+1,idx+N,cmp);
		
		int cnt = 0;
		int end;
		for(int i = 1; i < N-1; i++){
			if(lccw(dots[idx[0]],dots[idx[i]],dots[idx[i+1]]) != 0){end = i;
				if(i-cnt != 1 && cnt){reverse(idx+(i-cnt), idx+i+1);}
			cnt = 0;
			}
			if(lccw(dots[idx[0]],dots[idx[i]],dots[idx[i+1]]) == 0){cnt++;}
		}
		if(cnt){reverse(idx+N-1-cnt,idx+N);}
		
		for(int i = 0; i < N; i++){	
			cout << idx[i] << " ";
		}
		cout << '\n';
	}
	
}
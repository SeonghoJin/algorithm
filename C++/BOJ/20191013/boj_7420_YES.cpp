/*#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using pii = pair<int, int>;
const double PI = 3.1415926535;
const int MAX = 1000;
int N, L, cnt = 0;

int s[MAX];
pii n[MAX];

int ccw(pii a, pii b, pii c){
	long long temp = 1LL * (b.first-a.first)*(c.second-a.second) - 1LL * (b.second-a.second)*(c.first-a.first);
	return temp < 0 ? -1 : temp > 0;
}

bool cmp(pii a, pii b){
	int k = ccw(n[0],a,b);
	return k != 0 ? k > 0 : a.first != b.first ? a.first < b.first : a.second < b.second;
}

double dist(pii a, pii b){
	long long dx = a.first-b.first;
	long long dy = a.second-b.second;
	return sqrt(dx*dx+dy*dy);
}

double findangle(pii a, pii b){
	long long t = a.first*b.first + a.second*b.second;
	dou norm_a = dist({0,0},a);
	long long norm_b = dist({0,0},b);
	double k = sqrt( 1.0*t/norm_a/norm_b);
	return acos(k);
}

long long dot(pii a, pii b){ //백터 내적
	return a.first*b.first + a.second*b.second;
}


int main(){
	
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N >> L;
	
	for(int i = 0; i < N; i++)cin >> n[i].first >> n[i].second;
	
	sort(n,n+N);
	sort(n+1,n+N,cmp);
	
	for(int i = 0; i < N; i++){	
		while(cnt >= 2 && ccw(n[s[cnt-2]], n[s[cnt-1]], n[i]) <= 0)cnt--;
		s[cnt++] = i;
	}
	
	double ans = 0;
	
	for(int i = 0; i < cnt; i++){
		int j = (i+1)%cnt;
		ans+=dist(n[s[i]],n[s[j]]);
	}
	
	double all_angle = 0;
	
	for(int i = 0; i < cnt; i++){
		pii before = n[s[(i+cnt-1)%cnt]], cur = n[s[i]], next = n[s[(i+1)%cnt]];
		double dist1 = dist(before,cur);
		double dist2 = dist(cur,next);
		long long inner = dot({before.first - cur.first, before.second-cur.second},{next.first - cur.first, next.second-cur.second});
		ans += (PI-(acos(1.0*inner/dist1/dist2)))*L;
	}
	cout << (int)(ans+0.5);
	
}

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using pii = pair<int, int>;
const double PI = 3.1415926535;
const int MAX = 1000;
int N, L, cnt = 0;

int s[MAX];
pii n[MAX];

int ccw(pii a, pii b, pii c){
	long long temp = 1LL * (b.first-a.first)*(c.second-a.second) - 1LL * (b.second-a.second)*(c.first-a.first);
	return temp < 0 ? -1 : temp > 0;
}

bool cmp(pii a, pii b){
	int k = ccw(n[0],a,b);
	return k != 0 ? k > 0 : a.first != b.first ? a.first < b.first : a.second < b.second;
}

double dist(pii a, pii b){
	long long dx = a.first-b.first;
	long long dy = a.second-b.second;
	return sqrt(dx*dx+dy*dy);
}

double findangle(pii a, pii b){
	long long t = a.first*b.first + a.second*b.second;
	double norm_a = dist({0,0},a);
	double norm_b = dist({0,0},b);
	double k = 1.0*t/norm_a/norm_b;
	return acos(k);
}

int main(){
	
	
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N >> L;
	
	for(int i = 0; i < N; i++)cin >> n[i].first >> n[i].second;
	
	sort(n,n+N);
	sort(n+1,n+N,cmp);
	
	for(int i = 0; i < N; i++){	
		while(cnt >= 2 && ccw(n[s[cnt-2]], n[s[cnt-1]], n[i]) <= 0)cnt--;
		s[cnt++] = i;
	}
	
	double ans = 0;
	
	for(int i = 0; i < cnt; i++){
		int j = (i+1)%cnt;
		ans+=dist(n[s[i]],n[s[j]]);
	}
	
	double all_angle = 0;
	
	for(int i = 0; i < cnt; i++){
		int before = (i+cnt-1)%cnt, next = (i+1)%cnt;
		pii new_A = {n[s[before]].first - n[s[i]].first, n[s[before]].second -n[s[i]].second};
		pii new_B = {n[s[next]].first - n[s[i]].first, n[s[next]].second-n[s[i]].second};
		ans+=(PI-findangle(new_A,new_B))*L;
	}
	cout << (int)(ans+0.5);
	
}*/
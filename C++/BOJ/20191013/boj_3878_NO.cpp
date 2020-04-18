#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vpii = vector<pair<int, int>>;
using pii = pair<int, int>;

const int MAX = 100000;
pii dots[MAX];

int ccw(pii x,pii a, pii b){
	long long k = 1LL*(a.first-x.first)*(b.second-x.second)-1LL*(a.second-x.second)*(b.first-x.first);
	return k < 0 ? -1 : k > 0;
}

bool cmp(pii a, pii b){
	int k = ccw(dots[0],a,b);
	return k != 0 ? k > 0 : a.first != b.first ? a.first < b.first : a.second < b.second;
}

vpii* scan(int N){
	sort(dots,dots+N);
	sort(dots+1,dots+N,cmp);

	int cnt = 0;
	vpii s(N);
	
	for(int i = 0; i < N; i++){
		while(cnt >= 2 && ccw(s[cnt-2],s[cnt-1],dots[i]) <= 0)cnt--;
		s[cnt++] = dots[i];
	}
	
	return new vpii(s.begin(),s.begin()+cnt);
}

bool intersection(pair<pii,pii> line1, pair<pii,pii> line2){
	int a = ccw(line1.first,line1.second,line2.first);
	int b = ccw(line1.first,line1.second,line2.second);
	int c = ccw(line2.first,line2.second,line1.first);
	int d = ccw(line2.first,line2.second,line1.second);
	
	if(a*b == 0 && c*d == 0){
		if(line1.first > line1.second)swap(line1.first,line1.second);
		if(line2.first > line2.second)swap(line2.first,line2.second);
		
		return line2.first <= line1.second && line1.first <= line2.second;
	}
	
	return a*b <= 0 && c*d <= 0;
}

bool isInside(pii B, vpii& p){
//crosses는 점q와 오른쪽 반직선과 다각형과의 교점의 개수
int crosses = 0;
for(int i = 0 ; i < p.size() ; i++){
int j = (i+1)%p.size();
//점 B가 선분 (p[i], p[j])의 y좌표 사이에 있음
if((p[i].second >= B.second) != (p[j].second >= B.second) ){
//atX는 점 B를 지나는 수평선과 선분 (p[i], p[j])의 교점
double atX = (p[j].first- p[i].first)*(B.second-p[i].second)/(p[j].second-p[i].second)+p[i].first;
//atX가 오른쪽 반직선과의 교점이 맞으면 교점의 개수를 증가시킨다.
if(B.first <= atX)
crosses++;
}
}
return crosses % 2 > 0;
}


bool check(vpii& cv1, vpii& cv2){
	for(int i = 0; i < cv1.size(); i++){
			int i_next = (i+1)%cv1.size();
			for(int j = 0; j < cv2.size(); j++){
				int j_next = (j+1)%cv2.size();
				if(intersection({cv1[i],cv1[i_next]},{cv2[j],cv2[j_next]})){return false;}
			}	
		}
	
	int j = 0;
	int crossed = 0;
	for(int i = 0; i < cv1.size(); i++){
		int i_next = (i+1)%cv1.size();
		
		int dx = cv2[j].first;
		int dy = cv2[j].second;
		
		
		
	}
	
	

	
	
	
	return false;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int T;
	cin >> T;
	while(T--){
		int N, M;
		cin >> N >> M;
		for(int i = 0; i < N; i++)cin >> dots[i].first >> dots[i].second;
		vpii& cv1 = *scan(N);
		for(int i = 0; i < M; i++)cin >> dots[i].first >> dots[i].second;
		vpii& cv2 = *scan(M);
		
		
		/*cout << (check(cv1,cv2) ? "YES" : "NO") << '\n';*/
	}
	
	
}
/*#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;
using point = pair<int, int>;
vector<point> Points; 
point standard;

static void input(){
	int N;
	cin >> N; 
	
	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		Points.push_back(make_pair(a,b));
	}
	
}

double findangle(point a){
	int ax = (a.first - standard.first);
	int ay = (a.second - standard.second);
	double a_angle = atan2(ay,ax);
	a_angle *=(double)180/3.141592;
	return a_angle;
}
bool cmpdot(point a, point b){
	if(a.second < b.second) return true;
	if(a.second == b.second) return a.first < b.first;
	return false;
}

bool cmp(point a, point b){
	double a_angle = findangle(a);
	double b_angle = findangle(b);
	
	if(a_angle < b_angle)return true;
	if(a_angle - b_angle < 0.0000001)return cmpdot(a,b);
	return false;
}


long long ccw(point a, point b, point c){
	
	long long t = 1LL*a.first * b.second + 1LL*b.first * c.second + 1LL*c.first * a.second;
	long long p = 1LL*b.first * a.second + 1LL*c.first * b.second + 1LL*a.first * c.second;
	return t-p;
}


static stack<point>& GrahamScan(vector<point>& Points){
	stack<point>* tconvexhullpoints = new stack<point>(); 
	
	sort(Points.begin(), Points.end(), cmpdot);
	standard = Points[0];
	sort(Points.begin()+1, Points.end(), cmp);
	
	tconvexhullpoints->push(Points[0]);
	tconvexhullpoints->push(Points[1]);
	
	for(int i = 2; i < Points.size(); i++){
		while(tconvexhullpoints->size() >= 2){
			
			point first,second,next;
			second = tconvexhullpoints->top();
			tconvexhullpoints->pop();
			first = tconvexhullpoints->top();
			next = Points[i];
			
			if(ccw(first,second,next) > 0){
				tconvexhullpoints->push(second);
				break;
			}
		}
			
		tconvexhullpoints->push(Points[i]);
		
	}
	
	
	return *tconvexhullpoints;
}

*/



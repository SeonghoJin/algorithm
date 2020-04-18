#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double stx;
double sty;
vector<pair<double,double>> v;
double ccw(double x1, double y1, double x2, double y2, double x3, double y3){
	double a = x1*y2 + x2*y3 + x3*y1;
	double b = x2*y1 + x3*y2 + x1*y3;
	
	return a - b;
}

double len(double x1,double y1, double x2, double y2){return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);}


bool cmp(pair<double,double> a, pair<double,double> b){
	double t = ccw(stx,sty,a.first,a.second,b.first,b.second);
	double c = len(stx,sty,a.first,a.second);
	double d = len(stx,sty,b.first,b.second);
	return t == 0 ?  (a.first == b.first ? a.second > b.second : c < d ) : t > 0 ? 1 : 0; 
}

int main(){
	cin.tie(0);
    ios_base :: sync_with_stdio(0);
    int N;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		double x, y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	stx = v[0].first;
	sty = v[0].second;

	long double sum = 0;
	
	for(int i = 1; i < N-1; i++){
		sum+=ccw(stx,sty,v[i].first,v[i].second,v[i+1].first,v[i+1].second)/2;
	}
	cout.precision(1);
	cout << fixed;
	cout << abs(sum);
	
}

#include <iostream>
#include <cmath>

using namespace std;

int ccw(long long x1,long long y1, long long x2, long long y2, long long x3, long long y3){
	
	long long x_1 = x2 - x1, y_1 = y2 - y1;
	long long x_2 = x3 - x1, y_2 = y3 - y1;
	long long p = x_1 * y_2 - x_2 * y_1;
	return p == 0 ? 0 : p > 0 ? 1 : -1;
	
}

int main(){
	
	long long x1,y1,x2,y2;
	long long x3,y3,x4,y4;
	
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	
	bool flag = ccw(x1,y1,x2,y2,x3,y3)*ccw(x1,y1,x2,y2,x4,y4) < 0 && ccw(x3,y3,x4,y4,x1,y1)*ccw(x3,y3,x4,y4,x2,y2) < 0;
	
	cout << flag;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c, d, e ,f;
	cin >> a >> b >> c >> d >> e >> f;
	int answer = 0;
	int length = 0;
	length += f*6;
	length += e*5;
	a = max(0, a-e*5);
	length += d*4;
	
	
	
	if(c%2 == 1)length += 3;

}

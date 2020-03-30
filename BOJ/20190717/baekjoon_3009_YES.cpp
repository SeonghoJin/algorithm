#include <iostream>
#include <cmath>
using namespace std;

/*
int main(){
	
	
	int T;
	cin >> T;
	while(T--){
		int x1,y1,r1,x2,y2,r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double length = sqrt(pow((x1-x2),2)+pow((y1-y2),2));
		double r1_r2 = r1+r2;
		int max_r = max(r1,r2);
		int min_r = min(r1,r2);
		
		if(length == 0 && min_r == max_r){
			cout << "-1" << '\n';
		}
		else if(r1_r2 > length){
			if(length+min_r > max_r){
				cout << "2"<< '\n';
			}
			else if(length+min_r == max_r){
			cout << "1"<< '\n';
			}
			else if(length+min_r < max_r){
			cout << "0"<< '\n';
			}	
			else {cout << "2"<< '\n';}
		}
		else if(r1_r2 == length){
			cout << "1"<< '\n';
		}
		else if(r1_r2 < length){
			cout << "0"<< '\n';
		}
		
	}
	
}*/
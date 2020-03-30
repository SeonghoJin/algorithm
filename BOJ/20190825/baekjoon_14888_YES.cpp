/*
#include <iostream>
#include <cmath>
#include <deque>

using namespace std;

int operators[4];
int ma = -2123456789;
int mi = 2123456789;

deque<int> dq;

void dfs(){
	
	
	
	int flag = 0;
	for(; flag < 4; flag++){
		if(operators[flag]!=0)break;
	}
	
	if(flag == 4){
		ma = max(ma,dq.front());
		mi = min(mi,dq.front());
		return;
	}
	
	
	for(int i = 0; i < 4; i++){
		if(operators[i] != 0){
			int operand1 = dq.front(); dq.pop_front();
			int operand2 = dq.front(); dq.pop_front();
			operators[i]--;
			int operand3;
			switch(i){
				case 0:
					operand3 = operand1+operand2;
					break;
				case 1:
					operand3 = operand1-operand2;
					break;
				case 2:
					operand3 = operand1*operand2;
					break;
				case 3:
					operand3 = operand1/operand2;
					break;
			}
			dq.push_front(operand3);
			dfs();
			operators[i]++;
			dq.pop_front();
			dq.push_front(operand2);
			dq.push_front(operand1);
		}
	}
	
	
}



int main(){
	
	int N;
	cin >> N;
	
	
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		dq.push_back(a);
	}
	
	for(int i = 0; i < 4; i++){
		cin >> operators[i];
	}
	
	dfs();
	
	cout << ma << '\n';
	cout << mi << '\n';
	
}
*/
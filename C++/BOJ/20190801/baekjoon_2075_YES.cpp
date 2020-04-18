/*
#include <iostream>
#include <queue>

using namespace std;

int main(){
	int N;
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> N;
	priority_queue<int> t;
	int num = 0;
	int k = N*(N-1);
	
	for(register int i = 0; i < N * N; i++){
		int p;
		cin >> p;
		t.push(-p);
		if(t.size() == 10000){
			t.pop();
			num++;
		}
		if(num == k){break;}
	}
	
	while(num < k){
		t.pop();
		num++;
	}
	
	cout << -t.top() << endl;
	
}
*/

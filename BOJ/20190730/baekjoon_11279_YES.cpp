/*https://stackoverflow.com/questions/4600295/what-is-the-meaning-of-operator-bool-const*/
/*
참고

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct cmp{
	 bool operator()(int t,int u){
		return abs(t) != abs(u) ? abs(t) > abs(u) : t > u;
        
    }
	
};



int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int N;
	priority_queue<int,vector<int>,cmp> pq;
	
	cin >> N;
	
	while(N--){
		int ans;
		cin >> ans;
		if(ans == 0){
			if(pq.empty()){
				cout << "0" << '\n';
			}
			else{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else{
			pq.push(ans);
		}
	}
	
	
}*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

static int Arr[100001]; // [0]은 부모, [1]은 루트에서와 자신의 거리
static int N;
queue<pair<int,int>> store;


static void input(){
	
	
	cin >> N;
	Arr[1]=1;
	
	for(int i = 0; i < N-1; i++){
		int a, b;
		cin >> a >> b;
		if(Arr[a]==0 && Arr[b]==0){
			store.push(make_pair(a,b));
		}
		else{
		if(Arr[a]==0)Arr[a]=b;
		else Arr[b]=a;
		}
	}
	
	while(!store.empty()){
		
		int a = store.front().first;
		int b = store.front().second;
		store.pop();
		if(Arr[a]==0 && Arr[b]==0){
			store.push(make_pair(a,b));
		}
		else{
		if(Arr[a]==0)Arr[a]=b;
		else Arr[b]=a;
		}
	}
}


int main(){
	
	input();
	
	for(int i = 2; i <=N; i++){
		cout << Arr[i] << '\n';
	}
}
/*
#include <iostream>


using namespace std;
int Arr[100001];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, M;
	
	cin >> N >> M;
	
	cin >> Arr[1];
	
	for(int i = 2; i <= N; i++){
		cin >> Arr[i];
		Arr[i] +=Arr[i-1];
	}
	
	while(M--){
		int a,b;
		cin >> a >> b;
		cout << Arr[b] - Arr[a-1]<< "\n";
	}
	
	
	
}
*/
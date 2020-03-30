#include <iostream>

using namespace std;

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int T;
	cin >> T;
	
	while(T--){
		int N, M;
		cin >> N >> M;
		
		int answer = 0;
		
		for(int i = 1; i < N; i++)
			for(int j = i+1; j < N; j++){
				int t = i*i+j*j+M;
				int k = i*j;
				if(t%k == 0)answer++;
			}
		cout << answer << '\n';
	}
}
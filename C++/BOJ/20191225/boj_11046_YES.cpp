
/*#include <iostream>

using namespace std;
int N, M;
const int MAX_N = 100'0001 * 2;

int A[MAX_N];
int Arr[MAX_N];
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N;
	for(int i = 0; i < N; i++)cin >> Arr[2*i+1];
	
	int l = 0, s = 0;
	
	for(int i = 0; i <= 2*N; i++){
		int m_i = 2*s - i;
		
		A[i] = (i <= l ? min(A[m_i],l-i) : 0);
		
		while(i-A[i]-1 >= 0 && i + A[i] + 1 <= 2*N && Arr[i-A[i]-1] == Arr[i+A[i]+1])A[i]++;
		
		if(i + A[i] > l){
			l = i+A[i];
			s = i;
		}
		
	}

	cin >> M;
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if((b - a + 1) & 1){
			int t = (a + b)/2;
			int l = 2*t - 2*a;
			t = t*2 + 1;
			cout << (l <= A[t]) << '\n';
		}
		else{
			int t = (a+b)/2;
			t = 2*(t+1);
			int l = t - (2*a+1);
			cout << ( l <= A[t]) << '\n';
		}
	}
	
}*/
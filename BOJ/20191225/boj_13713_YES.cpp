#include <iostream>
#include <algorithm>

using namespace std;

int Z[1000003], L, R;
int main() {
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
    string S;
    cin >> S;
    int N = S.size();
	reverse(S.begin(), S.end());
    
	int j=0;
	for(int i=1;i<N;i++) {
		while(j && S[i]!=S[j]) j=Z[j-1];
		if(S[i]==S[j]) Z[i]=++j;
	}
	
	for(int i = 0; i < N; i++)cout << S[i] << " ";
	cout << '\n';
	for(int i = 0; i < N; i++){
		cout << Z[i] << ' ';
	}
	
	
}



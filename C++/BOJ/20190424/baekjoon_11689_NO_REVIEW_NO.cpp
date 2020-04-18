#include <iostream>
#include <vector>

using namespace std;


void Fractional_decomposition(long long N, vector<long long>& restore){
	
	
	
	while(N!=1){
		
		for(long long i = 2; i <= N; i++){
			
			if(N%i == 0){
				
				N/=i;
				restore.push_back(i);
				break;
			}
				
			
		}
		
	}
	
	
}

vector<vector<char>> Map(1000, vector<char>(1000,' '));
	
long long gcd(long long N, long long K){
	
	long long C = N%K;
	
	if(C == 0){
		return K == 1 ? 1 : 0;
	}
	else return gcd(K,C);
}

/*int main(void){
	
	long long N ;
	cin >> N;
	
	
	for(int j = 1; j <= N; j++){
		int ans = 0;
		for(long long i = 1; i <= j; i++){
			ans += gcd(j, i);
		
		}
		Map[ans][j] = 'O';
	cout << " j=" << j << " ans=" << ans<< endl;
	}
	

	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cout << Map[i][j];
		}
		cout << endl;
	}
	vector<long long> Fractional_decomposition_restore;
	Fractional_decomposition(N,Fractional_decomposition_restore);
	
	return 0;
}*/
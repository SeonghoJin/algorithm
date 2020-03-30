/*#include <iostream>

using namespace std;
long long N;
long long fenwik1[100001];
long long fenwik2[100001];
long long Arr[100001];
long long t1[100001];
long long t2[100001];
void update1(long long i){
	
	while(i <= 100001){
		fenwik1[i] += 1;
		i += i & -i;
	}
}

long long sum1(long long i){
	long long ret = 0;
	while(i){
		ret += fenwik1[i];
		i -= i & -i;
	}
	return ret;
}
void update2(long long i){
	
	while(i <= 100001){
		fenwik2[i] += 1;
		i += i & -i;
	}
}

long long sum2(long long i){
	long long ret = 0;
	while(i){
		ret += fenwik2[i];
		i -= i & -i;
	}
	return ret;
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N;
	long long ans = 0;
	for(long long i = 0; i < N; i++){
		cin >> Arr[i];	
	}
	
	for(long long i = 0; i < N; i++){
		update1(Arr[i]);
		
		t1[i] = sum1(100001) - sum1(Arr[i]);
	}
	
	for(long long i = N-1; i >= 0; i--){
		update2(Arr[i]);
		
		t2[i] = sum2(Arr[i]-1);
	}
	
	
	for(long long i = 0; i < N; i++){
		ans += 1LL * t1[i] * t2[i];
	}
	cout << ans;
	
}*/
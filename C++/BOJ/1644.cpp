#include <bits/stdc++.h>

using namespace std;

const int MAX = 4'000'001;
int N;
vector<bool> isPrime(MAX, 1);
vector<int> prime;
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	cin >> N;
	for(int i = 2; i * i <= N; i++){
		if(isPrime[i]){
			for(int j = i*i; j <= N; j+=i){
				isPrime[j] = 0;
			}
		}
	}
	for(int i = 2; i <= N; i++){
		if(isPrime[i])prime.push_back(i);
	}
	int idx = 0;
	int sum = 0;
	int answer = 0;
	queue<int> q;
	
	for(int i = 0; i < prime.size(); i++){
		int here = prime[i];

		if(sum + here <= N){
			sum+=here;
			q.push(here);
		}
		else{
			while(sum + here > N){
				sum-=q.front();
				q.pop();
			}
			sum += here;
			q.push(here);
		}
		if(sum == N)answer++;
	}

	cout << answer;
}
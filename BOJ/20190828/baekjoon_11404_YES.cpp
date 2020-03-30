/*
첫째 줄에 도시의 개수 n(1 ≤ n ≤ 100)이 주어지고 둘째 줄에는 버스의 개수 m(1 ≤ m ≤ 100,000)이 주어진다. 그리고 셋째 줄부터 m+2줄까지 다음과 같은 버스의 정보가 주어진다. 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 버스의 정보는 버스의 시작 도시 a, 도착 도시 b, 한 번 타는데 필요한 비용 c로 이루어져 있다. 시작 도시와 도착 도시가 같은 경우는 없다. 비용은 100,000보다 작거나 같은 자연수이다.

시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.
*/
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	
	int N, M;
	cin >> N >> M;
	
	vector<vector<int>> t(N+1,vector<int>(N+1,987654321));
	
	for(int i = 1; i <= N; i++){
		t[i][i] = 0;
	}
	
	for(int i = 0; i < M; i++){
		int a,b,c;
		cin >> a >> b >> c;
		t[a][b]=min(t[a][b],c);
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			for(int k = 1; k <= N; k++){
				
				if(t[j][i] > t[j][k]+t[k][i])t[j][i] = t[j][k]+t[k][i];
				
			}
		}
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cout << t[i][j] << ' ';
		} 
		cout << '\n';
	}
	
	
	
}
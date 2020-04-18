/*
첫째 줄에 N(1≤N≤32,000), M(1≤M≤100,000)이 주어진다. M은 키를 비교한 회수이다. 다음 M개의 줄에는 키를 비교한 두 학생의 번호 A, B가 주어진다. 이는 학생 A가 학생 B의 앞에 서야 한다는 의미이다.

학생들의 번호는 1번부터 N번이다.

출력
첫째 줄부터 앞에서부터 줄을 세운 결과를 출력한다. 답이 여러 가지인 경우에는 아무거나 출력한다.


#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<vector<int>> adjlist(32001,vector<int>());
int visit[32001] = { 0,};
int N, M;

void set(int num){
	
	if(adjlist[num].empty()){
		visit[num]=1;
		cout << num << " ";
		return ;
	}
	
	for(int i = 0; i < adjlist[num].size(); i++){
		if(!visit[adjlist[num][i]])set(adjlist[num][i]);
	}
	   
	visit[num]=1;
	cout << num << " ";
}

int main(){
	cin.tie(NULL);
	ios_base :: sync_with_stdio(false);
	cin >> N >> M;
	
	for(int i = 0; i < M; i++){
		int a,b;
		cin >> a >> b;
		
		adjlist[b].push_back(a);
	}
	
	for(int i = 1; i <= N; i++){
		if(!visit[i])set(i);
	}
	
}*/
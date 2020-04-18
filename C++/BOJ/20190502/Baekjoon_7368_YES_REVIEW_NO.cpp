#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> weight_height(50, pair<int,int>(0,0));
static int N;
	


int comparePair(pair<int, int> p1, pair<int, int> p2){
	
	if(p1.first < p2.first && p1.second < p2.second)return 1;
	return 0;
}

void input(){
	cin >> N;
	
	for(int i = 0; i < N; i++){
		
		int weight,height;
		cin >> weight >> height;
		pair<int, int> t(weight, height);
	weight_height[i]=t;
	}
}
int main(){
	
	input();
	
	for(int i = 0; i < N; i++){
		int ret = 1;
		for(int j = 0; j < N; j++){
			ret += comparePair(weight_height[i],weight_height[j]);
		}
		cout << ret << " ";
	}
	
}
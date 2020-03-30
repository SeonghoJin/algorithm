/*
#include <iostream>
#include <vector>

using namespace std;

int t[1000001];
vector<int> k(1000001,0);

long long mergesort(int left ,int right){
	if(left == right)return 0;
	long long ret = 0;
	
	int mid = (left + right ) / 2;
	
	ret += mergesort(left ,mid);
	ret += mergesort(mid+1, right);
	
	vector<int> temp(right - left + 1);
	
	int li = left;
	int ri = mid+1;
	int idx = 0;
	
	while(li <= mid || ri <= right){
		if(ri > right || (li <= mid && k[li] < k[ri])){
			temp[idx++] = k[li++];
		}
		else{
			temp[idx++] = k[ri++];
			ret += mid - li + 1;
		}
	}
	
	for(int i = 0; i < right - left + 1; i++){
		k[left + i] = temp[i];
	}
	
	return ret;
}
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		int temp;
		cin >> temp;
		t[temp] = i;
	}
	
	for(int i = 0; i < N; i++){
		int temp;
		cin >> temp;
		k[i] = t[temp];
	}
	
	
	cout << mergesort(0, N-1);
	

	
}
*/
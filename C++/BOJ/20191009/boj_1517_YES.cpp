#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
vector<int> temp(1000000);
	

long long mergesort(vector<int>& arr,int i, int j){
	if(i >= j){return 0;}
	int mid = (i+j)/2;
	
	long long total = 0;
	
	total+=mergesort(arr,i,mid);
	total+=mergesort(arr,mid+1,j);
	
	int cnt = 0;
	
	int li = i;
	int ri = mid+1;
	
	while(li <= mid || ri <= j){
		if(ri > j || (li <= mid && arr[li] <= arr[ri])){
			temp[cnt++] = arr[li++];
		}
		else{
			temp[cnt++] = arr[ri++];
			total+=(ri-(i+cnt));
		}
	}
	cnt = 0;
	for(int k = i; k <= j; k++){
		arr[k] = temp[cnt++];
	}
	return total;
}



int main(){
	
	srand(time(0));
  	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int N;
	cin >> N;
	vector<int> v;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	cout << mergesort(v,0,v.size()-1);
	
	
}
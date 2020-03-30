/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> post,in(100001,0);
	

void printpre(int po_st, int po_end, int in_st, int in_end){
	if(in_st == in_end){
		cout << post[po_st] << " "; return;
	}
	
	int mid = post[po_end];
	cout << mid << " ";
	
	int mid_idx = in[mid];
	
	int temp = mid_idx - in_st ;
	if(po_st <= po_st+temp-1){
	printpre(po_st,po_st+temp-1,in_st,mid_idx-1);
	}
	if(po_st+temp <= po_end-1){
	printpre(po_st+temp,po_end-1,mid_idx+1,in_end);
	}
	
	
}


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		in[a] = i;
	}
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		post.push_back(a);
	}
	
	printpre(0,n-1,0,n-1);
	
	
	
}
*/

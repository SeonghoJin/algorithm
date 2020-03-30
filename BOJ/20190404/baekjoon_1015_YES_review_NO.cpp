#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static vector<int> Arr(51, 0);
static vector<int> sortArr(51, 0);
static vector<int> flag(51,0);
static int N;


static void input(){
	
	cin >> N;
	
	int k;
	
	for(int i = 0; i < N; i++){
		
		cin >> k;
		sortArr[i] = k;
		Arr[i] = k;
	
	}
	
	
}

static void r(){
	
	for(int i = 0; i < N; i++){
		
		for(int j = 0; j < N; j++){
			
			if(flag[j]==0&&Arr[i] == sortArr[j]){
				flag[j]=1;
				cout << j << " ";
				j += N+1;
			}
			
		}
		
	}
	
}





int main(){
	
	input();
	
	sort(&sortArr[0], &sortArr[N]);
	
	r();

	
}


/*


#include<stdio.h>
const int MAX_N=50;
int n,a[MAX_N],b[MAX_N];
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",a+i);
		for(int j=0; j<i; j++) a[j]>a[i]?b[j]++:b[i]++;
	}
	for(int i=0; i<n; i++) printf("%d ",b[i]);
	return 0;
}


*/
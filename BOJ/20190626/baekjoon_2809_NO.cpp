/*
상근이네 집 앞의 아스키 거리는 알파벳 소문자가 적혀 있는 타일 N개로 이루어져 있다. 정부는 알 수 없는 이유 때문에 거리의 타일을 자주 바꾼다. 하지만, 글자가 적혀있는 타일은 공급이 수요를 따라갈 수 없기 때문에 정부는 M종류의 묶음 타일만 사용할 수 있다.

i번째 묶음 타일은 Li개의 글자로 이루어져 있다. 묶음 타일은 회전하거나 조각으로 나눌 수 없다. 또, 거리와 연속해서 글자가 모두 일치하는 경우에만 그 묶음을 사용해서 타일을 교체할 수 있다. 타일은 겹쳐도 상관없고, 한 묶음을 여러 번 사용해도 된다.

현재 거리에 쓰여 있는 타일과 묶음 타일의 정보가 주어졌을 때, 그 어떤 타일로도 바꿀 수 없는 칸의 수를 구하는 프로그램을 작성하시오.
*/


#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
char str[300001];
int ans[300001];
int pos[300001];
int sa[300001],d=1;


bool cmp(int i, int j){
	if(pos[i]!=pos[j])return pos[i] < pos[j];
	i+=d;
	j+=d;
	return i < N && j < N ? pos[i] < pos[j] : i > j;
}

void findstr(char* s,int n = 0,int a = 0, int b = N-1){;
	if(s[0] =='\0'){ 
		for(int i = a; i <= b; i++){
			int k = sa[i];
			fill(ans+k,ans+k+n,1);
		}
		return;		   
	}
	
	int ta = -1;
	int tb = -1;
	for(int start = a, end = b; start<=end; ){
		int mid = (start+end)/2;
		if(sa[mid] + n > N){
			start = mid + 1; 
			continue;
		}
		if( str[sa[mid]+n]==s[0] && (sa[mid-1]+n >= N || mid == a || (sa[mid-1]+n < N && mid > 0  && s[0] > str[sa[mid-1]+n]) ) ){
			ta = mid;
			break;
		}
		else{
			if((str[sa[mid]+n] == s[0] && (sa[mid-1]+n < N && str[sa[mid-1]+n] == s[0])) || str[sa[mid]+n] > s[0]){
				end = mid - 1;
			}
			else{
				start = mid + 1;
			}
		}
		
	}
	for(int start = a, end = b; start<=end;){
		int mid = (start+end)/2;
		if(sa[mid]+n > N){
			start = mid + 1;
			continue;
		}
		if( str[sa[mid]+n]==s[0] && (sa[mid+1]+n >= N || mid == b || (mid < b  && sa[mid+1]+n  < N && s[0] < str[sa[mid+1]+n]) ) ){
			tb = mid;
			break;
		}
		else{
			if((str[sa[mid]+n] == s[0] &&(sa[mid+1]+n < N  && str[sa[mid+1]+n] == s[0])) || str[sa[mid]+n] < s[0]){
				start = mid + 1;
			}
			else{
				end = mid - 1;
			}
		}
		
	}
	
	if(ta == -1 || tb == -1)return;
	findstr(s+1,n+1,ta,tb);
}

int main(){
	
	scanf("%d %s",&N, str);
	
	for(int i = 0; i < N; i++){
		sa[i]=i;
		pos[i]=str[i];
	}
	
	while(1){
		sort(sa,sa+N,cmp);
		
		int temp[300001];
		
		for(int i = 1; i < N; i++){
			temp[i] = temp[i-1]+cmp(sa[i-1],sa[i]);
		}
		
		for(int i = 0; i < N; i++){
			pos[sa[i]]=temp[i];
		}
		
		if(temp[N-1] == N-1)break;
		d*=2;
	}
	int T;
	scanf("%d",&T);
	char c[5001];
	while(T--){
		scanf("%s",c);
		findstr(c);
	}
	int sum = 0;
	for(int i = 0; i < N; i++){
		sum+=ans[i];
	}
	printf("%d",N-sum);
	
}

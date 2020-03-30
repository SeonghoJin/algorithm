#include <cstdio>
#include <string.h>
#include <iostream>

using namespace std;
char DNA[501];
short dp[501][501];
inline short max(short a, short b){return a>b ? a : b;}
int main(){
    scanf("%s", &DNA);
    int len=strlen(DNA);
    for(int i=1; i<=len; i++)
    for(int j=i-1; j>0; j--){
        if((DNA[j-1]=='a'&&DNA[i-1]=='t')||(DNA[j-1]=='g'&&DNA[i-1]=='c'))
            dp[j][i]=dp[j+1][i-1]+2;
        for(int k=j; k<i; k++)
            if(dp[j][i] < dp[j][k]+dp[k+1][i])
                dp[j][i]=dp[j][k]+dp[k+1][i];
    }
	
	for(int i = 0; i <= len; i++){
		for(int j = 0; j <= len; j++){
			cout << dp[j][i] << ' ';
		}
		cout << '\n';
	}
    printf("%d", dp[1][len]);
}
/*#include <stdio.h>
#define BUFFER_SIZE 1048576

int N, M, Ans;
int Trees[1000000];


char getBuffer(void)
{
    static int idx = BUFFER_SIZE;
    static char buffer2[BUFFER_SIZE];
    if(idx == BUFFER_SIZE)
    {
        fread(buffer2, 1, BUFFER_SIZE, stdin);
        idx = 0;
    }
    return buffer2[idx++];
}

int getInt(void)
{
    int num;
    char ch;
    ch = getBuffer();
    while(ch < '0' || '9' < ch)
        ch = getBuffer();
    num = ch - '0';
    ch = getBuffer();
    while('0' <= ch && ch <= '9')
    {
        num = num * 10 + (ch - '0');
        ch = getBuffer();
    }
    return num;
}

int main(void){
	int max, from, to, m;
	long long sum;
	N = getInt();
	M = getInt();
	max = 0;
	for(int i = 0; i < N; i++){
		Trees[i] = getInt();
		if(max < Trees[i]){
			max = Trees[i];
		}
	}
	from = 0;
	to = max;
	while(from <= to){
		m = (from + to) / 2;
		sum = 0;
		for(int i = 0; i < N; i++){
			sum += (Trees[i] - m) > 0 ? (Trees[i] - m) : 0;
		}
		if(sum == M){
			Ans = m;
			break;
		}
		else if(sum > M){
			from = m + 1;
			Ans = m;
		}
		else{
			to = m - 1;
		}	
	}
	printf("%d", Ans);
	return 0;
}*/
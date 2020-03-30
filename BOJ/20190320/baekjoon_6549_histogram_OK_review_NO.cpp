#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

static long long N = -1;
static long long Arr[100001];

static void input(){
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> Arr[i];
	}
	
}

static long long solve(long long li, long long ri){
	
	if(li == ri){
		return Arr[li];
	}
	
	long long mid = (li + ri)/2;
	
	long long ret = max(solve(li, mid), solve(mid+1, ri));
	
	long long tli = mid;
	long long tri = mid+1;
	long long height = min(Arr[tli], Arr[tri]);
	ret = max(ret, (long long)(2*height));
	
	while(li < tli || tri < ri ){
		
		if(tri < ri && (Arr[tli-1] < Arr[tri+1] || tli == li)){
			++tri;
			height = min(height, Arr[tri]);
		}
		else{
			--tli;
			height = min(height, Arr[tli]);
		}
		
		ret = max(ret, (long long)(height*(tri - tli +1)));
	}
	
	return ret;
	
}


/*int main(){
	
	while(true){
		
		input();
		if(N == 0) break;
		
		long long MaxArea = solve(0, N-1);
		
		
		cout << MaxArea << endl;
		
		
	}
	

}*/


/*
#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/syscall.h>
using namespace std;

namespace fio {
	const int BSIZE = 2097152;
	char buffer[BSIZE];
	auto p = buffer + BSIZE;
	inline char readChar() {
		if (p == buffer + BSIZE) {
			syscall(0x00, 0, buffer, BSIZE);
			p = buffer;
		}
		return *p++;
	}
	int readInt() {
		char c = readChar();
		while (c < '-') {
			c = readChar();
		}
		int ret = 0;
		while (c >= '-') {
			ret = ret * 10 + c - '0';
			c = readChar();
		}
		return ret;
	}

	unsigned char outbuf[BSIZE + 20];
	unsigned char *outp = outbuf;

	void flush()
	{
		if (outp != outbuf)
		{
			syscall(0x01, 1, outbuf, outp - outbuf);
			outp = outbuf;
		}
	}

	void printans(long long ans)
	{
		unsigned char *endp = outp;
		do
		{
			*endp++ = ans % 10 + '0';
			ans /= 10;
		} while (ans);
		reverse(outp, endp);
		*(outp = endp)++ = '\n';

		if (outp > outbuf + BSIZE) flush();
	}
}

pair<int, int> stk[100005];

int main()
{
	for (;;)
	{
		int n = fio::readInt();
		if (n == 0) break;

		int top = 0;
		stk[top] = { 0, 0 };

		long long ans = 0;

		for (int i = 1; i <= n; i++)
		{
			int t = fio::readInt();
			int last = i;

			while (stk[top].first > t)
			{
				ans = max(ans, (long long)(i - stk[top].second) * stk[top].first);
				last = stk[top].second;
				--top;
			}

			if (stk[top].first < t) stk[++top] = { t, last };

		}

		while (top)
		{
			ans = max(ans, (long long)(n + 1 - stk[top].second) * stk[top].first);
			--top;
		}

		fio::printans(ans);
	}

	fio::flush();
	_Exit(0);
}*/
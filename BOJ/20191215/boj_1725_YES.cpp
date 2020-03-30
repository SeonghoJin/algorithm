#include <bits/stdc++.h>
using namespace std;

int p[300001];
int x[300001];

char buf[4200100];

inline int ri()
{
	static int i = 0;
	int r = buf[i++] - '0';
	while (buf[i] >= '0')
	{
		r *= 10;
		r += buf[i++] - '0';
	}
	return ++i, r;
}

char buf2[2100100];
int ii;
inline void wi(const char *s)
{
	while (*s)
		buf2[ii++] = *(s++);
	buf2[ii++] = '\n';
}

int f(int x)
{
	if (p[x] != x)
		p[x] = f(p[x]);
	return p[x];
}

void g(int a, int b)
{
	a = f(a);
	b = f(b);
	p[a] = b;
}

int main()
{
	fread(buf, 1, sizeof buf, stdin);

	int n, l, i;
	n = ri();
	l = ri();
	for (i = 1; i <= l; i++)
		p[i] = x[i] = i;
	for (i = 1; i <= n; i++)
	{
		int a, b;
		a = ri();
		b = ri();
		if (x[f(a)] == a)
		{
			if (a == f(b))
				x[a] = 0;
			else
				g(a, b);
		}
		else if (x[f(b)] == b)
		{
			if (b == f(a))
				x[b] = 0;
			else
				g(b, a);
		}
		else if (x[f(a)])
		{
			if (f(a) == f(b))
				x[f(a)] = 0;
			else
				g(a, b);
		}
		else if (x[f(b)])
		{
			if (f(b) == f(a))
				x[f(b)] = 0;
			else
				g(b, a);
		}
		else
		{
			wi("SMECE");
			continue;
		}
		wi("LADICA");
	}
	fwrite(buf2, 1, ii, stdout);
}
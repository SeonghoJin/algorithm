#include<cstdio>

int n,m,rt[101010],pos;

struct node{int l,r,v;}T[3535353];

const int MAXN=1e9;

void pst(int p,int s,int e,int idx)
{
	T[p].v++;

	if(s==e) return;

	int mid=s+e>>1;
	if(idx<=mid)
	{
		T[++pos]=T[T[p].l];T[p].l=pos;
		pst(pos,s,mid,idx);
	}

	else
	{
		T[++pos]=T[T[p].r];T[p].r=pos;
		pst(pos,mid+1,e,idx);
	}
}

int kth(int p1, int p2, int s, int e, int k)
{
	if(s==e) return e;

	int tmp=T[T[p2].l].v-T[T[p1].l].v;
	if(tmp>=k) return kth(T[p1].l,T[p2].l,s,s+e>>1,k);

	return kth(T[p1].r,T[p2].r,(s+e>>1)+1,e,k-tmp);
}

int main()
{
	scanf("%d %d",&n,&m);

	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		T[++pos]=T[rt[i-1]];
		rt[i]=pos;
		pst(pos,-MAXN,MAXN,a);
	}

	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		printf("%d\n",kth(rt[a-1],rt[b],-MAXN,MAXN,c));
	}
}

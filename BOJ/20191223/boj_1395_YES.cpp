/*
#include <iostream>

using namespace std;

const int MAX = 100001;

int tree[4*MAX];
int lazy[4*MAX];
int N, M;

void lazy_update(int root, int root_li, int root_ri){
	if(lazy[root]){
		tree[root] = root_ri - root_li + 1 - tree[root];
		lazy[root] = 0;
		
		if(root_li != root_ri){
		lazy[root*2] = 1 - lazy[root*2];
		lazy[root*2+1] = 1 - lazy[root*2+1];
		}
	}
}

void update(int l, int r, int root = 1, int root_li = 0, int root_ri = N-1){
	lazy_update(root, root_li, root_ri);
	
	if(r < root_li || root_ri < l)return;
	
	if(l <= root_li && root_ri <= r){
		tree[root] = root_ri - root_li + 1 - tree[root];
		if(root_li != root_ri){
			lazy[root*2] = 1 - lazy[root*2];
			lazy[root*2+1] = 1 - lazy[root*2 +1];
		}
		return;
	}
	
	int mid = (root_li + root_ri) >> 1;
	update(l,r,root*2,root_li, mid);
	update(l,r,root*2+1, mid+1, root_ri);
	
	tree[root] = tree[root*2] + tree[root*2+1];
}

int sum(int l, int r, int root = 1, int root_li = 0, int root_ri = N-1){
	lazy_update(root,root_li,root_ri);
	
	if(r < root_li || root_ri < l)return 0;
	
	if(l <= root_li && root_ri <= r){
		return tree[root];
	}
	int mid = (root_li + root_ri) >> 1;
	
	return sum(l,r,root*2, root_li, mid) + sum(l,r,root*2+1,mid+1, root_ri);
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < M; i++){
		int C, l, r;
		cin >> C >> l >> r;
		
		if(C == 0){
			update(l-1,r-1);
		}
		else{
			cout << sum(l-1,r-1) << '\n';
		}
		
	}
	
}
*/

#include <cstdio>
#include <cmath>
using namespace std;

char in[10000000];
const char* o;

void getIn() {
    o = in;
    in[fread(in, 1, sizeof(in) - 4, stdin)] = '\n';
}

int nextInt() {
    int ret = 0;
    bool sign = true;

    while (*o < '0' || *o > '9') ++o;
    while (*o >= '0' && *o <= '9') ret = 10 * ret + *o++ - '0';

    return ret;
}

const int MaxN = 1<<17;

int N, M;

class SegmentTree {
public:
    int size;
    int tree[2 * MaxN];
    bool lazy[2 * MaxN];

    SegmentTree(int n) {
        size = 1 << int(ceil(log2(n)));
    }

    void propagate(int nIdx, int nLeft, int nRight) {
        if (lazy[nIdx]) {
            if (nLeft != nRight) {
                lazy[2 * nIdx] ^= 1;
                lazy[2 * nIdx + 1] ^= 1;
            }

            tree[nIdx] = (nRight - nLeft + 1) - tree[nIdx];
            lazy[nIdx] = false;
        }
    }

    int query(int left, int right, int nIdx, int nLeft, int nRight) {
        propagate(nIdx, nLeft, nRight);

        if (left > nRight || right < nLeft)
            return 0;

        if (left <= nLeft && right >= nRight)
            return tree[nIdx];

        int nMid = nLeft + (nRight - nLeft) / 2;
        int retLeft = query(left, right, 2 * nIdx, nLeft, nMid);
        int retRight = query(left, right, 2 * nIdx + 1, nMid + 1, nRight);

        return retLeft + retRight;
    }

    void update(int left, int right, int nIdx, int nLeft, int nRight) {
        propagate(nIdx, nLeft, nRight);

        if (left > nRight || right < nLeft)
            return;

        if (left <= nLeft && right >= nRight) {
            lazy[nIdx] ^= 1;
            propagate(nIdx, nLeft, nRight);
            return;
        }

        int nMid = nLeft + (nRight - nLeft) / 2;
        update(left, right, 2 * nIdx, nLeft, nMid);
        update(left, right, 2 * nIdx + 1, nMid + 1, nRight);
        tree[nIdx] = tree[2 * nIdx] + tree[2 * nIdx + 1];
    }
};

int main() {
    getIn();
    N = nextInt();
    M = nextInt();

    SegmentTree st = SegmentTree(N);

    int q, s, e;
    while (M--) {
        q = nextInt();
        s = nextInt() - 1;
        e = nextInt() - 1;

        if (q)
            printf("%d\n", st.query(s, e, 1, 0, st.size - 1));
        else
            st.update(s, e, 1, 0, st.size - 1);
    }

    return 0;
}
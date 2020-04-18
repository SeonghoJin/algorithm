#include <iostream>
#include <string.h>

using namespace std;

const int mod = 100000007;

int N, K;
int tree[100001];
int base_tree[100001];
int current[100001];
int binary[100001] = { 1, };

void update(int idx, int diff)
{
	for (; idx <= N; idx += (idx&(-idx))) tree[idx] = (tree[idx] + diff) % mod;
}

int get_sum(int idx)
{
	int ret = 0;

	for (; idx > 0; idx -= (idx&(-idx))) ret = (ret + tree[idx]) % mod;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	cin >> T;

	N = 100000;

	for (int i = 1; i <= N; i++)
	{
		binary[i] = (2 * binary[i - 1]) % mod;
		update(i, binary[i - 1]);
		base_tree[i] = tree[i];
	}

	while (T--)
	{
		cin >> N >> K;

		for (int i = 1; i <= N; i++)
		{
			tree[i] = base_tree[i];
			current[i] = binary[i - 1];
		}

		for (int i = 0; i < K; i++)
		{
			int Q, A, B;

			cin >> Q >> A >> B;

			if (Q == 0)
			{
				update(B + 1, (current[A + 1] - current[B + 1] + mod) % mod);
				update(A + 1, (current[B + 1] - current[A + 1] + mod) % mod);
				
				int temp = current[A + 1];
				current[A + 1] = current[B + 1];
				current[B + 1] = temp;
			}
			else
			{
				int target = (binary[B + 1] - binary[A] + mod) % mod;

				if (target == (get_sum(B + 1) - get_sum(A) + mod) % mod) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}

	return 0;
}
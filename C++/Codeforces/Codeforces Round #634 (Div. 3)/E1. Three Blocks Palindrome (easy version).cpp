#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

#define sz(a) int((a).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &it : a) cin >> it;
		vector<vector<int>> cnt(26, vector<int>(n + 1));
		forn(i, n) {
			forn(j, 26) cnt[j][i + 1] = cnt[j][i];
			++cnt[a[i] - 1][i + 1];
		}
		int ans = 0;
		forn(i, 26) ans = max(ans, cnt[i][n]);
        
        for(int i = 0; i < 26; i++){
            for(int j = 0; j <= n; j++){
                cout << cnt[i][j] << " ";
            }
            cout << '\n';
        }
		forn(l, n) fore(r, l, n) {
			int cntin = 0, cntout = 0;
			forn(el, 26) {
				cntin = max(cntin, cnt[el][r + 1] - cnt[el][l]);
				cntout = max(cntout, min(cnt[el][l], cnt[el][n] - cnt[el][r + 1]) * 2);
			}
			ans = max(ans, cntin + cntout);
		}
		cout << ans << endl;
	}
	
	return 0;
}
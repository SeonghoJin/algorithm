#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, Arr[1001];
int tb[1001];
int t[10001];
int visit[1001];
	
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	int N;
	cin >> N;
	int m = 987654321;
	for(int i = 1; i <= N; i++){
		int k; cin >> k;
		m = min(m, k);
		Arr[i] = k;
		t[k] = i;
	}
	int cnt = 1;
	for(int i = 1; i <= 10001; i++){
		if(t[i] > 0){
			tb[t[i]] = cnt++; 
		}
	}
	
	for(int i = 1; i <= N; i++)cout << tb[i] << " ";
	cout << '\n';
	
	int ans = 0;
	for(int i = 1; i <= N; i++){
		if(visit[i] == 1)continue;
		
		int start = i;
		int next = tb[i];
		
		vector<int> v;
		v.push_back(start);
		visit[start] = 1;
		while(!visit[next]){
			visit[next] = 1;
			v.push_back(next);
			next = tb[next];
		}
		
		int sum =0;
		int sum1 = 0;
		int sum2 = 0;
		int mi = Arr[i];
		if(v.size() != 1){
			
			for(int i = 0; i < v.size(); i++){
				mi = min(mi, Arr[v[i]]);
				sum += Arr[v[i]];
			}
			sum1 = (v.size()-2)*mi + sum;
			sum2 = (v.size()+1)*m  + sum + mi;
			
			ans += sum1 < sum2 ? sum1 : sum2;
		}
		
	}
	cout << ans;

}
/*
#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;
int n, ck[1000], r;
pair<int, int> p[1000];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &p[i].first), p[i].second = i;
    sort(p, p + n);
    for (int i = 0; i < n; i++) {
        if (ck[i]) continue;
        int c = 0;
		int sum1 = 0;
		int sum2 = 0;
		int sum = 0;
        for (int j = i; !ck[j]; j = p[j].second) {
            ck[j] = 1;
            sum += p[j].first;
            c++;
        }
		sum1 = sum + p[0].first*(c+1) + p[i].first;
		sum2 = sum + p[i].first*(c-2);
		cout << sum1 << " " << sum2 << '\n';
		r += (sum1 < sum2 ? sum1 : sum2);
	}
    printf("%d", r);
    return 0;
}
*/
/*
#include<cstdio>
#include<algorithm>
using namespace std;
int n, ck[1000], r;
pair<int, int> p[1000];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &p[i].first), p[i].second = i;
    sort(p, p + n);
    for (int i = 0; i < n; i++) {
        if (ck[i]) continue;
        int c = 0;
        for (int j = i; !ck[j]; j = p[j].second) {
            ck[j] = 1;
            r += p[j].first;
            c++;
        }
        r += min(p[0].first*(c + 1) + p[i].first, p[i].first*(c - 2));
    }
    printf("%d", r);
    return 0;
}
*/
/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 200000;
int st = 1;
int L;
vector<int> sa(MAX,0), lcp(MAX,0), pos(MAX,0);
	
bool cmp(int i, int j){
	if(pos[i] != pos[j])return pos[i] < pos[j];
	i+=st;
	j+=st;
	return (i < L && j < L) ? (pos[i] < pos[j]) :( i > j);
}


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	
	cin >> L;
	string s;
	cin >> s;
	
	for(int i = 0; i < L; i++){
		sa[i] = i;
		pos[i] = s[i];
	}
	
	
	while(1){
		
		sort(sa.begin(), sa.begin()+L,cmp);
			
		vector<int> temp(L, 0);
		
		for(int i = 0; i < L-1; i++){
			temp[i+1] = temp[i] + cmp(sa[i],sa[i+1]);
		}
		
		for(int i = 0; i < L; i++){
			pos[sa[i]] = temp[i];
		}
		
		st*=2;
		if(temp[L-1] == L-1)break;	
	}
	
	int ans = 0;
	
	for(int i = 0, k = 0; i < L; i++, k = max(k-1, 0)){
		if(pos[i] == L-1)continue;
		int next = sa[pos[i]+1];
		while(s[next+k] == s[i+k])k++;
		ans = max(ans, k);
	}
	
	cout << ans;

}*/
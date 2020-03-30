#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX =200'001;

int SA[MAX], sz;
int pos[MAX];
int st = 1;
int lcp[MAX];
bool cmp(int i, int j){
	if(pos[i] != pos[j]){return pos[i] < pos[j];}
	i += st;
	j += st;
	return i < sz && j < sz ? pos[i] < pos[j] : i > j; 
}
int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int T;
	cin >> T;
	
		fill(SA, SA+MAX, 0);
		fill(lcp, lcp+MAX, 0);
		sz = 0;
		fill(pos, pos+MAX, 0);
		st = 1;
		string s;
		cin >> s;
		
		sz = s.size();
		
		for(int i = 0; i < sz; i++){
			SA[i] = i;
			pos[i] = s[i];
		}
		
		
		while(1){
			
			sort(SA, SA+sz, cmp);
			
			vector<int> temp(sz, 0);
			
			for(int i = 1; i < sz; i++){
				temp[i] = temp[i-1] + cmp(SA[i-1], SA[i]);
			}
			
			for(int i = 0; i < sz; i++){
				pos[SA[i]] = temp[i];
			}
			
			if(temp[sz-1] == sz-1)break;
			st *= 2;
		}
		
		for(int i = 0, k = 0; i < sz; i++, k = max(k-1, 0)){
			
			if(pos[i] == sz - 1)continue;
			
			int next = SA[pos[i]+1];
			
			while(s[i+k] == s[next + k])k++;
			
			lcp[pos[i]] = k;
		}
		
		int ans = 0;
		
		int t = 0;
		for(int i = 0; i < sz; i++){
			ans = max(ans, lcp[i]);
		}
		cout << ans;
		
	
	
}
#include <bits/stdc++.h>

using namespace std;


int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	long long N;
	cin >> N;
	
	vector<int> p;
	vector<int> m;
	int cnt = 0;
	for(int i = 0; i < N; i++){
		int temp;
		cin >> temp;
		if(temp == 0)cnt++;
		else if(temp > 0)p.push_back(temp);
		else{m.push_back(temp);}
	}

	sort(p.begin(),p.end());
	sort(m.begin(),m.end());

	vector<int> n_p(p.size());
	vector<int> n_m(m.size());

	int left = 0;
	int right = p.size()-1;

	for(int i = 0; i < p.size(); i++){
		if(i&1){
			n_p[right--] = p[i];
		}
		else{
			n_p[left++] = p[i];
		}
	}

	left = 0;
	right = m.size() - 1;
	reverse(m.begin(),m.end());
	for(int i = 0; i < m.size(); i++){
		if(i&1){
			n_m[left++] = m[i];
		}
		else{
			n_m[right--] = m[i];
		}
	}
	for(int j = 0; j < m.size(); j++)cout << n_m[j] << " ";
	for(int i = 0; i < cnt; i++)cout << 0 << " ";
	for(int i = 0; i < p.size(); i++)cout << n_p[i] << " ";
	
}
	



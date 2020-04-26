#include <bits/stdc++.h>

using namespace std;


map<string, int> m;
map<int,int> groupm;
vector<string> atos(1);
int parent[500001];
set<int> rel[500001];

set<int> groups;
int find(int i){return parent[i] == i ? i : parent[i] = find(parent[i]);}

void Union(int i, int j){
	int pi = find(i);
	int pj = find(j);
	//cout << "INUNON" << i << " " << j << ' ' << pi << " " << pj << '\n';
	parent[pi] = pj;
}

void test(vector<pair<string,string>>& vp, int group_cur, vector<set<int>>& group_rel, vector<vector<string>>& ingroup){
	for(int i = 1; i < atos.size(); i++){
		cout << atos[i] << " " << m[atos[i]] << " "<< i << '\n';
	}
	cout << '\n';
	for(auto it = groups.begin(); it != groups.end(); it++){
		cout << *it << " " << groupm[*it] << '\n';
	}
	cout << '\n';
	for(int i = 0; i < group_cur; i++){
		cout << vp[i].first << " " << vp[i].second << '\n';
	}
	cout << '\n';
	for(int i = 0; i < group_cur; i++){
		cout << i << ": ";
		for(auto it = group_rel[i].begin(); it != group_rel[i].end(); it++){
			cout << *it << " ";
		}
		cout << '\n';
	}
	cout << '\n';
	for(int i = 0; i < group_cur; i++){
		cout << i << ": ";
		for(string str : ingroup[i]){
			cout << str << " ";
		}
		cout << '\n';
	}

}



int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	for(int i = 0; i < 500001; i++)parent[i] = i;
	string str;
	cin >> str;
	int start = 0;
	int end;
	int sz = str.size();
	int cnt = 0;
	for(int i = 0; i <= str.size(); i++){
		if(i == str.size() || (i <= sz-2 && str[i] == '&' && str[i+1] == '&')){
			end = i-1;
			//cout << str.substr(start,end-start+1) << " ";
			
			for(int j = start; j <= end-1; j++){
				if(str[j+1] == '=' && (str[j] == '!' || str[j] == '=')){
					string a = str.substr(start, j-start);
					string b = str.substr(j+2,end-j-1);
					if(m[a] == 0){m[a] = ++cnt; atos.push_back(a);}
					if(m[b] == 0){m[b] = ++cnt; atos.push_back(b);}
					int ai = m[a];
					int bi = m[b];
					if(str[j] == '!'){
						//cout << ai << " " << bi << '\n';
						rel[min(ai,bi)].insert(max(ai,bi));
					}
					else{
					//cout << ai << " " << bi << '\n';
						Union(ai, bi);
					//cout << "parent : ";
					//cout << find(ai) << " " << find(bi) << '\n';
					}
				}
			}


			start = end+3;
		}
	}

	
	for(int i = 1; i <= cnt; i++){
		string here = atos[i];
		groups.insert(find(m[atos[i]]));
	}
	
	int group_cur = 0;
	for(auto it = groups.begin(); it != groups.end(); it++){
		int here = *it;
		groupm[here] = group_cur++;		
	}
	vector<pair<string,string>> vp(group_cur,pair<string,string>("#","1987654321"));
	bool flag = true;
	
	for(int i = 1; i < atos.size(); i++){
		string str = atos[i];
		
		int hereg = groupm[find(i)];
		//cout << hereg << " ";
		if(str[0] == '-' ||(str[0] >= '0' && str[0] <= '9')){
			if(vp[hereg].second != "1987654321"){
				flag = false;
			}
			else{vp[hereg].second = str;} 
		}
		else{
			if(vp[hereg].first == "#"){
				vp[hereg].first = str;
			}
			else{
				if(str.size() < vp[hereg].first.size()){
					vp[hereg].first = str;
				}
			}
		}
	}
	
	vector<set<int>> group_rel(group_cur);
	vector<vector<string>> ingroup(group_cur);
	for(int i = 1; i < atos.size(); i++){
		
		int here = groupm[find(i)];
		ingroup[here].push_back(atos[i]);
		//cout << rel[i].size() << '\n';
		for(auto it = rel[i].begin(); it != rel[i].end(); it++){
			int there = groupm[find(*it)];
			if(here == there)flag = false;
			group_rel[min(here,there)].insert(max(here,there));
		}
	}

	if(!flag){
		cout << "1==0"; return 0;
	}
	vector<string> temp;
	for(int i = 0; i < group_cur; i++){
		string s = (vp[i].first.size() > vp[i].second.size() && vp[i].second != "1987654321")  || vp[i].first == "#" ? vp[i].second  : vp[i].first;

		for(int j = 0; j < ingroup[i].size(); j++){
			
			if(ingroup[i][j] != s){
				temp.push_back(s+"=="+ingroup[i][j]);
			}
		
		}
	}

	for(int i = 0; i < group_cur; i++){
		int here = i;
		for(auto it = group_rel[i].begin(); it != group_rel[i].end(); it++){
			int there = *it;
			int ret = 0;
			string a1 = (vp[i].first.size() > vp[i].second.size() && vp[i].second != "1987654321")  || vp[i].first == "#" ? vp[i].second  : vp[i].first;
			string b1 = (vp[there].first.size() > vp[there].second.size() && vp[there].second != "1987654321")  || vp[there].first == "#" ? vp[there].second  : vp[there].first;	
			if(vp[i].second != "1987654321" && vp[there].second != "1987654321")continue;
			temp.push_back(a1+"!="+b1);
		}
	}
	if(temp.size() != 0){
	for(int i = 0; i < temp.size(); i++){
		cout << temp[i];
		if(i != temp.size()-1)cout << "&&";
	}}
	else{
		cout << "1==11";
	}



	//test(vp, group_cur, group_rel,ingroup);
}
	
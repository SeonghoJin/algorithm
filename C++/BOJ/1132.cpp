#include <bits/stdc++.h>

using namespace std;

vector<pair<vector<int>,char>> v;
vector<int> m(10,0);
bool check[10];
int N;
string str[51];
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    for(int i = 0; i < 10; i++){
        v.push_back({vector<int>(14,0), 'A'+i});
    }
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> str[i];
        int sz = str[i].size();
        for(int j = 0; j < str[i].size(); j++){
            v[str[i][j] - 'A'].first[14-sz+j]++;
        }
        check[str[i][0] - 'A'] = true;
    }

    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < 10; i++){
        if(check[v[i].second-'A'] == false){
            
            int j = i;
            while(j > 0 && v[j].first == v[j-1].first){
                swap(v[j-1],v[j]);
                j--;
            }
            swap(v[j], v[0]);
            sort(v.begin()+1, v.end());   
            break;
        }
    }
    
    for(int i = 0; i < 10; i++){
        int here = v[i].second - 'A';
        m[here] = i;
    }
    
    long long answer = 0;
    for(int i = 0; i < N; i++){
        long long n = 0;
        for(int j = 0; j < str[i].size(); j++){
            n += m[str[i][j]-'A'];
            n *= 10;
        }
        answer += n/10;
    }
    cout << answer;
}
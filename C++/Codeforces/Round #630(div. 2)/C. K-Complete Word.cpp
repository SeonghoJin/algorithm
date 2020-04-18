#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;


int find(vector<int>& parent, int i){return i == parent[i] ? i : parent[i] = find(parent, parent[i]);}
bool Union(vector<int>& parent, int a, int b){
    int pa = find(parent, a);
    int pb = find(parent, b);

    if(pa == pb)return false;

    parent[pb] = pa;
    return true;
}

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);

    int T;
    cin >> T;

    while(T--){
        int a, b;
        cin >> a >> b;
        string str;
        cin >> str;
        vector<int> parent(a);
        
        for(int i = 0; i < a; i++)parent[i] = (i%b);
        
        for(int i = 0; i < a/2; i++){
            Union(parent, i, a-i-1);
        }

        for(int i = 0; i < a; i+=b){
            for(int j = 0; j < b/2; j++){
                Union(parent, i+j, i + b - j - 1);
            }
        }
        
        set<int> s;
        map<int, int> m;
        for(int i = 0; i < a; i++){
            s.insert(find(parent,i));
        }
        
        
        int c = 0;

        for(auto i = s.begin(); i != s.end(); i++){
            m[*i] = c++;
        }
        /*for(int i = 0; i < a; i++){
            cout << m[find(parent,i)] << " ";
        }
        cout << '\n';*/
        vector<vector<int>> arr(c, vector<int>());
        
        for(int i = 0; i < a; i++){
            arr[m[find(parent,i)]].push_back(i);
        }
        int ans = 0;

        
        for(int i = 0; i < c; i++){
            int ma = 0;
            
            for(int j = 'a'; j <= 'z'; j++){
                int h_max = 0;
                for(int k = 0; k < arr[i].size(); k++){
                    if(str[arr[i][k]] == j)h_max++;
                }
                ma = max(ma, h_max);
            }
            
           /* for(int k = 0; k < arr[i].size(); k++){
                cout << arr[i][k] << " ";
            }
            cout << ma << '\n';
            cout << '\n';*/
            ans += (arr[i].size() - ma); 
        }

        cout << ans << '\n';
    }
    
}

/*

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
 
 
 
         int d,length;
         vector<int> pos,sa;
 
bool cmp_SA(int i, int j){
            if(pos[i]!=pos[j])return pos[i] < pos[j];
            i+=d;
            j+=d;
            return i < length && j < length ? pos[i] < pos[j] : i > j;
    }
        
         vector<int> getSA(string& s){
            length = s.size();
            d=1;
            pos.resize(length);
            sa.resize(length);
    
            for(int i = 0; i < length; i++){
                sa[i] = i;
                pos[i] = s[i];
            }
            
            while(1){
                
                sort(sa.begin(),sa.end(),cmp_SA);
                
                vector<int> temp(length,0);
                
                for(int i = 1; i < length; i++){
                    temp[i] = temp[i-1] + cmp_SA(sa[i-1],sa[i]);
                }
                
                for(int i = 0; i < length; i++){
                    pos[sa[i]] = temp[i];
                }
                
                if(temp[length-1] == length-1)break;
                
                d*=2;
            }
            
            return sa;
        }
 
        vector<int> getLCP(string& s){
            int length = s.size();
            vector<int> LCP(length),sa(length),pos(length);
            sa = getSA(s);
            
            for(int i = 0; i < length; i++){
                pos[sa[i]]=i;
            }
            
            for(int i = 0,k = 0; i < length; i++){
            
                int p = pos[i];
                if(p == length -1) continue;
                
                while(s[i+k] == s[sa[p+1]+k]){
                    k++;
                }
                LCP[pos[i]] = k;
                k=max(k-1,0);
            }
            
            return LCP;
            
        }
 
int main(){
  
    while(1){
        string str;
        getline(cin,str);
        vector<int> sa = getSA(str);
        vector<int> LCP = getLCP(str);
        for(int i = 0; i < sa.size(); i++){
            cout << sa[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < sa.size(); i++){
            cout << LCP[i] << " ";
        }
        cout << endl;
    }
}
*/
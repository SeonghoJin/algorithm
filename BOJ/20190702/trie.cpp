/*
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
 
class trie{
    
    public:
        trie(){
            Trie.resize(26);
        }
        void push(char* s){
            if(*s == '\0'){check = true;cout << check; return;}
            
            int index = *s - 'a'; 
            
            if(Trie[index] == nullptr)Trie[index] = new trie();
            Trie[index]->push(s+1);
            
        }
        
        int find(char* s){
            
            if(*s == '\0')return check;
            int index = *s -'a';
            
            if(Trie[index] == nullptr)return false;    
            return Trie[index]->find(s+1);
        }
        
    private:
        vector<trie*> Trie;
        bool check = false;
};
 
int main(){
    trie T;
    
    while(1){
        char str[100];
        cin >> str;
        if(str[0] == '0')break;
        T.push(str);
    }
    
    cout << "끝";
    
    while(1){
        char str[100];
        cin >> str;
        if(str == "0")break;
        if(T.find(str)){
            cout << "있음";
        }
        else{
            cout << "없음";
        }
    }
}
*/

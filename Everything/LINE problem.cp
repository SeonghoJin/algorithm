#include <iostream>
#include <cmath>
using namespace std;


string answer_sheet;  // 0 < answer_sheet.size() < 101
string sheets[200];
int N, M;
        
int f(string s1, string s2){
    
    int sum1 = 0, sum2 = 0;
    int temp = 0;
    for(int i = 0; i < N; i++){
        if(answer_sheet[i] != s1[i] && s1[i] == s2[i]){
            sum2 = max(sum2, ++temp);
            sum1++;
        }
        else{
            temp = 0;
        }
    }
    
    return sum1 + sum2*sum2;
}

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    cin >> N >> M; // N은 문제의수, M은 답지의 수(사람의 수)

    cin >> answer_sheet;
    for(int i = 0; i < M; i++)cin >> sheets[i];

    int ans = 0;
    for(int i = 0; i < M; i++){
        string here = sheets[i];
        for(int j = i+1; j < M; j++){
            string next = sheets[j];
            ans = max(ans, f(here, next));
        }
    }

    cout << ans;

    
}
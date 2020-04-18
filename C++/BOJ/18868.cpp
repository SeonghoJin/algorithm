#include <iostream>

using namespace std;

int check[10];
int arr[10][100];
int _arr[10][100];

int main(){

    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)cin >> arr[i][j];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            int c = 0;
            for(int k = 0; k < M; k++){
                if(k != j && arr[i][j] < arr[i][k]){
                    c++;
                }
            }
            _arr[i][j] = c;
        }

    int ans = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            bool flag = true;
            for(int k = 0; k < M; k++){
                if(_arr[i][k] != _arr[j][k])flag = false;
            }
            if(flag)ans++;
        }
        
    }
        cout << ans;
}
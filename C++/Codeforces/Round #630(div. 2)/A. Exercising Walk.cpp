#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
 
    int T;
    cin >> T;
 
    while(T--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        int x,y,x1,y1,x2,y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
 
        x1-=x;
        x2-=x;
        y1-=y;
        y2-=y;
 
        bool flag = true;
 
        int h_x = b - a;
        int h_y = d - c;
 
        if(h_x >= x1 && h_x <= x2 && h_y >= y1 && h_y <= y2){
            flag = true;
        }
        else{
            flag = false;
        }
 
        if((a > 0 || b > 0) && ((x2 - x1) == 0))flag = false;
        if((c > 0 || d > 0) && ((y2 - y1) == 0))flag = false;
 
        if(!(x1 <= 0 && y1 <= 0 && 0 <= x2 && 0 <= y2)){flag = false;}
        cout << (flag ? "YES" : "NO") << '\n';
           
    }
 
}
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	char t = getchar();
	while(T--){
		double E = 0, A = 0;
		
		while(1){
			char temp[101];
			int cursor = 0;
			
			while(1){
				scanf("%c", &temp[cursor]);
				if(temp[cursor] == '\n'){temp[cursor] = '\0'; break;}
				cursor++;
			}
			
			if(temp[0] == '\0')break;
			A+=cursor;
			for(int i = 0; i < cursor; i++){
				if(temp[i] == '#'){E++;}
			}
		}
		double ans = (A-E)/A*100;
		float nearest = roundf(ans * 10) / 10;
		cout << "Efficiency ratio is " << nearest << "%" << ".\n";
		}
}
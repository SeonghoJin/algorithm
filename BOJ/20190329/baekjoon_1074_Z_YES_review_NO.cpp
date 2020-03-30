#include <iostream> 
#include <cmath>

using namespace std;

static int N , r , c;
static int Answer = 0;

static void input(){
	
	cin >> N >> r >> c;
}

static int Search(int x, int y, int Answer, int length){ // 1, 3
	
	int ret = 0;
	
	if(y == r && x == c ){
		return Answer;
	}
	
	length /=2;
	int area = length*length;
	
	
	if(r < y + length && c < x + length){
		
	}
	else if(r < y + length && c < x + length*2){
		x += length;
		ret += area;
	}
	else if(r < y + length*2 && c < x + length){
		y += length;
		ret += 2 * area;
	}
	else if(r < y + length*2 && c < x + length*2){
		x += length;
		y += length;
		ret += 3 * area;
	}
	return Search(x,y, Answer+ret, length);
	
	
}


/*int main(){
	
	input(); 
	
	
	
	cout << Search(0, 0, 0, pow(2,N));
	
}*/


/*

#import<map>
int N,r,c,t,x;main(){scanf("%d%d%d",&N,&c,&r);for(t=1<<N;N--;x+=((c>=t)*2|r>=t)*t*t)r%=t,c%=t,t/=2;printf("%d",x);}

*/
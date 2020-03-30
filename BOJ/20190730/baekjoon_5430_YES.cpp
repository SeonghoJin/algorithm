/*#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int main(){
	
	int T;
	scanf("%d",&T);
	while(T--){
		char command[300001];
		char array[300001];
		int N;
		vector<int> li;
		scanf("%s %d %s",command, &N,array);
		int Rnum = 0, Bnum = 0, Fnum = 0;
		
		char* result = strtok(array,"[],");
		while(result != NULL){
			li.push_back(atoi(result));
			result = strtok(NULL,"[],");
		}
		int start = 0;
		int end = li.size()-1;
		bool flag = false;
		
		for(int i = 0; i < strlen(command); i++){
			if(command[i] == 'R'){
				Rnum = (Rnum+1)%2;
			}
			else if(command[i] == 'D'){
				if(start > end){ flag = true; break;}
				if(Rnum == 0){
					start++;
				}
				else if(Rnum == 1){
					end--;
				}
			}
		}
		
		if(flag){printf("error\n"); continue;}
		
		if(start > end){
			printf("[]\n");
			continue;
		}
		
		if(Rnum == 0){
			printf("[");
			for(int i = start; i < end; i++){
				printf("%d,",li[i]);
			}
			printf("%d]",li[end]);
		}
		else{
			printf("[");
			for(int i = end; i > start; i--){
				printf("%d,",li[i]);
			}
			printf("%d]",li[start]);
		}
		printf("\n");
		
		
	}
}*/
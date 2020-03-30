/*
#include <iostream>
#include <vector>
using namespace std;

const int sz = 3;

vector<vector<char>> rotation(vector<vector<char>>& v,int angle){
	
	vector<vector<char>> temp(3,vector<char>(3));
	
	if(angle == 90){
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){			
				temp[j][2-i] = v[i][j];
			}
		}
	}
	else{
		
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){			
				temp[2-j][i] = v[i][j];
			}
		}
	}
	
	return temp;
}

void cycle(vector<vector<vector<char>>>& cube, string value){
	
	
	if(value[0] == 'U'){ //4,3,2,1
		if(value[1] == '+'){
			cube[0] = rotation(cube[0],90);
			vector<char> unsafe;
			unsafe = cube[1][0];
			cube[1][0] = cube[2][0];
			cube[2][0] = cube[3][0];
			cube[3][0] = cube[4][0];
			cube[4][0] = unsafe;
			
		}
		else{ // 1,2,3,4
			cube[0] = rotation(cube[0],-90);
			vector<char> unsafe;
			unsafe = cube[4][0];
			cube[4][0] = cube[3][0];
			cube[3][0] = cube[2][0];
			cube[2][0] = cube[1][0];
			cube[1][0] = unsafe;
		}
	}
	else if(value[0] == 'D'){ // 1,2,3,4
		if(value[1] == '+'){
			cube[5] = rotation(cube[5],-90);
			vector<char> unsafe;
			unsafe = cube[4][2];
			cube[4][2] = cube[3][2];
			cube[3][2] = cube[2][2];
			cube[2][2] = cube[1][2];
			cube[1][2] = unsafe;
		}
		else{ // 4,3,2,1
			cube[5] = rotation(cube[5],+90);
			vector<char> unsafe;
			unsafe = cube[1][2];
			cube[1][2] = cube[2][2];
			cube[2][2] = cube[3][2];
			cube[3][2] = cube[4][2];
			cube[4][2] = unsafe;
		}
	}
	else if(value[0] == 'F'){ //0,2,5,4  
		if(value[1] == '+'){
			cube[1] = rotation(cube[1],90);
			vector<vector<char>> unsafe;
			unsafe = cube[4];
			
			cube[4][0][2] = cube[5][2][0];
			cube[4][1][2] = cube[5][2][1];
			cube[4][2][2] = cube[5][2][2];
			
			cube[5][2][0] = cube[2][2][0];
			cube[5][2][1] = cube[2][1][0];
			cube[5][2][2] = cube[2][0][0];
			
			cube[2][0][0] = cube[0][2][0];
			cube[2][1][0] = cube[0][2][1];
			cube[2][2][0] = cube[0][2][2];
			
			cube[0][2][0] = unsafe[2][2];
			cube[0][2][1] = unsafe[1][2];
			cube[0][2][2] = unsafe[0][2];
		
		}
		else{ //4,5,2,0
			cube[1] = rotation(cube[1],-90);
			vector<vector<char>> unsafe;
			
			unsafe = cube[0];
			cube[0][2][2] = cube[2][2][0];
			cube[0][2][1] = cube[2][1][0];
			cube[0][2][0] = cube[2][0][0];
			
			cube[2][2][0] = cube[5][2][0];
			cube[2][1][0] = cube[5][2][1];
			cube[2][0][0] = cube[5][2][2];
			
			cube[5][2][0] = cube[4][0][2];
			cube[5][2][1] = cube[4][1][2];
			cube[5][2][2] = cube[4][2][2];
			
			cube[4][0][2] = unsafe[2][2];
			cube[4][1][2] = unsafe[2][1];
			cube[4][2][2] = unsafe[2][0];
		}
	}
	else if(value[0] == 'B'){ //4,5,2,0
		if(value[1] == '+'){
			cube[3] = rotation(cube[3],90);
			vector<vector<char>> unsafe;
			
			unsafe = cube[0];
			cube[0][0][0] = cube[2][0][2];
			cube[0][0][1] = cube[2][1][2];
			cube[0][0][2] = cube[2][2][2];
			
			cube[2][0][2] = cube[5][0][2];
			cube[2][1][2] = cube[5][0][1];
			cube[2][2][2] = cube[5][0][0];
			
			cube[5][0][0] = cube[4][0][0];
			cube[5][0][1] = cube[4][1][0];
			cube[5][0][2] = cube[4][2][0];
			
			cube[4][2][0] = unsafe[0][0];
			cube[4][1][0] = unsafe[0][1];
			cube[4][0][0] = unsafe[0][2];
		
		}
		else{//0,2,5,4
			cube[3] = rotation(cube[3],-90);
			vector<vector<char>> unsafe;
			
			unsafe = cube[4];
			cube[4][0][0] = cube[5][0][0];
			cube[4][1][0] = cube[5][0][1];
			cube[4][2][0] = cube[5][0][2];
			
			cube[5][0][0] = cube[2][2][2];
			cube[5][0][1] = cube[2][1][2];
			cube[5][0][2] = cube[2][0][2];
			
			cube[2][0][2] = cube[0][0][0];
			cube[2][1][2] = cube[0][0][1];
			cube[2][2][2] = cube[0][0][2];
			
			cube[0][0][2] = unsafe[0][0];
			cube[0][0][1] = unsafe[1][0];
			cube[0][0][0] = unsafe[2][0];
		
		}
	}
	else if(value[0] == 'L'){
		if(value[1] == '+'){ //5,3,0,1
			cube[4] = rotation(cube[4],90);
			vector<vector<char>> unsafe;
			
			unsafe = cube[1];
			cube[1][2][0] = cube[0][2][0];
			cube[1][1][0] = cube[0][1][0];
			cube[1][0][0] = cube[0][0][0];
			
			cube[0][2][0] = cube[3][0][2];
			cube[0][1][0] = cube[3][1][2];
			cube[0][0][0] = cube[3][2][2];
			
			cube[3][0][2] = cube[5][0][0];
			cube[3][1][2] = cube[5][1][0];
			cube[3][2][2] = cube[5][2][0];
			
			cube[5][0][0] = unsafe[2][0];
			cube[5][1][0] = unsafe[1][0];
			cube[5][2][0] = unsafe[0][0];
		
		}
		else{//1,0,3,5
			cube[4] = rotation(cube[4],-90);
			vector<vector<char>> unsafe;
			
			unsafe = cube[5];
			cube[5][0][0] = cube[3][0][2];
			cube[5][1][0] = cube[3][1][2];
			cube[5][2][0] = cube[3][2][2];
			
			cube[3][0][2] = cube[0][2][0];
			cube[3][1][2] = cube[0][1][0];
			cube[3][2][2] = cube[0][0][0];
			
			cube[0][0][0] = cube[1][0][0];
			cube[0][1][0] = cube[1][1][0];
			cube[0][2][0] = cube[1][2][0];
			
			cube[1][0][0] = unsafe[2][0];
			cube[1][1][0] = unsafe[1][0];
			cube[1][2][0] = unsafe[0][0];
		
		}
	}
	else if(value[0] == 'R'){
		if(value[1] == '+'){ //1,0,3,5
			cube[2] = rotation(cube[2],90);
			vector<vector<char>> unsafe;
			
			unsafe = cube[5];
			cube[5][0][2] = cube[3][0][0];
			cube[5][1][2] = cube[3][1][0];
			cube[5][2][2]= cube[3][2][0];
			
			cube[3][0][0] = cube[0][2][2];
			cube[3][1][0] = cube[0][1][2];
			cube[3][2][0] = cube[0][0][2];
			
			cube[0][2][2] = cube[1][2][2];
			cube[0][1][2] = cube[1][1][2];
			cube[0][0][2] = cube[1][0][2];
			
			cube[1][2][2] = unsafe[0][2];
			cube[1][1][2] = unsafe[1][2];
			cube[1][0][2] = unsafe[2][2];
		
		}
		else{//5,3,0,1
			cube[2] = rotation(cube[2],-90);
			vector<vector<char>> unsafe;
			
			unsafe = cube[1];
			cube[1][2][2] = cube[0][2][2];
			cube[1][1][2] = cube[0][1][2];
			cube[1][0][2] = cube[0][0][2];
			
			cube[0][2][2] = cube[3][0][0];
			cube[0][1][2] = cube[3][1][0];
			cube[0][0][2] = cube[3][2][0];
			
			cube[3][0][0] = cube[5][0][2];
			cube[3][1][0] = cube[5][1][2];
			cube[3][2][0] = cube[5][2][2];
			
			cube[5][0][2] = unsafe[2][2];
			cube[5][1][2] = unsafe[1][2];
			cube[5][2][2] = unsafe[0][2];
		}
	}
	
	
	
}



int main(){
	
	int T;
	cin >> T;
	
	while(T--){
		int N;
		cin >> N;
		
		vector<vector<vector<char>>> cube = {{{'w','w','w'},{'w','w','w'},{'w','w','w'}},{{'r','r','r'},{'r','r','r'},{'r','r','r'}},{{'b','b','b'},{'b','b','b'},{'b','b','b'}},{{'o','o','o'},{'o','o','o'},{'o','o','o'}},{{'g','g','g'},{'g','g','g'},{'g','g','g'}},{{'y','y','y'},{'y','y','y'},{'y','y','y'}}};
	
		while(N--){
			string s;
			cin >> s;
			cycle(cube,s);
			
		}
		
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < sz; j++){
				for(int k = 0; k < sz; k++){
					cout << cube[i][j][k];
				}
				cout << '\n';
			}
			cout << '\n';
		}
		/*
			for(int j = 0; j < sz; j++){
				for(int k = 0; k < sz; k++){
					cout << cube[0][j][k];
				}
				cout << '\n';
			}
		
		
	}
	
	
}
*/
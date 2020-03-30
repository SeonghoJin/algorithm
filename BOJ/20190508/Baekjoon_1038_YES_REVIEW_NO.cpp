#include <iostream>
#include <algorithm>

using namespace std;

int N;
char binarytree[26][3];


static bool hasrightnode(char Value);
static bool hasleftnode(char Value);
static int ctoi(char Value);
static void input(){
	cin >> N;
	
	for(int i = 0; i < N; i++){
		
		char a;
		cin >> a;
			
		for(int j = 1; j < 3; j++){
			cin >> binarytree[ctoi(a)][j];
		}
	}
}

static int ctoi(char Value){
	return Value - 'A';
}

static bool isEmpty(char Value){
	return !hasleftnode(Value) && !hasrightnode(Value);
}

static bool hasleftnode(char Value){
	return binarytree[ctoi(Value)][1]!='.';
}

static bool hasrightnode(char Value){
	return binarytree[ctoi(Value)][2]!='.';
}

void preorder(char Value){
	
	cout << Value;
	
	if(hasleftnode(Value)){
		preorder(binarytree[ctoi(Value)][1]);
	}
	if(hasrightnode(Value)){
		preorder(binarytree[ctoi(Value)][2]);
	}
	

}

void inorder(char Value){
	
	if(hasleftnode(Value)){
			inorder(binarytree[ctoi(Value)][1]);
	
	}
	cout << Value;
	if(hasrightnode(Value)){
			inorder(binarytree[ctoi(Value)][2]);
	}
	
	
	
}

void postorder(char Value){
	if(hasleftnode(Value)){
			postorder(binarytree[ctoi(Value)][1]);
	}
	if(hasrightnode(Value)){
		postorder(binarytree[ctoi(Value)][2]);

	}
	
	cout << Value;
	
	
	
	
}


/*int main(){
	input();
	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
}*/
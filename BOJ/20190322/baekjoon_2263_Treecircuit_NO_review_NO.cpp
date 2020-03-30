#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static int N;
vector<int> inOrder;
vector<int> postOrder;
vector<int> preOrder;

void print(vector<int>& source){
		
		for(int i = 0; i < N; i++){
			
			cout << source[i] << " ";
			
		}
		
		cout << endl;
		
}

vector<int>& slice(vector<int>& v, int a, int b){
	return *new vector<int>(v.begin()+ a , v.begin()+ b);
}

/*void FindpreOrder(vector<int>& inOrder, vector<int>& postOrder){
	
	int N = postOrder.size();
	int rootValue = postOrder[N-1];
	
	cout << rootValue << ' ';
	
	if(postOrder.empty()) return; 
	
	int L = find(inOrder.begin(), inOrder.end(), rootValue) - inOrder.begin();
	
	FindpreOrder(slice(inOrder, 0, L),slice(postOrder,0,L));
	FindpreOrder(slice(inOrder,L+1,N),slice(postOrder,L+1,N - 1));
	
}

static void input(){
	
	cin >> N;
	for(int i = 0; i < N; i++){
		int K;
		cin >> K;
		inOrder.push_back(K);
	}
	
	for(int j = 0; j < N; j++){
		int K;
		cin >> K;
		postOrder.push_back(K);
	}
	
	
	
	
}





int main(){
	
	input();
	FindpreOrder(inOrder, postOrder);
	
	
	
}*/
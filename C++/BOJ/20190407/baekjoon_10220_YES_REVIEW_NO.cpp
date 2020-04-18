https://blog.encrypted.gg/139

#include <iostream>
#include <vector>

using namespace std;

vector<int> Arr;
int T;
int sum = 0;

/*bool judge(){
	
	vector<int> judgeArr(10,0);
	
	for(int i = 0; i < T; i++){
		judgeArr[Arr[i]]++;
		
	}
	
	
	for(int i = 0; i < T; i++){
		
		if(judgeArr[i] != Arr[i])
			return false;
		
	}
	
	return true;
	
}




void seq(int N){
	
	if(T == N){
		
		if(judge()){
			for(auto it = Arr.begin(); it != Arr.end(); it++){
			
			cout << *it << " ";
	}
		
		
		
		cout << endl;
		
		sum++;
		}
		
		return;	
	}
	for(int i = 0; i < T; i++){
		
		Arr.push_back(i);
		seq(N+1);
		Arr.pop_back();
		
	
	}
	
}
*/
int main(){
	
	cin >> T;
	
	while(T--){
	
	int a;
	cin >> a;
		
	 if (6 % a == 0)
            {
                cout <<"0"<<endl;
            } else if (a == 4)
                cout <<"2"<<endl;
            else
            cout <<"1"<<endl;
            }
	}	

#include <bits/stdc++.h>

using namespace std;

const int MAX = 51;
int Arr[MAX];
int N;
double slopes[MAX][MAX];

double slope(int x, int y, int nx, int ny){
	return (1.0)*(y-ny)/(x-nx);
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);

	cin >> N;

	for(int i = 0; i < N; i++)cin >> Arr[i];	
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i == j)continue;
			slopes[i][j] = slope(i,Arr[i],j,Arr[j]);
		}
	}

	int answer = 0;
	for(int i = 0; i < N; i++){
		int count = 0;
		
		if(i > 0){
			double sl = slopes[i][i-1];
			count++;
			for(int j = i-1; j >= 0; j--){
				if(sl > slopes[i][j]){
					count++;
					sl = slopes[i][j];
				}
			}
		}
		if(i < N-1){
			double sl = slopes[i][i+1];
			count++;
			for(int j = i+1; j < N; j++){
				if(sl < slopes[i][j]){
					sl = slopes[i][j];
					count++;
				}
			}
		}
		//cout << count << " ";
		answer = max(answer, count);
	}

	/*cout << '\n';
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << slopes[i][j] << " ";
		}
		cout << '\n';
	}*/
	cout << answer;
}

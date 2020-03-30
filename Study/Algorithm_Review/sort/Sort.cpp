#ifndef SORT_CPP__
#define SORT_CPP__
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std; 

vector<int> Array = 
{1,5,4,2,3,1,2,3,1,5,21543,24,7,7,34,5,52,412,3676,7,37,243,6,54,3,214,3,41,32,13,213,1,23,123,21,3,432,1,14,3,432,43,443,43,4,2,1,3,2,1,1,7,567,543,4,54,43,3,2,2,5,7,7,48,2,2,245,6,7,8};


void digitSortOf_digit(vector<int>& Array,int _digit);
void merge(vector<int>& Array, int leftIndex, int rightIndex);
void split_merge(vector<int>& Array, int leftIndex, int rightIndex);
void printArray(vector<int>& Array);
void printArray(queue<int> Array);
int partition(vector<int>& Array, int leftIndex, int rightIndex);
void swap(int& a,int &b);
pair<int, int> childeIndeof(int parentNode);
int parentIndexof(int childNode);
bool hasParent(int i);
bool isbigger(int i, int j);
void isbigger_in_heaptree(vector<int>& Array, int i);
void vector_to_heaptree(vector<int>& Array);
int hasChild(int i, int size);
void issmaller_in_heaptree(vector<int>& Array, int size,int i);
void SumArray(vector<int>& Array);
void counting(vector<int>& Array, vector<int>& Brray);
int digit(int Value, int dig);
int digitsOf(int Value);
int Foundmax(vector<int>& Array);

//QuickSort
void QuickSort(vector<int>& Array, int leftIndex, int rightIndex){
	
	int p;

	if(rightIndex - leftIndex > 0){	
	p = partition(Array, leftIndex, rightIndex);
	QuickSort(Array, leftIndex, p-1); 
	QuickSort(Array, p+1, rightIndex);
	}
	}
	


int partition(vector<int>& Array, int leftIndex, int rightIndex){
	int li = leftIndex;
	int p = rightIndex; //17
	

	int FirstUpper = leftIndex; 
	int size = rightIndex - leftIndex + 1;
	
	for(int i = leftIndex; i < rightIndex; i++){
		
		if(Array[i] < Array[p]){
			swap(Array[i],Array[FirstUpper]);
			FirstUpper++;
			
		}
	}
	
	swap(Array[FirstUpper],Array[p]);
		
	return FirstUpper;
	
}

//bubleSort
void bubleSort(vector<int>& Array){
	
	int size = Array.size();
	
	for(int i = 0; i < size; i++){
		for(int j = i; j < size; j++){
			if( Array[i] > Array[j]){
				swap(Array[i], Array[j]);
			}
		}
	}
	
}


//mergeSort
void mergeSort(vector<int>& Array){
	
	split_merge(Array, 0, Array.size()-1);
	
}

void split_merge(vector<int>& Array, int leftIndex, int rightIndex){
	
	if(leftIndex == rightIndex) return;
	
	int midIndex = (leftIndex + rightIndex)/2;
	
	split_merge(Array,leftIndex, midIndex);
	split_merge(Array,midIndex+1, rightIndex);

	merge(Array, leftIndex, rightIndex);
}


void merge(vector<int>& Array, int leftIndex, int rightIndex){
	
	vector<int> Temp;
	int midIndex = (leftIndex + rightIndex)/2;
	
	int lm = leftIndex;
	int mm = midIndex+1; 
	
	while(lm <= midIndex || mm <= rightIndex){
		if(mm > rightIndex || (lm <= midIndex && Array[lm] < Array[mm])){
			Temp.push_back(Array[lm++]);
		}
		else{
			Temp.push_back(Array[mm++]);
		}
	}
	
	int Length = rightIndex - leftIndex+1;
	
	for(int i = 0; i < Length; i++){
		Array[leftIndex + i] = Temp[i];
	}
}



// pushionSort
void pushionSort(vector<int>& Array){
	int size = Array.size();
	
	for(int i = 1; i < size; i++){
		int j = i-1;
		int t = i;
		while(Array[t] < Array[j] && j >=0){
			swap(Array[t--],Array[j--]);
		}
	}
	
}




//heapSort

void heapSort(vector<int>& Array){
	
	int size = Array.size();
	vector_to_heaptree(Array);
	
	for(int i = size - 1; i > 0; i--){
		swap(Array[i], Array[0]);
		issmaller_in_heaptree(Array,i,0);
	}
	
	
}

void vector_to_heaptree(vector<int>& Array){
	
	int size = Array.size();
	
	for(int i = 0; i < size; i++){
		
		isbigger_in_heaptree(Array, i);
		
	}
	
for(int i = 0; i < Array.size(); i++){
		
		cout << "ValueOf" <<i <<"=" << Array[i] << " ValueOf" << parentIndexof(i) << "=" << Array[parentIndexof(i)] << " " << isbigger(Array[i],Array[parentIndexof(i)]) << endl; 
		
	}
		
}

void issmaller_in_heaptree(vector<int>& Array, int size,int i){
	
	pair<int,int> childNodes = childeIndeof(i);
	if(hasChild > 0 ){
		
		if(hasChild(i,size) == 1 && !isbigger(Array[i],Array[childNodes.first])){
			
			swap(Array[i],Array[childNodes.first]);
			issmaller_in_heaptree(Array,size,childNodes.first);
			
		}
		
		if(hasChild(i, size) == 2){
			
			if(Array[childNodes.first] > Array[childNodes.second] && !isbigger(Array[i],Array[childNodes.first])){
				swap(Array[i],Array[childNodes.first]);
				issmaller_in_heaptree(Array,size,childNodes.first);
			}
			else{
				
				if(!isbigger(Array[i],Array[childNodes.second])){
				   
				swap(Array[i],Array[childNodes.second]);
				issmaller_in_heaptree(Array,size,childNodes.second);
				}
			}
			
		}
		
	}
	
}

void isbigger_in_heaptree(vector<int>& Array, int i){
	
	if(hasParent(i) && isbigger(Array[i], Array[parentIndexof(i)])){
		swap(Array[i],Array[parentIndexof(i)]);
		isbigger_in_heaptree(Array,parentIndexof(i));
	}
	
}

bool hasParent(int i){
	return parentIndexof(i) >= 0;
}

int hasChild(int i, int size){
	pair<int, int> childeNodes = childeIndeof(i);
	
	int childcount = 0;
	
	if(size <= childeNodes.first){
		return childcount;
	}
	else if(size <= childeNodes.second){
		return 1;
	}
	else return 2;
	
}

bool isbigger(int i, int j){
	return i > j;
}

int parentIndexof(int childNode){
	return (childNode-1)/2;
}

pair<int, int> childeIndeof(int parentNode){
	pair<int, int> childeNodes;
	childeNodes.first = parentNode*2 + 1;
	childeNodes.second = parentNode*2 + 2;
	return childeNodes;
}



//radixsort
void radixSort(vector<int>& Array){
	int maxdigit = Foundmax(Array);
	
	for(int i = 1; i <= maxdigit; i++){
		digitSortOf_digit(Array,i);
	}
	
}

void digitSortOf_digit(vector<int>& Array,int _digit){
	
	vector<vector<int>> digitsqueue(11, vector<int>());
	
	for(int i = 0; i < Array.size(); i++){
		//cout <<" Array[" << i << "]=" << Array[i]<< " " << endl;  
		int digitValue = digit(Array[i],_digit);
		
		if(digitValue==-1){
			digitsqueue[10].push_back(Array[i]);
			continue;
			}
		
		digitsqueue[digitValue].push_back(Array[i]);
	}
	int index = 0;
	

	
	for(int i = 0; i < digitsqueue[10].size(); i++){
		Array[index++] = digitsqueue[10][i];
	}
	
	for(int i = 0; i < 10; i++){
		
		for(int j = 0; j < digitsqueue[i].size(); j++){
			Array[index++] = digitsqueue[i][j];
		}
		
	}
	
	
}

int Foundmax(vector<int>& Array){

	int ret = 1;
	for(int i = 0; i < Array.size(); i++){
		ret = max(ret, digitsOf(Array[i])); 
	}
	return ret;
}

int digitsOf(int Value){
	
	int digits = 0;
	int i = 1;
	
	while(digits != -1){
		
		digits = digit(Value, i+1);
		i++;
	
	}
	
	return i-1;
}

int digit(int Value, int dig){
	if(Value == 0 && dig == 1)return 0;
	if(Value/pow(10,dig-1) < 1)return -1;
	
	return (Value%(int)(pow(10,dig)))/pow(10,dig-1);
}


//countingSort
void countingSort(vector<int>& Array){
	
	vector<int> SortedArray(Array.size());
	vector<int> count(10,0);
	
	counting(Array, count);
	SumArray(count);
	
	for(int i = 0; i < Array.size(); i++){
		int location = --count[Array[i]];
		SortedArray[location]=Array[i];
		cout << "location = " << location << " ValueOflocation=" << Array[i] << endl;
	}
	
	printArray(SortedArray);
	
}

void SumArray(vector<int>& Array){
	
	for(int i = 0; i < Array.size()-1; i++){
		
		Array[i+1] = Array[i]+Array[i+1];
		cout << Array[i] << " ";
	}
	cout << Array[Array.size()-1] << endl;
	
}

void counting(vector<int>& Array, vector<int>& Brray){
	
	for(int i = 0; i < Array.size(); i++){
		Brray[Array[i]]++;
	}
	
	
}


void selectionSort(vector<int>& Array){
	
	int size = Array.size();
	for(int i = 0; i < size; i++){
		
		int mini = i;
		int min = Array[mini];
			
		for(int j = i+1; j < size; j++){
			
			if(min > Array[j]){
				min = Array[j];
				mini = j;
			}
			
		}
		
		swap(Array[mini], Array[i]);
		
		
		
	}
	
	
	
}

void swap(int& a,int &b){
	
	int temp = a;
	a = b;
	b = temp;
	
}

void printArray(vector<int>& Array){
	
	for(auto it = Array.begin(); it!= Array.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	
}

void printArray(queue<int> Array){
	
	for(int i = 0; i < Array.size(); i++){
		cout << Array.front() << " ";
		Array.pop();
	}
	cout << endl;
	
}

#endif

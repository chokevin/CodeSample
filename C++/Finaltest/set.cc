#include <iostream>
#include <set>
#include <string>
using namespace std;
void DisplayAllSubsets(set<string> S){
	set<string>::iterator it;
	int size = S.size();
	int currentSubset = 2;
	int tmp;
	while(size-1){
		currentSubset *= 2;
		size--;
	}
	while(currentSubset){
		cout << "{";
		tmp = currentSubset;
		for(it = S.begin(); it != S.end(); it++){
			if(tmp&1) cout << *it  << ' ';
			tmp >>=1;
		}
		cout << "}" << endl;
		currentSubset--;
	}
}

void PrintSubsets() 
{ 
	int source[3] = {1,2,3}; 
	int currentSubset = 8; 
	int tmp; 
	while(currentSubset){ 
		printf("("); 
		tmp = currentSubset; 
		for(int i = 0; i<3; i++) { 
		if (tmp & 1) printf("%d ", source[i]); 
		tmp >>= 1; 
		} 
	printf(")\n"); 
	currentSubset--; 
	} 
}

int main(){
	PrintSubsets();
	set<string> strings;
	strings.insert("Alice");
	strings.insert("Bob");
	strings.insert("Dave");
	strings.insert("James");
	DisplayAllSubsets(strings);
}


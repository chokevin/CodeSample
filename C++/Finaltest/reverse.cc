#include <iostream>
#include <deque>
using namespace std;


int reverse(int x){
	deque<int> queue;
	bool neg = false;
	if(x < 0){
		x *= -1;
		neg = true;
	}
	while(x){
		queue.push_front(x%10);
		x /= 10;
	}
	int size = queue.size();
	for(int i = 0; i < size; i++){
		x += queue.back();
		queue.pop_back();
		x*=10;
	}
	x /= 10;
	if(neg){
		return x*-1;
	}
	return x;
}


int main(){

int x = 23213;
int x2 = 12002;
int x3 = 1200003;
int x4 = -6232000;

cout << x << endl;
x = reverse(x);
cout << x << endl;

cout << x2<< endl;
x2 = reverse(x2);
cout << x2 << endl;

cout << x3 << endl;
x3 = reverse(x3);
cout << x3 << endl;

cout << x4 << endl;
x4 = reverse(x4);
cout << x4 << endl;


}



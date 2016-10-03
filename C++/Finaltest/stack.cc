#include <iostream>
#include "stack.h"
#define defT template <typename T>

template <typename T>
Stack<T>::Stack(int size) : capacity(size), count(0)
{}

template <typename T>
Stack<T>::~Stack(){
	capacity = 0;
	count = 0;
	delete [] elements;
}

template <typename T>
int Stack<T>::push(T& entry){
	if(count == capacity) return 0;
    elements[count] = entry;
	count++;
}
template <typename T>
T Stack<T>::pop(){
	T number = elements[count-1];
	elements[count-1] = 0;
	count --;
	return number;
}
template <typename T>
T Stack<T>::top() const{
	return elements[count-1];
}
template <typename T>
int Stack<T>::isEmpty() const{
	if(count) return 0;
	return 1;
}
template <typename T>
int Stack<T>::isFull() const{
	if(count == capacity) return 1;
	return 0;
}


int main(){
	

}


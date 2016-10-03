#include <iostream>
template <typename T>

class Stack
{
public:
    Stack(int size = 100);
    ~Stack();
    int push(T& entry);
    T pop();
    T top() const;
    int isEmpty() const;
    int isFull() const;
private:
    int capacity;
    int count;
    T* elements;
};



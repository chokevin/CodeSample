#include <iostream>

struct ListNode{
	int value;
	ListNode* next;
};

class IntList{
public:
	IntList();
	IntList(const IntList & other);
	~IntList();
	IntList& operator =( const IntList & other);
private:
	int num;
	ListNode* first;
};

IntList::IntList( const IntList &other){

	ListNode * p1 = 0;
	ListNode * p2 = 0;

	if(other.first == 0) first = 0;
	else{
		first = new ListNode;
		first -> value = other.first -> value;

		p1 = first;
		p2 = other.first -> next;
	}
	while(p2){
		p1->next = new ListNode;
		p1 = p1 -> next;
		p1 -> value = p2 -> value;
		p2 = p2 -> next;
	}
	p1 -> next = 0;

/*
	if(&other != this){
		ListNode* tmp = first;
		while(tmp->next != NULL){
			first = first->next;
			delete tmp;
			tmp = first;
		}
		num = 0;
		while(tmp != NULL){
			this->first = tmp.first;
			this->value = tmp->value;
		}
	}*/
}


IntList::~IntList(){
	num = 0;
	while(first != NULL){
		ListNode* temp = first;
		first = first->next;
		free(temp);
	}
	first = NULL;

}


IntList& IntList::operator=(const IntList &other){
	ListNode* temp = other.first;
	while(temp){
		first = temp;
		first->next = new ListNode;
		first = first->next;
		temp = temp->next;
	}
	return *this;
}


int main(){

	return 0;

}

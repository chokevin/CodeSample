#include <iostream>

struct ListNode
{
    int value;
    ListNode* next;
};

void printNode(ListNode* tmp);

ListNode* RotateRight(ListNode *head, int k){

    ListNode* tmp = head;
    ListNode* tmp2 = head;
    int len = 1;
    if(!head){
        return head;
    }
    while(tmp->next){
        tmp = tmp->next;
        len++;
    }
    tmp->next = head;
    if( k %= len){
        for(int i = 0; i < len-k; i++){
            tmp = tmp->next;
        }
    }
    tmp2 = tmp->next;
    tmp->next=NULL;

    return tmp2;
}

int main(){
    ListNode *linkedlist = new ListNode;
    ListNode *head = linkedlist;
    ListNode *tmp = head;
    ListNode *temp = head;

    linkedlist->value = 1;
    linkedlist->next = new ListNode;
    linkedlist = linkedlist->next;
    linkedlist->value = 2;
    linkedlist->next = new ListNode;
    linkedlist = linkedlist->next;
    linkedlist->value = 3;
    linkedlist->next = new ListNode;
    linkedlist = linkedlist->next;
    linkedlist->value = 4;
    linkedlist->next = new ListNode;
    linkedlist = linkedlist->next;
    linkedlist->value = 5;
    linkedlist->next = new ListNode;
    linkedlist->next = NULL;
    
    for(int i = 0; i< 5; i++){
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << std::endl;
    ListNode* tmp8 = RotateRight(tmp, 0);
    printNode(tmp8);
    ListNode* tmp2 = RotateRight(temp ,1);
    printNode(tmp2);
    ListNode* tmp3 = RotateRight(tmp ,2);
    printNode(tmp3);
    ListNode* tmp4 = RotateRight(tmp ,3);
    printNode(tmp4);
    ListNode* tmp5 = RotateRight(tmp ,4);
    printNode(tmp5);
    ListNode* tmp6 = RotateRight(tmp ,5);
    printNode(tmp6);
}

void printNode(ListNode* tmp){
    for(int i = 0; i < 5; i++){
        std::cout << tmp->value << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}


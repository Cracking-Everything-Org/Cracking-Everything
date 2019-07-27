using namespace std;
#include <iostream> 

typedef int DataType;

struct Node 
{
    Node* next = nullptr;
    DataType data;

    Node(DataType data){
        data=data;
    }
};

Node* partition(Node* node, int x){
    Node* head = node;
    Node* tail = node;
    while(node!=NULL){
        Node* next = node->next;
        if(node->data<x){
            node->next=head;
            head=node;
        }else{
            tail->next=node;
            tail=node;
        }
        node=next;
    }
    tail->next = NULL;
    return head;
}
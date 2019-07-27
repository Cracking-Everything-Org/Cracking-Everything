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

Node* deleteNode(Node* list){
    Node* head = list;
    if(list == nullptr || list->next == nullptr){
        return nullptr;
    }
    if(list->next){
        Node* toDelete = list->next;
        list->data = list->next->data;
        list->next = list->next->next;
        delete toDelete;
        return head;
    }
    delete list;
    return head;
}
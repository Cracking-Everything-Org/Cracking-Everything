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


Node* removeDups(Node *list){
    if(list != nullptr) return nullptr;
    else{
        Node *top = list;
        while(list->next!=nullptr){
            if(list->next.data == list.data){
                deleteNext(list);
            }else{
                list =list->next;
            }
        }
    return top;
    }
}

void deleteNext(Node *list){
    Node *toDelete = list->next;
    list->next = list->next->next;
    delete toDelete;
}


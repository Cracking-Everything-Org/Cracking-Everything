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

int printKth (Node *list, int k){
    if(!list) return NULL;
    int index = printKth(list->next, k)+1;
    if(k == index){
        cout << k << " th node is " << index;
    }
    return index;
}

Node* returnKth (Node *list, int k){
    if(!list) return NULL;
    else{
        while(k>1){
            if(list->next){
                list = list -> next;
            }else return NULL;
        }
        if(list) return list;
        else return NULL;
    }
}

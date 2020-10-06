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
    if(!list) return 0;
    int index = printKth(list->next, k)+1;
    if(k == index){
        cout << k << " th node is " << index;
    }
    return index;
}
//

Node* returnKth (Node *list, int k, int i){
    if(!list) return nullptr;
    Node* nd = returnKth(list->next,k,i);
    i++;
    if(i==k){
        return list;
    }
    return nd;
}

Node* returnKth (Node *list, int k){
    int i = 0;
    returnKth(list,k,i);
}

//
Node* returnKth (Node *list, int k){
    if(!list) return nullptr;
    else{
        while(k>1){
            if(list->next){
                list = list -> next;
            }else return nullptr;
        }
        if(list) return list;
        else return nullptr;
    }
}

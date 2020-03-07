using namespace std;
#include <iostream> 
#include <string>
#include <stack>

typedef int DataType;

struct Node 
{
    Node* next = NULL;
    DataType data;

    Node(DataType data){
        data=data;
        next=NULL;
    }
};

Node* loopDetection(Node* list){
    Node* fast= list;
    Node* slow= list;

    if(!fast || !fast->next){
        return NULL;
    }else{
        slow=slow->next;
        fast=fast->next->next;
        while(fast){
            if(fast==slow){
                slow=list;
            }else{
                slow=slow->next;
                fast=fast->next->next;
            }
        }
        if(!fast) return NULL;
        while(fast != slow){
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
}
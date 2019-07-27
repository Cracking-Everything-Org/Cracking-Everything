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

bool palindrome(Node* word){
    stack<int> stk;
    Node* faster = word;
    Node* slower = word;
    while(faster && faster->next){
        stk.push(slower->data);
        faster = faster->next->next;
        slower = slower->next;
    }
    
    //odd length
    if(faster){
        slower = slower->next;
    }

    while(slower){
        int top = stk.top();
        stk.pop();
        if(top != slower->data){
            return false;
        }
        slower=slower->next;
    }
    return true;
}
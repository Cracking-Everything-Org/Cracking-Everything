using namespace std;
#include <iostream> 
#include <string>

typedef int DataType;

struct Node 
{
    Node* next = nullptr;
    DataType data;

    Node(DataType data){
        data=data;
        next=NULL;
    }
};

Node* sumLists(Node* first, Node* second){
    int count =1;
    int firstN, secondN = 0;
    while(first!=NULL){
        int cup = (first->data) * count;
        count *= 10;
        firstN += cup;
    }
    count = 1;
    while(second!=NULL){
        int cup = (second->data) * count;
        count *= 10;
        secondN += cup;
    }
    int result = firstN + secondN;
    string resString = to_string(result);
    Node *head = NULL;
    Node *tail = head;
    for(int i = resString.length()-1;i>=0;i--){
        Node* newNode = new Node(resString[i]);
        if(head==NULL){
            head = newNode;
            tail = head;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    tail->next = NULL;
    return head;
}

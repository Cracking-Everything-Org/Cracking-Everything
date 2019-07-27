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

Node* intersection (Node* first, Node* second){
    Node* f = first;
    Node* s = second;
    int sizeF = 0;
    int sizeS = 0;

    while(f){
        sizeF++;
        f=f->next;
    }
    while(s){
        sizeS++;
        s=s->next;
    }
    f=first;
    s=second;
    if(sizeF>sizeS){
        int dif= sizeF-sizeS;
        while(dif>0){
            f=f->next;
            dif--;
        }
    }else{
        int dif= sizeS-sizeF;
        while(dif>0){
            s=s->next;
            dif--;
        } 
    }

    while(f){
        if(f==s) return f;
        else{
            f=f->next;
            s=s->next;
        }
    }
    return NULL;
}
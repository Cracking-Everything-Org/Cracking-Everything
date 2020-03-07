using namespace std;
#include <algorithm>
#include <stack>
#include <iostream>

class Tower {
    public: 
    stack<int> stk;
};

void moveDisks(int n, Tower *origin, Tower *destination, Tower *buffer){
    if(n<=0) return;
    moveDisks(n-1, origin, buffer, destination);
    moveTop(origin, destination);
    moveDisks(n-1, buffer, destination, origin);
}

void moveTop(Tower *origin, Tower *destination){
    int top = origin->stk.top();
    origin->stk.pop();
    destination->stk.push(top);
}

//////////// other implementation
class Tower {
    public: 
    stack<int> stk;
     
    public:
    void add(int item){
        if(stk.top() <= item) cout << "error";
        else stk.push(item);
    }

    void moveTopToo(Tower *t){
        int top = stk.top();
        stk.pop();
        t->add(top);
    }

    void moveDiskss(int quantity, Tower *destination, Tower *buffer){
        moveDiskss(quantity-1, this, buffer);
        moveTopToo(destination);
        moveDiskss(quantity-1, buffer, destination);
    }
};
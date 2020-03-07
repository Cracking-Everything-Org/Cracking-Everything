using namespace std;
#include <stack>

void sortStack(stack<int> stk){
    stack<int> stkAux[stk.size()];
    while(!stk.isEmpty()){
        int tmp = stk.top();
        stk.pop();
        while(stkAux.top()>tmp){
            stk.push(stkAux.top());
            stkAux.pop();
        }
        stkAux.push(tmp);
    }

    while(!stkAux.isEmpty()){
        stk.push(stkAux.top());
        stkAux.pop();
    }
}
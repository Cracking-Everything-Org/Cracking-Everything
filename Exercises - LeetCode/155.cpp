class MinStack {

    stack<int> data;
    stack<int> min;

public:

    void push(int x) {
        if(min.empty()){
            data.push(x);
            min.push(x);
        }else {
            data.push(x);
            if(x<=min.top()){
                min.push(x);
            }
        }
    }

    void pop() {
        if(!min.empty()){
            if(data.top()==min.top()){
                min.pop();
            }
            data.pop();
        }
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

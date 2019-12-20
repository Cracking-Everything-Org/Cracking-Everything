class MyQueue {
public:
    stack<int> stack1, stack2;

    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1.push(x);
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int element = peek();
        stack1.pop();
        return element;
    }

    /** Get the front element. */
    int peek() {
        return stack1.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stack1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

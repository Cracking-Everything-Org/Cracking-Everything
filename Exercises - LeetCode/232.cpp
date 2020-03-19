class MyQueue {
public:
    stack<int> pushStack;
    stack<int> popStack;
    int size = 0;

    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        pushStack.push(x);
        size++;
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int topElement;
        if (!popStack.empty()) {
            topElement = popStack.top();
            popStack.pop();
        } else {
            while (!pushStack.empty()) {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
            topElement = popStack.top();
            popStack.pop();
        }
        size--;
        return topElement;
    }

    /** Get the front element. */
    int peek() {
        if (!popStack.empty()) {
            return popStack.top();
        } else {
            while (!pushStack.empty()) {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
            return popStack.top();
        }
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return size == 0;
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

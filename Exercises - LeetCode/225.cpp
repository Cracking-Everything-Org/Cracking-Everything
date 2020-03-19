// debi usar una queue temp y luego transformarla en mi pushQueue

class MyStack {
public:
    queue<int> pushQueue;
    queue<int> popQueue;
    int size = 0;

    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        pushQueue.push(x);
        size++;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int topElement;
        if (pushQueue.size() > 0) {
            int queueSize = pushQueue.size();
            for (int i = 1; i < queueSize ;i++) {
                popQueue.push(pushQueue.front());
                pushQueue.pop();
            }
            topElement = pushQueue.front();
            pushQueue.pop();
        } else {
            int queueSize = popQueue.size();
            for (int i = 1; i < queueSize; i++) {
                pushQueue.push(popQueue.front());
                popQueue.pop();
            }
            topElement = popQueue.front();
            popQueue.pop();
        }
        size--;
        return topElement;
    }

    /** Get the top element. */
    int top() {
        int topElement;
        if (pushQueue.size() > 0) {
            int queueSize = pushQueue.size();
            for (int i = 0; i < queueSize - 1; i++) {
                popQueue.push(pushQueue.front());
                pushQueue.pop();
            }
            topElement = pushQueue.front();
        } else {
            int queueSize = popQueue.size();
            for (int i = 0; i < queueSize - 1; i++) {
                pushQueue.push(popQueue.front());
                popQueue.pop();
            }
            topElement = popQueue.front();
        }
        return topElement;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

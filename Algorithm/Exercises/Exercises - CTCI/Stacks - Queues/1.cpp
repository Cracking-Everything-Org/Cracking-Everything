using namespace std;
#include <iostream> 
#include <string>
#include <vector>

class FixedMultiStack{
    int numberOfStacks = 3;
    int stackCapacity;
    int[] values;
    int[] sizes;

    public FixedMultiStack(int stackSize){
        stackCapacity = stackSize;
        values = new int[stackSize * stackSize];
        sizes = new int[stackSize];
    }

    //push
    void push(int value, int stackNumber){
        if(sizes == stackCapacity) throw new exception();
        values[indexOfTop(stackNumber)] = value;
        sizes[stackNumber]++;
    }

    //pop
    void pop(int stackNumber){
        if(isEmpty(stackNumber)) throw new exception();
        values[indexOfTop(stackNumber)] = 0;
        sizes[stackNumber]--;
    }

    //top
    int top(int stackNumber){
        if(isEmpty(stackNumber)) throw new exception();
        return valueOfTop(stackNumber);
    }

    //empty
    bool isEmpty(int stackNumber){
        return (sizes[stackNumber] == 0);
    }

    //topIndex
    int indexOfTop(int stackNumber){
        int offset = stackNumber * stackCapacity;
        int size = sizes[stackNumber];
        return offset - size;
    }
}
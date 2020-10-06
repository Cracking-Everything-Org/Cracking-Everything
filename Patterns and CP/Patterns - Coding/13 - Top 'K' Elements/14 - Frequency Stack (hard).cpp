Design a class that simulates a Stack data structure, implementing the following two operations:

push(int num): Pushes the number ‘num’ on the stack.
pop(): Returns the most frequent number in the stack. If there is a tie, return the number which was pushed later.
Example:

After following push operations: push(1), push(2), push(3), push(2), push(1), push(2), push(5)

1. pop() should return 2, as it is the most frequent number
2. Next pop() should return 1
3. Next pop() should return 2


struct frequencyCompare {
  bool operator()(const Element &e1, const Element &e2) {
    if (e1.frequency != e2.frequency) {
      return e2.frequency > e1.frequency;
    }
    // if both elements have same frequency, return the one that was pushed later
    return e2.sequenceNumber > e1.sequenceNumber;
  }
};

int sequenceNumber = 0;
priority_queue<Element, vector<Element>, frequencyCompare> maxHeap;
unordered_map<int, int> frequencyMap;

virtual void push(int num) {
  frequencyMap[num] += 1;
  maxHeap.push({num, frequencyMap[num], sequenceNumber++});
}

virtual int pop() {
  int num = maxHeap.top().number;
  maxHeap.pop();

  // decrement the frequency or remove if this is the last number
  if (frequencyMap[num] > 1) {
    frequencyMap[num] -= 1;
  } else {
    frequencyMap.erase(num);
  }

  return num;
}


Time complexity #
The time complexity of push() and pop() is O(logN) where ‘N’ is the current number of elements in the heap.

Space complexity #
We will need O(N) space for the heap and the map, so the overall space complexity of the algorithm is O(N).

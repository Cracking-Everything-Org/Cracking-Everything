class ConnectRopes {
 public:
  static int minimumCostToConnectRopes(const vector<int> &ropeLengths) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // add all ropes to the min heap
    for (int i = 0; i < ropeLengths.size(); i++) {
      minHeap.push(ropeLengths[i]);
    }

    // go through the values of the heap, in each step take top (lowest) rope lengths from the min
    // heap connect them and push the result back to the min heap. keep doing this until the heap is
    // left with only one rope
    int result = 0, temp = 0;
    while (minHeap.size() > 1) {
      temp = minHeap.top();
      minHeap.pop();
      temp += minHeap.top();
      minHeap.pop();
      result += temp;
      minHeap.push(temp);
    }

    return result;
  }
};
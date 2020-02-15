Design a class to efficiently find the Kth largest element in a stream of numbers.

The class should have the following two things:

The constructor of the class should accept an integer array containing initial numbers from the stream and an integer ‘K’.
The class should expose a function add(int num) which will store the given number and return the Kth largest number.
Example 1:

Input: [3, 1, 5, 12, 2, 11], K = 4
1. Calling add(6) should return '5'.
2. Calling add(13) should return '6'.
2. Calling add(4) should still return '6'.

class KthLargestNumberInStream {
 public:
  struct numCompare {
    bool operator()(const int &x, const int &y) { return x > y; }
  };

  priority_queue<int, vector<int>, numCompare> minHeap;
  const int k;

  KthLargestNumberInStream(const vector<int> &nums, int k) : k(k) {
    // add the numbers in the min heap
    for (int i = 0; i < nums.size(); i++) {
      add(nums[i]);
    }
  }

  virtual int add(int num) {
    // add the new number in the min heap
    minHeap.push(num);

    // if heap has more than 'k' numbers, remove one number
    if ((int)minHeap.size() > this->k) {
      minHeap.pop();
    }

    // return the 'Kth largest number
    return minHeap.top();
  }
};

Time complexity #
The time complexity of the add() function will be O(logK) since we are inserting the new number in the heap.

Space complexity #
The space complexity will be O(K) for storing numbers in the heap.

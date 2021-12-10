using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KLargestNumbers {
 public:
  static vector<int> findKLargestNumbers(const vector<int>& nums, int k) {
    vector<int> kNumbers;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < nums.size(); i++) {
      minHeap.push(nums[i]);
      if (minHeap.size() > k) {
        minHeap.pop();
      }
    }

    while (!minHeap.empty()) {
      kNumbers.push_back(minHeap.top());
      minHeap.pop();
    }

    return kNumbers;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result = KLargestNumbers::findKLargestNumbers(vector<int>{3, 1, 5, 12, 2, 11}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = KLargestNumbers::findKLargestNumbers(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}


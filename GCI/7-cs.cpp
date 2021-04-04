using namespace std;

#include <iostream>
#include <vector>

class FirstMissingPositive {
 public:
  static int findNumber(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] != nums[nums[i] - 1] && nums[i] > 0 && nums[i] < nums.size()){
        swap(nums[i], nums[nums[i] - 1]);
      } else {
        i++;
      }
    }

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) return i + 1;
    }
    return -1;
  }
};

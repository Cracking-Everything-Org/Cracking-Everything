using namespace std;

#include <iostream>
#include <vector>

class FindDuplicate {
 public:
  static int findNumber(vector<int> &nums) {  
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] != i + 1) {
        if (nums[i] != nums[nums[i] - 1]) {
          swap(nums[i], nums[nums[i] - 1]);
        } else {
          return nums[i];
        }
        i++;
      } else {
        i++;
      }
    }
    return -1;
  }
};

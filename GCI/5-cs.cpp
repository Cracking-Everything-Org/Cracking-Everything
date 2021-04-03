using namespace std;

#include <iostream>
#include <vector>

class FindAllDuplicate {
 public:
  static vector<int> findNumbers(vector<int> &nums) {
    vector<int> duplicates;

    int i = 0;
    while (i < nums.size()) {
      if (nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
      } else {
        i++;
      } 
    }

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        duplicates.push_back(nums[i]);
      }
    }

    return duplicates;
  }
};

We are given an unsorted array containing numbers taken from the range 1 to ‘n’. The array can have duplicates, which means some numbers will be missing. Find all those missing numbers.

Input: [2, 3, 1, 8, 2, 3, 5, 1]
Output: 4, 6, 7
Explanation: The array should have all numbers from 1 to 8, due to duplicates 4, 6, and 7 are missing.

Input: [2, 4, 1, 2]
Output: 3

Input: [2, 3, 2, 1]
Output: 4

vector<int> findNumbers(vector<int> &nums) {
  int i = 0;
  while (i < nums.size()) {
    if (nums[i] != nums[nums[i] - 1]) {
      swap(nums, i, nums[i] - 1);
    } else {
      i++;
    }
  }

  vector<int> missingNumbers;
  for (i = 0; i < nums.size(); i++) {
    if (nums[i] != i + 1) {
      missingNumbers.push_back(i + 1);
    }
  }

  return missingNumbers;
}

Time complexity #
The time complexity of the above algorithm is O(n).

Space complexity #
Ignoring the space required for the output array, the algorithm runs in constant space O(1).

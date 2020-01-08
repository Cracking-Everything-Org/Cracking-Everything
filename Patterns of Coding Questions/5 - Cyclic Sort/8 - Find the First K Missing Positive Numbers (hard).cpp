Given an unsorted array containing numbers and a number ‘k’, find the first ‘k’ missing positive numbers in the array.

Input: [3, -1, 4, 5, 5], k=3
Output: [1, 2, 6]
Explanation: The smallest missing positive numbers are 1, 2 and 6.

Input: [2, 3, 4], k=3
Output: [1, 5, 6]
Explanation: The smallest missing positive numbers are 1, 5 and 6.

Input: [-2, -3, 4], k=2
Output: [1, 2]
Explanation: The smallest missing positive numbers are 1 and 2.

vector<int> findNumbers(vector<int> &nums, int k) {
  int i = 0;
  while (i < nums.size()) {
    if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
      swap(nums, i, nums[i] - 1);
    } else {
      i++;
    }
  }

  vector<int> missingNumbers;
  unordered_set<int> extraNumbers;
  for (i = 0; i < nums.size() && missingNumbers.size() < k; i++) {
    if (nums[i] != i + 1) {
      missingNumbers.push_back(i + 1);
      extraNumbers.insert(nums[i]);
    }
  }

  // add the remaining missing numbers
  for (i = 1; missingNumbers.size() < k; i++) {
    int candidateNumber = i + nums.size();
    // ignore if the array contains the candidate number
    if (extraNumbers.find(candidateNumber) == extraNumbers.end()) {
      missingNumbers.push_back(candidateNumber);
    }
  }

  return missingNumbers;
}

Time complexity #
The time complexity of the above algorithm is O(n + k), as the last two for loops will run for O(n) and O(k) times respectively.

Space complexity #
The algorithm needs O(k) space to store the extraNumbers.
